#include "SDL/SDL.h" // Required by SDL

// To use OpenGL, uncomment the following line:
//#include "SDL/SDL_opengl.h"

int main(int argc, char *argv[]) {
    // The following code is just to test that SDL is working.
    // It will open a window, pause for 2 seconds, and then exit.
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    hello = SDL_LoadBMP("/Users/jmausti3/Developer/c_cpp/testApp2/testApp2/hello.bmp");

    SDL_BlitSurface(hello, NULL, screen, NULL);

    SDL_Flip(screen);
    SDL_Delay(2000);

    SDL_Quit();
    return 0;
}