
project(punkt3d)

set(HEDEAR_FILES Punkt3d.h Point.h)
set(SOURCE_FILES Punkt3d.cpp Point.cpp)

add_library(libpunkt3d STATIC ${SOURCE_FILES})
target_include_directories(libpunkt3d PUBLIC .)

add_executable(punkt3d ${SOURCE_FILES} main.cpp)

target_link_libraries(punkt3d libpunkt3d)