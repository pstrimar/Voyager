#include <Voyager.h>

class ExampleLayer : public Voyager::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		VGR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Voyager::Event& event) override
	{
		VGR_TRACE("{0}", event);
	}
};

class Sandbox : public Voyager::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Voyager::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Voyager::Application* Voyager::CreateApplication()
{
	return new Sandbox();
}