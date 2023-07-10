#include "vgrpch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace Voyager {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void Voyager::OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void Voyager::OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

}
