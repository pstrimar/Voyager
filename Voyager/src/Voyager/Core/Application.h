#pragma once

#include "Core.h"

#include "Window.h"
#include "Voyager/Core/LayerStack.h"
#include "Voyager/Events/ApplicationEvent.h"

#include "Voyager/Core/Timestep.h"

#include "Voyager/ImGui/ImGuiLayer.h"

namespace Voyager {

	class Application
	{
	public:
		Application(const std::string& name = "Voyager App");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

