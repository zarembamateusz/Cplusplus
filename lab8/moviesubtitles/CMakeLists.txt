
project(moviesubtitles)

set(HEDEAR_FILES MovieSubtitles.h MicroDvdSubtitles.h SubRipSubtitles.h Wyjatki.h)
set(SOURCE_FILES MovieSubtitles.cpp MicroDvdSubtitles.cpp SubRipSubtitles.cpp Wyjatki.cpp)

add_library(libmoviesubtitles STATIC ${SOURCE_FILES})
target_include_directories(libmoviesubtitles PUBLIC .)

add_executable(moviesubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(moviesubtitles libmoviesubtitles)