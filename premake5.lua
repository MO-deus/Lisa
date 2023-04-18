
workspace "Lisa"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Grimoire"
	location "Grimoire"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines  
		{
			"GRIM_CORE_WINDOW_PLATFORM",
			"GRIM_BUILD_DLL" 
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Lisa")
		}

	filter "configurations:Debug"
		defines "GM_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "GM_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "GM_DIST"
		optimize "On"

project "Lisa"
	location "Lisa"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Grimoire/vendor/spdlog/include",
		"Grimoire/src"
	}

	links
	{
		"Grimoire"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines  
		{
			"GRIM_CORE_WINDOW_PLATFORM"
		}

	filter "configurations:Debug"
		defines "GM_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "GM_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "GM_DIST"
		optimize "On"