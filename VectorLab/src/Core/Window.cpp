#include "Window.h"
#include "Log.h"
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

namespace VL 
{
    Window::Window(const WindowProps& props) 
    {
        // == Assign member values == //
        m_props = props;
        m_props.width = props.width;
        m_props.height = props.height;
        m_props.x = props.x;
        m_props.y = props.y;
        m_props.title = props.title;

        // == Initialize API: SDL == //
        if (SDL_Init(SDL_INIT_VIDEO) == 0) 
        {   
            m_sdl_window = SDL_CreateWindow(m_props.title, m_props.x, m_props.y, m_props.width, m_props.height, SDL_WINDOW_OPENGL);
            VL_ASSERT(m_sdl_window, "SDL Error: {}", SDL_GetError());
        } else {
            VL_ERROR("SDL Init Error: {}", SDL_GetError());
        }
    }

    Window::~Window() 
    {
        if (m_sdl_window != NULL) 
        {
            SDL_DestroyWindow(m_sdl_window);
        }

        SDL_Quit();
    }

    void Window::Update() 
    {
        VL_ASSERT(m_sdl_window, "Window does not exist!")     

        SDL_Event current_event;
        while (m_running) 
        {
            /* Event Loop */
            while(SDL_PollEvent(&current_event)) 
            {
                if (current_event.type == SDL_QUIT) m_running = false;
            }
        }
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new Window(props);
    }
}