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
        Window(char* p_title, uint p_width, uint p_height, uint p_x = (0x1FFF0000u|(0)), uint p_y = (0x1FFF0000u|(0)));
        ~Window();
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
        static Window* Create(char* p_title, uint p_width, uint p_height, uint p_x = (0x1FFF0000u|(0)), uint p_y = (0x1FFF0000u|(0)));
    };  
}