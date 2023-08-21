
namespace VL 
{
    class Renderer 
    {
        // Forward declarations
        class Window;
    public:
        // Initialize render API
        void Init();
        // Main loop used by the renderer.
        void Update();
        // 

    private:
        // The window we're rendering to
        Window* m_window;
    };
}