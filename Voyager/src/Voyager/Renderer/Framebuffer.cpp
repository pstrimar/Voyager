#include "vgrpch.h"
#include "Framebuffer.h"
#include "Renderer.h"
#include "Voyager/Platform/OpenGL/OpenGLFramebuffer.h"

namespace Voyager {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			VGR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLFramebuffer>(spec);
		}
		VGR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}