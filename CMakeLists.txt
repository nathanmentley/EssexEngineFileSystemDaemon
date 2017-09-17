#files

file(GLOB EssexEngineFileSystemDaemon_HEADERS
    "src/Daemons/FileSystem/*.h"
)
file(GLOB EssexEngineFileSystemDaemon_SRC
    ${EssexEngineFileSystemDaemon_HEADERS}
    "src/Daemons/FileSystem/*.cpp"
)

#setup headers

file(COPY ${EssexEngineFileSystemDaemon_HEADERS} DESTINATION "${CMAKE_BINARY_DIR}/lib/include/EssexEngineFileSystemDaemon/")

#setup build

add_library(EssexEngineFileSystemDaemon SHARED ${EssexEngineFileSystemDaemon_SRC})
target_link_libraries(EssexEngineFileSystemDaemon EssexEngineCore)