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
		if (Voyager::Input::IsKeyPressed(VGR_KEY_TAB))
			VGR_TRACE("Tab key is pressed! (poll)");
	}

	void OnEvent(Voyager::Event& event) override
	{
		if (event.GetEventType() == Voyager::EventType::KeyPressed)
		{
			Voyager::KeyPressedEvent& e = (Voyager::KeyPressedEvent&)event;
			if (e.GetKeyCode() == VGR_KEY_TAB)
				VGR_TRACE("Tab key is pressed! (event)");
			VGR_TRACE("{0}", (char)e.GetKeyCode());
		}
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