#pragma once

#include "Voyager/Renderer/Buffer.h"

namespace Voyager {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		// Inherited via VertexBuffer
		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		uint32_t m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		// Inherited via IndexBuffer
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual uint32_t GetCount() const override;
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}