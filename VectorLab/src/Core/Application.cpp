#include "../PCH.h"
#include "Application.h"

#include <SDL2/SDL.h>

namespace VL 
{
    Application* Application::s_Instance = nullptr;    

    Application::Application() 
    {
        VL_ASSERT(!s_Instance, "Application already exists!")
        s_Instance = this;

        // Create window
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    void Application::Run() 
    {
        SDL_Event event;
        while (m_Running) 
        {
            while (SDL_PollEvent(&event) != 0) 
            {
                switch(event.type) 
                {
                    case SDL_QUIT : 
                        m_Running = false; 
                    break;
                }
            }   
        }
    }

}