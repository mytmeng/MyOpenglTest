aux_source_directory(. DIR_SRCS)
aux_source_directory(./CommonTools DIR_TOOLS)
add_executable(test1 ${DIR_SRCS} ${DIR_TOOLS})
message(${CMAKE_CURRENT_SOURCE_DIR}/resources/texture1.png)
message(${CMAKE_CURRENT_BINARY_DIR}/texture1.png)
add_custom_command(
	OUTPUT texture1
	COMMAND echo hello
	COMMAND cmake -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/texture1.png ${CMAKE_CURRENT_BINARY_DIR}/resources/texture1.png)
add_custom_target(Texture ALL DEPENDS texture1)
target_link_libraries(test1 glfw3 opengl32)