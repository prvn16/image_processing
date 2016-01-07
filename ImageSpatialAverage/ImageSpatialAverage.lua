-- sample_premake.lua
solution "ImageSpatialAverage"
    configurations { "Debug", "Release", "Machine" }
 
    objdir "${HOME}/src/cpp/image_processing/obj/%{cfg.buildcfg}"
    targetdir "${HOME}/src/cpp/image_processing/bin/%{cfg.buildcfg}"

    configuration "Debug"
        defines { "_DEBUG" }
        flags { "Symbols" }
        targetsuffix "_g"
 
    configuration "Release"
        defines { "_REL" }
        flags { "Optimize" }

    configuration "gmake"
        buildoptions { "-Wall" }
        buildoptions { "-fPIC" }
        buildoptions { "-pthread" }
        buildoptions { "-std=c++14" }

    includedirs { "/usr/include", 
                 "/usr/local/include/opencv", 
                 "/usr/local/include/opencv2" }
    libdirs { "/usr/lib", 
                "/usr/local/lib" }
    links { "opencv_core", 
           "opencv_imgproc", 
           "opencv_imgcodecs", 
           "opencv_highgui" }

    project "ImageSpatialAverage"
        kind "ConsoleApp"
        language "C++"
        files { "ImageSpatialAverage.C" }
