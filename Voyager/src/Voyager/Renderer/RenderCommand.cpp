#include "vgrpch.h"
#include "RenderCommand.h"

#include "Voyager/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Voyager {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}