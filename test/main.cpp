#include <iostream>
#include "SimpleObject.h"

int main(int argc, char** argv)
{
	std::cout << "StiPersist Test" <<std::endl;
	SimpleObject *obj = new SimpleObject();
	
	obj->save("test.obj");
	
	SimpleObject *obj2 = new SimpleObject();
	
	obj2->load("test.obj");
	
	return 0;
}
