# lytoy_enigne
## 关于项目
本项目为作者课设, 对SDL进行了一些封装。

## 使用的第三方库及其拓展库
SDL2.0\
SDL2_image\
SDL2_ttf\
SDL2_mixer\
SDL_FontCache

## 编译方法
下载SDL的动态库版本, 下载拓展库。`*.a`文件放入`lib`中。
`*.dll`文件放入`bin`文件夹中。`*.h`和`*.cpp`文件放入`include`文件夹中。
`*.lib`文件放入`lib`文件夹中。\
将cmake文件中的`SDL2_DIR`和修改为自己的路径。
在clion中直接点击运行即可。
