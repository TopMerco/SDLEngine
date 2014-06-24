#include <SDL.h>
#include <SDL_Image.h>
#include "TextureManager.h"

TextureManager::TextureManager(){
}

TextureManager::~TextureManager(){
}

bool TextureManager::load(std::string nomeFile, std::string id, SDL_Renderer* render){
	SDL_Surface* surf = IMG_Load(nomeFile.c_str());//prende il nome file e lo trasforma in vettore di char da stringa
	if (surf==0)
		return false;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surf);
	SDL_FreeSurface(surf);
	if (texture != 0)
	{
		mappaTexture[id] = texture;
		return true;
	}
	return false;//se sono arrivato qua significa che qualquadra non cosa
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* render, SDL_RendererFlip flip){
	SDL_Rect rettSorg;
	SDL_Rect rettDest;

	rettSorg.x = 0;
	rettSorg.y = 0;
	rettSorg.w = rettDest.w = width;
	rettSorg.h = rettDest.h = height;
	rettDest.x = x;
	rettDest.y = y;
	SDL_RenderCopyEx(render, mappaTexture[id], &rettSorg, &rettDest, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int riga, int frame, SDL_Renderer* render, SDL_RendererFlip flip)
{
	SDL_Rect rettSorg;
	SDL_Rect rettDest;
	rettSorg.x = width*frame;
	rettSorg.y = height*(riga - 1);
	rettSorg.w = rettDest.w = width;
	rettSorg.h = rettDest.h = height;
	rettDest.x = x;
	rettDest.y = y;
	SDL_RenderCopyEx(render, mappaTexture[id], &rettSorg, &rettDest, 0, 0, flip);
}