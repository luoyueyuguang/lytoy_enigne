cmake_minimum_required(VERSION 3.25)
project(Ly_Engine)

set(CMAKE_CXX_STANDARD 23)

set(DIR D:/SDL2-2.28.3/x86_64-w64-mingw32)

add_executable(main ../src/main.cpp) # 可执行文件
add_library(engine STATIC ../include/Scene.cpp ../include/Window.cpp ../include/Sprite.cpp ../include/GameObject.h
        ../include/GameObject.cpp ../include/Ui.cpp ../include/Button.cpp ../include/Box.cpp
        ../include/CircleButton.cpp ../include/Text.cpp ${DIR}/include/SDL2/SDL_FontCache.c
        ../include/Music.cpp ../src/Res.h src/Game.cpp src/Event.cpp src/Res.cpp) # 静态库
# 库函数
target_link_libraries(main engine)
target_link_libraries(main SDL2 SDL2main SDL2_image SDL2_test SDL2_ttf SDL2_mixer)

include_directories(${DIR}/bin ${DIR}/include/SDL2 ${DIR}/lib)