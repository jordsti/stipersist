#include <iostream>
#include "SimpleObject.h"

int main(int argc, char** argv)
{
	std::cout << "StiPersist Test" <<std::endl;
	SimpleObject obj = SimpleObject();
	
	obj.save("test.obj");
	
	return 0;
}
