#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include "applicationState_t.h"

SDL_AppResult SDL_AppInit( void** _applicationState,
                           int _arcgumentCount,
                           char** _argumentVector ) {
    SDL_AppResult l_returnValue = SDL_APP_CONTINUE;

    SDL_SetAppMetadata( "fgengine", "0.1", "com.github.fgengine" );

    SDL_Init( SDL_INIT_VIDEO );

    applicationState_t l_applicationState;

    SDL_CreateWindowAndRenderer( "fgengine", 640, 480, 0,
                                 &( l_applicationState.window ),
                                 &( l_applicationState.renderer ) );

    *_applicationState = SDL_malloc( sizeof( applicationState_t ) );

    SDL_memcpy( *_applicationState, &l_applicationState,
                sizeof( applicationState_t ) );

    return ( l_returnValue );
}
