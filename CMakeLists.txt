cmake_minimum_required(VERSION 3.25)
project(Ly_Engine)

set(CMAKE_CXX_STANDARD 23)

set(DIR D:/SDL2-2.28.3/x86_64-w64-mingw32)

add_executable(main main.cpp) # 可执行文件
add_library(engine STATIC Scene.cpp Scene.h Window.h Window.cpp Sprite.cpp Camera.h GameObject.h GameObject.cpp Ui.cpp
        Button.cpp Box.cpp CircleButton.cpp Text.cpp ${DIR}/include/SDL2/SDL_FontCache.h ${DIR}/include/SDL2/SDL_FontCache.c Music.cpp) # 静态库
# 库函数
target_link_libraries(main engine)
target_link_libraries(main SDL2 SDL2main SDL2_image SDL2_test SDL2_ttf)

include_directories(${DIR}/bin ${DIR}/include/SDL2 ${DIR}/lib)