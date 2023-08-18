#include "Window.h"
#include "Log.h"
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

static SDL_GLContext m_sdl_context;

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
            // Load OpenGL
            SDL_GL_LoadLibrary(NULL);
            SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            
            m_sdl_window = SDL_CreateWindow(m_window_title, m_window_x, m_window_y, m_window_width, m_window_height, SDL_WINDOW_OPENGL);
            m_sdl_context = SDL_GL_CreateContext(m_sdl_window);

            VL_ASSERT(m_sdl_context, "SDL_GL_CreateContext error: {}", SDL_GetError());

            // Initialize GLAD
            if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
            {
                VL_INFO("OpenGL ({}) Loaded! [Vendor: {} Renderer: {}]",
                        *glGetString(GL_VERSION), *glGetString(GL_VENDOR), *glGetString(GL_RENDERER));
            } else {
                VL_ERROR("gladLoadGLLoader Error!");
            }
            // Use Vsync
            SDL_GL_SetSwapInterval(1);
            // Set glViewport size
            glViewport(m_window_x, m_window_y, m_window_width, m_window_height);
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
            /* Render Loop */
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Swap Buffers
            SDL_GL_SwapWindow(m_sdl_window);

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