#include "../PCH.h"
#include "Application.h"

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
        m_window->Update();
    }
}