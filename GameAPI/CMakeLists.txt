
file(GLOB PROJECT_HEADERS
	"BoardComponents/inc/*.h"
	"Simulation/inc/*.h"
)

file(GLOB PROJECT_SOURCES
	"BoardComponents/src/*.cpp"
	"Simulation/src/*.cpp"
)

source_group("Src" FILES PROJECT_SOURCES)
source_group("Inc" FILES PROJECT_HEADERS)

add_library(GameAPILib
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
)

target_link_libraries(GameAPILib
	DungeonLogger
)

target_include_directories(GameAPILib
	PUBLIC ${PROJECT_SOURCE_DIR}/GameAPI/BoardComponents/inc
	PUBLIC ${PROJECT_SOURCE_DIR}/GameAPI/Simulation/inc
)
# Creates a folder "libraries" and adds target project (math.vcproj) under it
set_property(TARGET GameAPILib PROPERTY FOLDER "GameAPI")

# Properties->General->Output Directory
set_target_properties(GameAPILib PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_custom_command(
	TARGET GameAPILib
	PRE_BUILD
	COMMAND ${PROJECT_SOURCE_DIR}/Build.cmd
)

# Adds logic to INSTALL.vcproj to copy math.dll to the destination directory
install (TARGETS GameAPILib
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

