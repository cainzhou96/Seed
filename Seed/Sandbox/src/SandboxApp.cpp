#include <Seed.h>

class Sandbox : public Seed::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Seed::Application* Seed::createApplication() {
	return new Sandbox(); 
}
