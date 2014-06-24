#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;
Game::Game(){
}

Game::~Game(){
}

bool Game::init(const char* titolo,int posx,int posy,int larghezza,int altezza,int flag){
	if(SDL_Init(SDL_INIT_VIDEO)>=0){
		finestra=SDL_CreateWindow(titolo,posx,posy,larghezza,altezza,flag);//crea finestra
		if(finestra!=0){
		render=SDL_CreateRenderer(finestra,-1,0);//crea render per la finestra
		if(render!=0){
		SDL_SetRenderDrawColor(render,0,0,0,255);//imposta il colore del render
		TM.load("bird.png", "uccello", render);
		running=true;
		}
		else
			cout<<"niente render";//mancata creazione del render
		}
		else
			cout<<"niente finestra";//mancata creazione della finestra
		return true;
	}
	else
		cout<<"manco riesco a inizializzare qua";//accettare sconfitta:non si riesce neanche ad inizializzare SDL
}

void Game::renderizza(){
	SDL_RenderClear(render);//ricolora usando il colore impostato
	TM.drawFrame("uccello", 0, 0, 180, 166,1,frameagg,render);
	TM.drawFrame("uccello", 100, 100, 180, 166, 1, frameagg, render);
	SDL_RenderPresent(render);// stampa il render 
}

void Game::aggiorna(){	
	frameagg = int((SDL_GetTicks() / 100) % 5);
}

void Game::eventi(){
}

void Game::clean(){
	SDL_DestroyWindow(finestra);//cancella tutto CHIUDETE I CANCELLI
	SDL_DestroyRenderer(render);//ANCHE QUEI CANCELLI LI INFONDO
	SDL_Quit();//RINCHIUDETE IL KRAKEN
}

