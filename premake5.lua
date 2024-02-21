workspace "NTNEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir={}
IncludeDir["GLFW"]= "NTNEngine/vendor/GLFW/include"

include "NTNEngine/vendor/GLFW"

project "NTNEngine"
	location "NTNEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir .. "/%{prj.name}")
	objdir("bin-int/".. outputdir .. "/%{prj.name}")
	
    -- Specify precompiled header settings
	pchheader "pch.h"
	pchsource "NTNEngine/src/pch.cpp"
	
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NTN_PLATFORM_WINDOWS",
			"NTN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NTN_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "NTN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NTN_DIST"
		buildoptions "/MD"
		optimize "On"

	filter{"system:windows","configurations:Release"}


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/".. outputdir .. "/%{prj.name}")
	objdir("bin-int/".. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"NTNEngine/src"
	}

	links
	{
		"NTNEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NTN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "NTN_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "NTN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NTN_DIST"
		buildoptions "/MD"
		optimize "On"

	filter{"system:windows","configurations:Release"}