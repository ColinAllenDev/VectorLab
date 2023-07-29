#include "Window.h"

#include <SDL2/SDL.h>

namespace VL 
{
    Window::Window(const WindowProps& props) 
    {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) == 0) 
        {
            m_sdl_window = SDL_CreateWindow(props.title, props.x, props.y, props.width, props.height, SDL_WINDOW_SHOWN);

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
        m_window_width = props.width;
        m_window_height = props.height;
        m_window_x = props.x;
        m_window_y = props.y;
        m_window_title = props.title;
    }

    Window::~Window() 
    {
        if (m_sdl_window != NULL) 
        {
            SDL_DestroyWindow(m_sdl_window);
        }

        SDL_Quit();
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new Window(props);
    }
}