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

        void Shutdown();

        inline Window& GetWindow() { return *m_window; }
    private:
        bool m_running = true;
        std::unique_ptr<Window> m_window;
    private:
        static Application* s_instance;
    };

    // Defined by client application
    Application* CreateApplication();
}