workspace "AlphaEngine"
	architecture "X64"
	configurations {"Debug",
					"Release",
					"Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "AlphaEngine/3rdparty/glfw/include"

include "AlphaEngine/3rdparty/glfw"

project "AlphaEngine"
	location "AlphaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "Aepch.h"
	pchsource "AlphaEngine/src/Aepch.cpp"
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		}
	includedirs {"%{prj.name}/3rdparty/spdlog/include",
	             "%{prj.name}/src",
				 "%{IncludeDirs.GLFW}"}

	links {"GLFW",
		   "opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
		"AE_BUILD_DLL",
		"AE_PLATFORM_WINDOWS"
		}

		postbuildcommands 
		{
		 ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}
		filter "configurations:Debug"
			defines "AE_DEBUG"
			symbols "On"
		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"
		filter "configurations:Dist"
			defines "AE_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		}

	includedirs 
	{	"AlphaEngine/3rdparty/spdlog/include",
		"AlphaEngine/src"
	}
	links {"AlphaEngine"}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
		"AE_PLATFORM_WINDOWS"
		}

		
		filter "configurations:Debug"
			defines "AE_DEBUG"
			symbols "On"
		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"
		filter "configurations:Dist"
			defines "AE_DIST"
			optimize "On"