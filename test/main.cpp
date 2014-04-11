#include <iostream>
#include "NestedObject.h"

int main(int argc, char** argv)
{
	std::cout << "StiPersist Test" <<std::endl;
	NestedObject *obj = new NestedObject();
	
	obj->save("test.obj");
	
	/*SimpleObject *obj2 = new SimpleObject();
	
	obj2->load("test.obj");*/
	
	return 0;
}
