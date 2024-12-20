#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_render.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} applicationState_t;

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

SDL_AppResult SDL_AppIterate( void* _applicationState ) {
    SDL_AppResult l_returnValue = SDL_APP_CONTINUE;

    applicationState_t* l_applicationState =
        ( applicationState_t* )_applicationState;

    SDL_RenderClear( l_applicationState->renderer );

    SDL_RenderPresent( l_applicationState->renderer );

    return ( l_returnValue );
}

SDL_AppResult SDL_AppEvent( void* _applicationState, SDL_Event* _event ) {
    SDL_AppResult l_returnValue = SDL_APP_CONTINUE;

    applicationState_t* l_applicationState =
        ( applicationState_t* )_applicationState;

    if ( _event->type == SDL_EVENT_QUIT ) {
        l_returnValue = SDL_APP_SUCCESS;
    }

    return ( l_returnValue );
}

void SDL_AppQuit( void* _applicationState, SDL_AppResult _appRunResult ) {
    applicationState_t* l_applicationState =
        ( applicationState_t* )_applicationState;

    SDL_DestroyRenderer( l_applicationState->renderer );
    SDL_DestroyWindow( l_applicationState->window );

    SDL_free( _applicationState );
}
