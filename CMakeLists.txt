cmake_minimum_required(VERSION 3.24)
project(Proyecto1Datos2CE_Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto1Datos2CE_Server main.cpp Bullet.cpp Bullet.h ShipPlayer.cpp ShipPlayer.h BulletCollector.cpp BulletCollector.h Ammunation.cpp Ammunation.h ShipEnemy.cpp ShipEnemy.h Waves.cpp Waves.h Strategys.cpp Strategys.h)
