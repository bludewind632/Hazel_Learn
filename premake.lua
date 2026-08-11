workspace "Hazel_Learn"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

-- Debug-Windows-x64
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Hazel_Learn"
	location "Hazel_Learn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.28000.2114"

		defines {
			"HZ_BUILD_DLL",
			"HZ_PLATFORM_WINDOWS"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "HZ_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "HZ_DIST"
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
		"Hazel_Learn/vendor/spdlog/include",
		"Hazel_Learn/src"
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.28000.2114"

		defines {
			"HZ_PLATFORM_WINDOWS"
		}

		links {
			"Hazel_Learn"
		}
		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "HZ_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "HZ_DIST"
			optimize "On"