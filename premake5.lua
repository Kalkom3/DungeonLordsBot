function useLib(test)
    includedirs { test .. "/**/inc" }
    links { test }
end

function addStdStaticLibProject(name)
    project (name) 
    kind "StaticLib"   
    targetdir "Build/Bin/%{prj.name}/%{cfg.longname}" 
	objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")
    includedirs { "%{prj.name}/**/inc" }
    files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" } 
end

workspace "DungeonLordsBot"  
--Glogal configs
    configurations { "Debug", "Release" } 
    architecture "x86_64"
    language "C++"   
    cppdialect "C++20"
    filter "configurations:Debug"
    defines { "DEBUG" }  
    symbols "On" 
    filter "configurations:Release"  
    defines { "NDEBUG" }    
    optimize "On" 
    filter {}
    location "Build" 

    filter "action:vs2022"
    prebuildcommands {
        "../Build.cmd vs2022"
    }
    filter{}

    addStdStaticLibProject("DlLogger")

    addStdStaticLibProject("GameAPI")
    useLib("DlLogger")
    
    project "GameAPITests"
        kind "ConsoleApp"

        targetdir "Build/Bin/%{prj.name}/%{cfg.longname}" 
        objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")
        files
        {
            "%{prj.name}/inc/**.h",
            "%{prj.name}/src/**.cpp",
            "lib/googletest/googletest/**.h",
            "lib/googletest/googletest/**.hpp",
            "lib/googletest/googletest/src/gtest-all.cc",
            "lib/googletest/googlemock/**.h",
            "lib/googletest/googlemock/**.hpp",
            "lib/googletest/googlemock/src/gmock-all.cc"
        }
        includedirs
        {
            "%{prj.name}/inc",
            "lib/googletest/googletest/include/gtest",
            "lib/googletest/googletest/include",
            "lib/googletest/googletest",
            "lib/googletest/googlemock/include/gmock",
            "lib/googletest/googlemock/include",
            "lib/googletest/googlemock"
        }
        useLib("GameAPI")

    project "Bot"  
        kind "ConsoleApp"   
        targetdir "Build/Bin/%{prj.name}/%{cfg.longname}" 
        objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")
        files { "%{prj.name}/**.h", "%{prj.name}/**.cpp" }
        useLib("GameAPI") 
        useLib("DlLogger")