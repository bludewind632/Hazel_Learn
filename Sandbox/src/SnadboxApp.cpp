#include "Hazel.h"

class Sandbox : public Hazel::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
	void Run() {

	}
};

Hazel::Application* CreateApplication() {
	return new Sandbox();
}

int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
	return 0;
}