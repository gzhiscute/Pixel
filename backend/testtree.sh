bison --defines=pixel.tab.h -o pixel.cpp pixel.y
g++ -m32  pixel.cpp utils.cpp