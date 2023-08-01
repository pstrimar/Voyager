workspace "Voyager"
	architecture "x64"
	startproject "Voyager-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Voyager/vendor/GLFW/include"
IncludeDir["Glad"] = "Voyager/vendor/Glad/include"
IncludeDir["ImGui"] = "Voyager/vendor/imgui"
IncludeDir["glm"] = "Voyager/vendor/glm"
IncludeDir["stb_image"] = "Voyager/vendor/stb_image"
IncludeDir["entt"] = "Voyager/vendor/entt/include"
IncludeDir["yaml_cpp"] = "Voyager/vendor/yaml-cpp/include"

group "Dependencies"
	include "Voyager/vendor/GLFW"
	include "Voyager/vendor/Glad"
	include "Voyager/vendor/ImGui"
	include "Voyager/vendor/yaml-cpp"
group ""

project "Voyager"
	location "Voyager"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vgrpch.h"
	pchsource "Voyager/src/vgrpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"YAML_CPP_STATIC_DEFINE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VGR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "VGR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VGR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VGR_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Voyager/vendor/spdlog/include",
		"Voyager/src",
		"%{IncludeDir.glm}",
		"Voyager/vendor",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Voyager"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "VGR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VGR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VGR_DIST"
		runtime "Release"
		optimize "on"


project "Voyager-Editor"
	location "Voyager-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Voyager/vendor/spdlog/include",
		"Voyager/src",
		"%{IncludeDir.glm}",
		"Voyager/vendor",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Voyager"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "VGR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VGR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VGR_DIST"
		runtime "Release"
		optimize "on"