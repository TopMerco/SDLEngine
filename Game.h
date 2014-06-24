#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "TextureManager.h"
class Game{
	private:
	bool running;
	SDL_Window* finestra;
	SDL_Renderer* render;
	int frameagg;
	TextureManager TM;
	
public:
	Game();
	~Game();
	bool init(const char* titolo,int posx,int posy,int larghezza,int altezza,int flags );
	void renderizza();
	void aggiorna();
	void eventi();
	void clean();
	bool isRunning(){return running;}
};
#endif