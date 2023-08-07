#pragma once

#include "Voyager/Scene/Scene.h"
#include "Voyager/Renderer/Texture.h"
#include <filesystem>

namespace Voyager {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
	};
}