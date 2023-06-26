#include <Voyager.h>

class Sandbox : public Voyager::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Voyager::Application* Voyager::CreateApplication()
{
	return new Sandbox();
}