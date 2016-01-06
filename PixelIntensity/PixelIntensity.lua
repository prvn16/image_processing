-- sample_premake.lua
solution "PixelIntensity"
   configurations { "Debug", "Release", "Machine" }
 
   project "PixelIntensity"
      kind "ConsoleApp"
      language "C++"
      objdir "${HOME}/src/cpp/image_processing/obj/%{cfg.buildcfg}"
      targetdir "${HOME}/src/cpp/image_processing/bin/%{cfg.buildcfg}"

      files { "**.H", "**.C" }
 
      configuration "Debug"
         defines { "_DEBUG" }
         flags { "Symbols" }
         targetsuffix "_g"
 
      configuration "Release"
         defines { "_REL" }
         flags { "Optimize" }

      configuration "Machine"
         defines { "_MACHINE" }
         flags { "Symbols" }
         targetsuffix "_m"

      configuration "gmake"
         buildoptions { "-Wall" }
         buildoptions { "-fPIC" }
         buildoptions { "-pthread" }
         buildoptions { "-std=c++14" }

      includedirs { "/usr/include", "/usr/local/include/opencv", "/usr/local/include/opencv2" }
      libdirs { "/usr/lib", "/usr/local/lib" }
      links { "opencv_core", "opencv_imgproc", "opencv_imgcodecs", "opencv_highgui" }
