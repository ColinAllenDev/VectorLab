#include <VectorLab.h>

class Sandbox : public VL::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

VL::Application* VL::CreateApplication() {
	return new Sandbox();
}