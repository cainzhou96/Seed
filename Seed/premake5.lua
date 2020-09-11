workspace "Seed"
	architecture "x64"

	configurations {
		"Debug", 
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Seed"
	location "Seed"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/submodules/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
			"SD_PLATFORM_WINDOWS",
			"SD_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SD_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Seed/submodules/spdlog/include", 
		"Seed/src"
	}

	links {
		"Seed"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
			"SD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SD_DIST"
		optimize "On"
