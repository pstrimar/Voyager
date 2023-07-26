#pragma once

#include "Voyager.h"

class Sandbox2D : public Voyager::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Voyager::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Voyager::Event& event) override;
private:
	Voyager::OrthographicCameraController m_CameraController;

	// Temp
	Voyager::Ref<Voyager::VertexArray> m_SquareVA;
	Voyager::Ref<Voyager::Shader> m_FlatColorShader;
	Voyager::Ref<Voyager::Framebuffer> m_Framebuffer;;

	Voyager::Ref<Voyager::Texture2D> m_CheckerboardTexture;
	
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};