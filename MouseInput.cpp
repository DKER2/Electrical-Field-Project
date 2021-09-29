#include "MouseInput.h"
#include<SDL.h>
bool MouseInput::DoubleClickDetected(int* xposOfMouse, int* yposOfMouse, SDL_Event event)
{
    if (int(event.button.clicks) == 2) {
        SDL_GetMouseState(xposOfMouse, yposOfMouse);
        return true;
    }
    return false;
    
}