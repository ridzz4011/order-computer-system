cmake_minimum_required(VERSION 3.27.7)
project(TokoKomputer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(TokoKomputer main.cpp

               src/functionMisc/clearscreen/clearscreen.cpp
               src/functionMisc/loading/loading.cpp
               src/functionMisc/pauseconsole/pauseconsole.cpp
               src/functionMisc/intro/intro.cpp
               
               src/functionTugas/addItem.cpp
               src/functionTugas/orderItem.cpp
               src/functionTugas/removeOrder.cpp
               src/functionTugas/editOrder.cpp
               src/functionTugas/displayStruk.cpp)

target_include_directories(TokoKomputer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
