#include "../PCH.h"
#include "Application.h"

#include <SDL2/SDL.h>

namespace VL 
{
    Application* Application::s_instance = nullptr;    

    Application::Application() 
    {
        VL_ASSERT(!s_instance, "Application already exists!")
        s_instance = this;

        // Create window
        m_window = std::unique_ptr<Window>(Window::Create());
    }

    void Application::Run() 
    {
        while(m_running) 
        {
            m_window->Update();
        }
    }

    void Application::Shutdown() {
        VL_ASSERT(s_instance, "Application does not exist!")
        s_instance = nullptr;
        m_running = false;
    }

}