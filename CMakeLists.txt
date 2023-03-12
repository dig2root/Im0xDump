cmake_minimum_required(VERSION 3.24)
project(Im0xDump)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/ImGuiFrame.cpp"
	"include/ImGuiFrame.h"
	"include/MainImGuiFrame.h"
	"src/MainImGuiFrame.cpp"
	"include/ImGuiFileBrowser.h"
	"include/Dirent/dirent.h"
	"src/ImGuiFileBrowser.cpp"
	"src/FileDumper.cpp"
	"include/ImGuiMemoryEditor.h")
target_include_directories(${PROJECT_NAME} PRIVATE include)

find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)