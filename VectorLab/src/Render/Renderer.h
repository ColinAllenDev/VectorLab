
class SDL_Window;
namespace VL 
{
    class Window;
    class Renderer 
    {   
    public:
        static Renderer* GetInstance();
        static Renderer* Create();
        // Initialize render API
        void Init();
        // Main loop used by the renderer.
        void Update();
        // Shutdown routine
        void Shutdown();
    protected:
        Renderer();
        static Renderer* s_instance;
    private:
        SDL_Window* sdl_window;
        bool m_running = true;
    };
}