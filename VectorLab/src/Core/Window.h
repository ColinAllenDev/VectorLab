#pragma once

#include "Base.h"
#include "Types.h"

struct SDL_Window;
struct SDL_Surface;

namespace VL
{
    class Window 
    {
    public:
        struct WindowProps {
            char* title;
            uint width;
            uint height;
            uint x;
            uint y;
            WindowProps(char* p_title = (char*)"VectorLab",
                        uint p_width = 640, uint p_height = 480,
                        uint p_x = 0,
                        uint p_y = 0) 
            : title(p_title), width(p_width), height(p_height), x(p_x), y(p_y) {}
        };

        static Window* Create(const WindowProps& props = WindowProps());

        Window(const WindowProps& props);
        ~Window();

    public:
        void Update();

        inline WindowProps* GetProps() { return &m_props; }
        inline SDL_Window* GetSDL() { return m_sdl_window; }
    private:
        WindowProps m_props;

        SDL_Window* m_sdl_window;
        SDL_Surface* m_sdl_surface;

        bool m_running = true;
    };  
}