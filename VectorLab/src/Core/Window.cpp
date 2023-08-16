#include "Window.h"

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

namespace VL 
{
    Window::Window(const WindowProps& props) 
    {
        // == Assign member values == //
        m_window_width = props.width;
        m_window_height = props.height;
        m_window_x = props.x;
        m_window_y = props.y;
        m_window_title = props.title;


        // == Initialize API: SDL == //
        if (SDL_Init(SDL_INIT_VIDEO) == 0) 
        {
            m_sdl_window = SDL_CreateWindow(m_window_title, m_window_x, m_window_y, m_window_width, m_window_height, SDL_WINDOW_SHOWN);
        } else {
            // Log error using SDL_GetError()
        }

        // == Initialize API: BGFW == //
        // Get system info from SDL
        SDL_SysWMinfo wmi;
        SDL_VERSION(&wmi.version);
        VL_ASSERT(!SDL_GetWindowWMInfo(m_sdl_window, &wmi), "SDL Error: Cannot find WM!")

        // Supply pointer to window to bgfx platform data object
        bgfx::PlatformData pd;
        pd.ndt = wmi.info.x11.display;
        pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
        
        // Tell bgfx about the platform data
        bgfx::setPlatformData(pd);

        // Initialize BGFX
        bgfx::Init bgfx_init;
        bgfx_init.type = bgfx::RendererType::Count; // Automatically choose a renderer
        bgfx_init.resolution.width = m_window_width;
        bgfx_init.resolution.height = m_window_height;
        bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
        bgfx::init(bgfx_init);
    }

    Window::~Window() 
    {
        if (m_sdl_window != NULL) 
        {
            SDL_DestroyWindow(m_sdl_window);
        }

        bgfx::shutdown();
        SDL_Quit();
    }

    void Window::Init() 
    {
    }

    void Window::Update() 
    {
        VL_ASSERT(m_sdl_window, "SDL Window does not exist!")

        m_sdl_surface = SDL_GetWindowSurface(m_sdl_window);
        SDL_FillRect(m_sdl_surface, NULL, SDL_MapRGB(m_sdl_surface->format, 18, 18, 18));        
        SDL_UpdateWindowSurface(m_sdl_window);
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new Window(props);
    }
}