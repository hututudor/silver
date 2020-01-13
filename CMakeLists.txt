cmake_minimum_required(VERSION 3.15)
project(silver)

set(CMAKE_CXX_STANDARD 14)

link_directories(deps/sfml/lib)
include_directories(deps/sfml/include)

include_directories(engine)

add_executable(silver test/main.cpp engine/Main.h engine/game/Game.cpp engine/game/Game.h engine/math/Vector2.h engine/math/Vector3.h engine/Macros.h engine/managers/ResourceManager.cpp engine/managers/ResourceManager.h engine/game/Scene.cpp engine/game/Scene.h engine/game/GameObject.cpp engine/game/GameObject.h engine/game/GameState.h)
target_link_libraries (silver sfml-graphics sfml-window sfml-system)