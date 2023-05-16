cmake_minimum_required(VERSION 3.21)
project(TP1_RayTracing)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS graphics window system)
include_directories(.)
include_directories(C:/SFML/include)
include_directories(C:/Dev/OpenCL-SDK/include)

add_compile_options(-O3)

add_executable(TP1_RayTracing
        Main.cc
        Vector3.hh
        Color.hh
        Image.hh
        Image.cc
        Object.hh
        Texture_Material.hh
        Uniform_Texture.hh
        Sphere.hh tools.hh Light.hh Point_Light.hh Point3.hh Camera.hh Scene.hh Engine.hh Rectangle.hh Triangle.hh Blob.hh PotentialPoint.hh Sierpinski.hh SDF.hh Mandelbulb.hh)


target_link_libraries(TP1_RayTracing sfml-graphics sfml-window sfml-system)