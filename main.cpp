#include "SDL.h"
#include "Game.h"
using namespace std;
Game gioco;
int main(int argc,char* argv[])
{
	gioco.init("Finestra",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
	while(gioco.isRunning()){
	gioco.renderizza();
	gioco.aggiorna();
	}
	gioco.clean();
	return 0;
}