
file(GLOB PROJECT_HEADERS
	"inc/*.h"
)

file(GLOB PROJECT_SOURCES
	"src/*.cpp"
)

source_group("Src" FILES PROJECT_SOURCES)
source_group("Inc" FILES PROJECT_HEADERS)

add_library(DungeonLogger
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
)

target_include_directories(DungeonLogger
	PUBLIC ${PROJECT_SOURCE_DIR}/Logger/inc
)
# Creates a folder "libraries" and adds target project (math.vcproj) under it
set_property(TARGET DungeonLogger PROPERTY FOLDER "DungeonLogger")

# Properties->General->Output Directory
set_target_properties(
	DungeonLogger PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)

add_custom_command(
	TARGET DungeonLogger
	PRE_BUILD
	COMMAND ${PROJECT_SOURCE_DIR}/Build.cmd
)

# Adds logic to INSTALL.vcproj to copy math.dll to the destination directory
install (TARGETS DungeonLogger
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)