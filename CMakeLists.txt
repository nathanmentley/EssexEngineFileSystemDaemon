#files

file(GLOB EssexEngineFileSystemDaemon_HEADERS
    "src/Daemons/FileSystemDaemon/src/*.h"
)
file(GLOB EssexEngineFileSystemDaemon_SRC
    ${EssexEngineFileSystemDaemon_HEADERS}
    "src/Daemons/FileSystemDaemon/src/*.cpp"
)

#setup headers

file(COPY ${EssexEngineFileSystemDaemon_HEADERS} DESTINATION "${CMAKE_BINARY_DIR}/lib/include/EssexEngineFileSystemDaemon/")

#setup build

add_library(EssexEngineFileSystemDaemon SHARED ${EssexEngineFileSystemDaemon_SRC})
target_link_libraries(EssexEngineFileSystemDaemon EssexEngineCore)

#setup tests

file(GLOB EssexEngineFileSystemDaemon_TESTSRC
    "src/Daemons/FileSystemDaemon/test/*.cpp"
)

add_executable(EssexEngineFileSystemDaemonTests ${EssexEngineFileSystemDaemon_TESTSRC})
add_test(NAME EssexEngineFileSystemDaemonTests COMMAND EssexEngineFileSystemDaemonTests)