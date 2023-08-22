#include "Renderer.h"

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <Core/Base.h>
#include <Core/Application.h>
#include <Core/Window.h>
#include <Core/Log.h>

static SDL_GLContext sdl_context;

namespace VL 
{
    Renderer* Renderer::s_instance = nullptr;
    Renderer* Renderer::GetInstance() { return s_instance; }
    Renderer* Renderer::Create() { return new Renderer(); }

    Renderer::Renderer() 
    {
        VL_ASSERT(!s_instance, "Renderer already exists!")
        s_instance = this;
    }

    void Renderer::Init() 
    {
        // Get application window
        Application* app = Application::GetInstance();
        Window::WindowProps* window_props = app->GetWindow()->GetProps();
        sdl_window = app->GetWindow()->GetSDL();

        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) == 0) 
        {
            // Load OpenGL
            SDL_GL_LoadLibrary(NULL);

            // TODO: Set attributes from config
            SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

            // Use Vsync
            SDL_GL_SetSwapInterval(1);

            // Create OpenGL Context
            sdl_context = SDL_GL_CreateContext(sdl_window);
            VL_ASSERT(sdl_context, "SDL Error: {}", SDL_GetError());
        }

        // Initialize GLAD
        if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
        {
            VL_INFO("OpenGL ({}) Loaded! [Vendor: {} Renderer: {}]",
                *glGetString(GL_VERSION), *glGetString(GL_VENDOR), *glGetString(GL_RENDERER));
        } else {
                VL_ERROR("gladLoadGLLoader Error!");
        }

        // Set OpenGL viewport size
        glViewport(window_props->x, window_props->y, window_props->width, window_props->height);
        // Enable depth buffer
        glEnable(GL_DEPTH_TEST);
    }

    void Renderer::Update()
    {
        while (m_running) 
        {
            // Clear
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Swap Buffers
            SDL_GL_SwapWindow(sdl_window);
        }
    }

    void Renderer::Shutdown()
    {
    }

}