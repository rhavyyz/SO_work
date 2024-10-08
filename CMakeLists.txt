cmake_minimum_required(VERSION 3.12)
project(server)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
cmake_policy(SET CMP0072 NEW)


set(types ${PROJECT_SOURCE_DIR}/types)
set(server_src ${PROJECT_SOURCE_DIR}/server/src)
set(client_src ${PROJECT_SOURCE_DIR}/client/src)
set(modules ${PROJECT_SOURCE_DIR}/modules)
set(utils ${PROJECT_SOURCE_DIR}/utils)
# set(windows_fac_folder ${PROJECT_SOURCE_DIR}/Factories/include/Windows)
# set(mac_fac_folder ${PRO#include "MyClass.h"JECT_SOURCE_DIR}/Factories/include/Mac)
# set(ui_folder ${PROJECT_SOURCE_DIR}/UiComponents/include)
# set(windows_ui_folder ${PROJECT_SOURCE_DIR}/UiComponents/include/Windows)
# set(mac_ui_folder ${PROJECT_SOURCE_DIR}/UiComponents/include/Mac)

# set(includes
#     ${fac_folder}
#     ${windows_fac_folder}
#     ${mac_fac_folder}
#     ${ui_folder} 
#     ${windows_ui_folder} 
#     ${mac_ui_folder} 
# )



file(GLOB_RECURSE server_source ${PROJECT_SOURCE_DIR}/server/src/*.cpp)
file(GLOB_RECURSE client_source ${PROJECT_SOURCE_DIR}/client/src/*.cpp)

add_executable(server server/main.cpp 
${types}
${utils}
${server_src}
)
target_include_directories(server PUBLIC ${utils})
target_include_directories(server PUBLIC ${types})
target_include_directories(server PUBLIC ${server_src})
target_include_directories(server PUBLIC ${modules})
target_sources(server PUBLIC ${server_source})

add_executable(client client/main.cpp 
    ${types}
    ${utils}
    ${client_src}
    )
target_include_directories(client PUBLIC ${utils})
target_include_directories(client PUBLIC ${types})
target_include_directories(client PUBLIC ${client_src})
target_sources(client PUBLIC ${client_source})
# CMakeLists.txt
# ...
# add_library(foo ...)
# ...
# find_package(nlohmann_json 3.2.0 REQUIRED)
# target_link_libraries(server PUBLIC_HEADER nlohmann_json::nlohmann_json)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    CXX_STANDARD 20
)

# target_include_directories(${PROJECT_NAME} PUBLIC ${includes})
# target_include_directories(${PROJECT_NAME} PUBLIC ${sources})
