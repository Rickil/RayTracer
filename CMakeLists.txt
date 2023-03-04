cmake_minimum_required(VERSION 3.21)
project(TP1_RayTracing)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(TP1_RayTracing
        Main.cc
        Vector3.hh
        Color.hh
        Image.hh
        Image.cc
        Object.hh
        Texture_Material.hh
        Uniform_Texture.hh
        Sphere.hh tools.hh Light.hh Point_Light.hh Point3.hh Camera.hh Scene.hh Engine.hh Rectangle.hh)
