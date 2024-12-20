#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include "applicationState_t.h"

void SDL_AppQuit( void* _applicationState, SDL_AppResult _appRunResult ) {
    applicationState_t* l_applicationState =
        ( applicationState_t* )_applicationState;

    SDL_DestroyRenderer( l_applicationState->renderer );
    SDL_DestroyWindow( l_applicationState->window );

    SDL_free( _applicationState );
}
