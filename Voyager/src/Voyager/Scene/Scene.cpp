#include "vgrpch.h"
#include "Scene.h"

#include "Voyager/Renderer/Renderer2D.h"
#include "Components.h"
#include <glm/glm.hpp>

namespace Voyager {

	Scene::Scene()
	{
#if ENTT_EXAMPLE_CODE
		entt::entity entity = m_Registry.create();

		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));

		auto view = m_Registry.view<TransformComponent>();
		for (auto entity : view)
		{
			auto transform = view.get<TransformComponent>(entity);
		}
#endif
	};

	Scene::~Scene()
	{
	}

	entt::entity Scene::CreateEntity()
	{
		return m_Registry.create();
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}
}