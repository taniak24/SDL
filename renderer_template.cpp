#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int WIDTH = 900;
const int HEIGHT = 1500;

int main(int args, char *argv[])
{
    //for the image
    SDL_Surface *imageSurface = NULL;
    SDL_Surface *windowSurface = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("First SDL", 10, 10, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    windowSurface = SDL_GetWindowSurface(window);

    //check
    if(NULL == window)
    {
        cout << "could not create a window";
    }
    else
    {
        cout << "SDL is installed";
    }

    //create the renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    //set the background color
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer); //the function clears the entire rendering target
    SDL_RenderPresent(renderer); //presents the color

    SDL_Delay(3000); //Sleep
    //set the new color
    SDL_SetRenderDrawColor(renderer, 255, 0, 225, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    //image
    imageSurface = SDL_LoadBMP("images/birds.bmp");

    if(imageSurface == NULL)
    {
        cout << "not loaded image";
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
         SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
         SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(windowSurface);

    imageSurface = NULL;
    windowSurface = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();
}
