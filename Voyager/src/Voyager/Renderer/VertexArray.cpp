#include "vgrpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Voyager/Platform/OpenGL/OpenGLVertexArray.h"

namespace Voyager {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			VGR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		}
		VGR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}