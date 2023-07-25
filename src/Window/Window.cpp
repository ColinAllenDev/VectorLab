#include "Window.h"

#include <SDL2/SDL.h>

using namespace VL::Display;

Window::Window(char* p_title, uint p_width, uint p_height, uint p_x, uint p_y) 
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        m_sdl_window = SDL_CreateWindow(p_title, p_x, p_y, p_width, p_height, SDL_WINDOW_SHOWN);

        if (m_sdl_window != NULL) 
        {
            m_sdl_surface = SDL_GetWindowSurface(m_sdl_window);
    
            SDL_FillRect(m_sdl_surface, NULL, SDL_MapRGB(m_sdl_surface->format, 18, 18, 18));
            
            SDL_UpdateWindowSurface(m_sdl_window);
        } else {
            // Log error using SDL_GetError()
        }
    } else {
        // Log error using SDL_GetError()
    }

    // Assign member values
    m_window_width = p_width;
    m_window_height = p_height;
    m_window_x = p_x;
    m_window_y = p_y;
    m_window_title = p_title;
}

Window::~Window() 
{
    if (m_sdl_window != NULL) 
    {
        SDL_DestroyWindow(m_sdl_window);
    }

    SDL_Quit();
}