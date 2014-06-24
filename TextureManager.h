#ifndef __TextureManager__
#define __TextureManager__
#include <map>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
class TextureManager{
private:
	map <string , SDL_Texture*> mappaTexture;
public:
	TextureManager();
	~TextureManager();
	bool load(string nomefile, string id, SDL_Renderer* render);
	void draw(string id, int x, int y, int w, int h, SDL_Renderer* render, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string id, int x, int y, int width, int height, int riga, int frame, SDL_Renderer* render, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
#endif