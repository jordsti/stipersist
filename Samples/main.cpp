#include <iostream>
#include "RectList.h"
int main(int argc, char** argv)
{
	std::cout << "Hello !" << std::endl;
	RectList rl = RectList();
	
	rl.createRect(1024);
	
	rl.save("rects.obj");
}