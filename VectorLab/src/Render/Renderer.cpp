#include "Renderer.h"
#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <Core/Base.h>
#include <Core/Window.h>
#include <Core/Log.h>

namespace VL 
{
    void Renderer::Init() 
    {
        // Initialize GLAD
        if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
        {
            VL_INFO("OpenGL ({}) Loaded! [Vendor: {} Renderer: {}]",
                *glGetString(GL_VERSION), *glGetString(GL_VENDOR), *glGetString(GL_RENDERER));
        } else {
                VL_ERROR("gladLoadGLLoader Error!");
        }
    }

    void Renderer::Update()
    {
    }

    void Renderer::Shutdown()
    {
    }

}