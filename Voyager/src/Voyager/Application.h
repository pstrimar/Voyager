#pragma once

#include "Core.h"

#include "Window.h"
#include "Voyager/LayerStack.h"
#include "Voyager/Events/ApplicationEvent.h"

#include "Voyager/ImGui/ImGuiLayer.h"

#include "Voyager/Renderer/Shader.h"
#include "Voyager/Renderer/Buffer.h"
#include "Voyager/Renderer/VertexArray.h"

namespace Voyager {

	class VOYAGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

