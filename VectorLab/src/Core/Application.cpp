#include "../PCH.h"
#include "Application.h"

namespace VL 
{
    Application* Application::s_Instance = nullptr;

    Application::Application() 
    {
        // VL_ASSERT(!s_Instance, "Application already exists!")
        s_Instance = this;

        // Create window
        m_Window = std::unique_ptr<Window>(Window::Create("Sandbox", 640, 480));
    }

    void Application::Run() 
    {
        while (m_Running) {}
    }

}