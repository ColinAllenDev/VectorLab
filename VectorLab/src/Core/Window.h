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
                        uint p_x = (0x1FFF0000u|(0)),
                        uint p_y = (0x1FFF0000u|(0))) 
            : title(p_title), width(p_width), height(p_height), x(p_x), y(p_y) {}
        };
    public:
        Window(const WindowProps& props);
        ~Window();

        void Update();
        void Init();
    private:
        uint m_id;
        uint m_window_width;
        uint m_window_height; 
        uint m_window_x;
        uint m_window_y;
        char* m_window_title;
        
        SDL_Window* m_sdl_window;
        SDL_Surface* m_sdl_surface;
    public:
        static Window* Create(const WindowProps& props = WindowProps());
    };  
}