#include "vgrpch.h"
#include "UniformBuffer.h"

#include "Voyager/Renderer/Renderer.h"
#include "Voyager/Platform/OpenGL/OpenGLUniformBuffer.h"

namespace Voyager {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    VGR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		VGR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}