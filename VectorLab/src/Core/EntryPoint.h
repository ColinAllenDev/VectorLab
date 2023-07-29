#pragma once

extern VL::Application* VL::CreateApplication();

int main(int arc, char** argv) 
{
    VL::Log::Init();
    VL_INFO("Hello Engine!");    

    auto app = VL::CreateApplication();
    app->Run();
    delete app;
}