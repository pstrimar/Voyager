#include "vgrpch.h"
#include "Entity.h"

namespace Voyager {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}
}