

add_executable(Bot DungeonLordsBot.cpp)

target_link_libraries(Bot
	GameAPILib
    DungeonLogger
)

set_property(TARGET Bot PROPERTY FOLDER "DungeonLordsApp")

# Properties->General->Output Directory
set_target_properties(
	Bot PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)

add_custom_command(
	TARGET Bot
	PRE_BUILD
	COMMAND ${PROJECT_SOURCE_DIR}/Build.cmd
)

# Adds logic to INSTALL.vcproj to copy app.exe to destination directory
install (TARGETS Bot
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)
