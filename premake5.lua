workspace "RacingGame"
   configurations { "Debug", "Release" }
   architecture "x86_64"
   toolset "clang"

project "RacingGame"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"

   includedirs { "vendor/Raylib/include" }  -- Adjust paths as needed
   libdirs { "vendor/Raylib/lib" }  -- Adjust paths as needed  
   links { "raylib.lib", "gdi32", "winmm", "user32", "shell32" }

   files { "src/**.cpp", "src/**.h" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "Full"
      optimize "Off"
      buildoptions { "-g", "-gcodeview" }  -- Enable debug symbols and use CodeView format for Windows
      linkoptions { "-fuse-ld=lld", "-g", "-Wl,/DEBUG:FULL" }  -- Use LLD as the linker and enable full debug info

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Full"
