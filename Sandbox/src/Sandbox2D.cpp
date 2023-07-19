#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	VGR_PROFILE_FUNCTION();

	m_CheckerboardTexture = Voyager::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	VGR_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Voyager::Timestep ts)
{
	VGR_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		VGR_PROFILE_SCOPE("Renderer Prep");
		Voyager::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Voyager::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		VGR_PROFILE_SCOPE("Renderer Draw");
		Voyager::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Voyager::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Voyager::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Voyager::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f } ,{ 0.2f, 0.3f, 0.8f, 1.0f });
		Voyager::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Voyager::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		Voyager::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	VGR_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Voyager::Event& e)
{
	m_CameraController.OnEvent(e);
}
