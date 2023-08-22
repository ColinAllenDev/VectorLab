#pragma once

#include <Core/Base.h>

namespace VL
{
    class Window;
    class Renderer;
    class Application 
    {
    public:
        static Application* GetInstance();
        inline Window* GetWindow() { return m_window; }
        inline Renderer* GetRenderer() { return m_renderer; }

        void Run();
    protected:
        Application();
        static Application* s_instance;
    private:
        Window* m_window;
        Renderer* m_renderer;
        
        bool m_running = true;
    };

    // Defined by client application
    Application* CreateApplication();
}