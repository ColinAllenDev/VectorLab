#pragma once

#include "Base.h"
#include "Window.h"

namespace VL
{
    class Application 
    {
    public:
        Application();
        
        /** Main Engine Loop */
		void Run();

        inline Window& GetWindow() { return *m_Window; }
    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
    private:
        static Application* s_Instance;
    };

    // Defined by client application
    Application* CreateApplication();
}