#include <Voyager.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}

	~Sandbox()
	{

	}
};

Voyager::Application* Voyager::CreateApplication()
{
	return new Sandbox();
}