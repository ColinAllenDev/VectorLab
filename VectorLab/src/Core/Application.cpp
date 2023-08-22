#include "Application.h"

#include <PCH.h>
#include <Core/Window.h>
#include <Render/Renderer.h>

namespace VL 
{
    Application* Application::s_instance = nullptr;    
    Application* Application::GetInstance() { return s_instance; }

    Application::Application() 
    {
        VL_ASSERT(!s_instance, "Application already exists!")
        s_instance = this;

        // Create window
        m_window = Window::Create();
        m_renderer = Renderer::Create();
    }

    void Application::Run() 
    {
        m_window->Update();
    }


}