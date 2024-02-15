workspace "NTNEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NTNEngine"
	location "NTNEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir .. "/%{prj.name}")
	objdir("bin-int/".. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "NTNEngine/src/pch.cpp"
	
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{

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
		optimize "On"

	filter "configurations:Release"
		defines "NTN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NTN_DIST"
		optimize "On"

	filter{"system:windows","configurations:Release"}
		buildoptions "/MT"


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
		optimize "On"

	filter "configurations:Release"
		defines "NTN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NTN_DIST"
		optimize "On"

	filter{"system:windows","configurations:Release"}
		buildoptions "/MT"