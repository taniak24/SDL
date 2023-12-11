#include <SDL2/SDL.h>
#include <iostream>

///BEFORE EVERY PROJECT YOU NEED TO DO THE INSTALLATION STEPS

using namespace std;

const int WIDTH = 500;
const int HEIGHT = 400;

int main(int args, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("SDL WORLD", 500, 500, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    //check in console if it's correctly installed
    if(NULL == window)
    {
        cout << "could not create a window";
    }
    else
    {
        cout << "SDL is installed";
    }

    SDL_Event windowEvent;

    while(true)
    {
        if(SDL_PollEvent(&windowEvent))
        {
            if(SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
    }
}

