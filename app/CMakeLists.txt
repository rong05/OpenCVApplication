# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
#指定cmke版本
cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#add_library（）命令用于CMake添加依赖源文件或者库
#指令需传入三个参数（函数库名称、库类型、依赖源文件相对路径）
add_library( # Sets the name of the library.
             # 生成函数库的名称，即libnative-lib.so或者libnative-lib.a(lib和.so/.a默认缺省)
             native-lib
             #生成库类型：动态库为SHARED,静态库位STATIC
             # Sets the library as a shared library.
             SHARED
             # 依赖的c/cpp文件（相当路径）
             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
# find——library（）命令用于定位NDK中的库
find_library( # Sets the name of the path variable.
              #设置path变量的名称，这里为NDK 中的日志库
              log-lib
              #指定cmake查询库的名称
              #即在ndk开发部中查询liblog.so函数库，将其路径赋值给log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#target_link_libraries()命令用于指定要关联到的原生库的库
target_link_libraries( # Specifies the target library.
                       #指定目标库，与上面指定的函数库名一致
                       native-lib

                       #链接的库，根据log-lib变量对应liblog.so函数库
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )