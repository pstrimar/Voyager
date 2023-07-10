#include "vgrpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Voyager {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		VGR_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VGR_CORE_ASSERT(status, "Failed to initialize Glad!");

		VGR_CORE_INFO("Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		VGR_CORE_INFO("Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		VGR_CORE_INFO("Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}