#include <iostream>
#include "NestedObject.h"
#include "ListObject.h"
#include "List.h"


using namespace StiPersist;
using namespace Container;

int main(int argc, char** argv)
{
	std::cout << "StiPerist : Container Test" << std::endl;

	List *list = new List();
	
	ListObject *lobj1 = new ListObject(1);
	ListObject *lobj2 = new ListObject(2);
	ListObject *lobj3 = new ListObject(3);
	ListObject *lobj4 = new ListObject(4);
	ListObject *lobj5 = new ListObject(5);
	ListObject *lobj6 = new ListObject(6);
	ListObject *lobj7 = new ListObject(100);
	
	std::cout << "List size : " << list->size() << std::endl;
	
	list->append(lobj1); //index : 0
	list->append(lobj2); //index : 1
	list->append(lobj3); //index : 2
	list->append(lobj4); //index : 3
	list->append(lobj5); //index : 4
	list->append(lobj6); //index : 5
	
	std::cout << (dynamic_cast<ListObject*>( list->get(4)->getElement()))->getValue() << " value at : 4 (5)" << std::endl;
	std::cout << (dynamic_cast<ListObject*>( list->get(0)->getElement()))->getValue() << " value at : 0 (1)" << std::endl;
	std::cout << (dynamic_cast<ListObject*>( list->get(5)->getElement()))->getValue() << " value at : 5 (6)" << std::endl;
	std::cout << (dynamic_cast<ListObject*>( list->get(1)->getElement()))->getValue() << " value at : 1 (2)" << std::endl;
	std::cout << "List size : " << list->size() << std::endl;
	
	list->insert(3, lobj7);
	std::cout << (dynamic_cast<ListObject*>( list->get(4)->getElement()))->getValue() << " value at : 4 (100)" << std::endl;
	std::cout << (dynamic_cast<ListObject*>( list->get(5)->getElement()))->getValue() << " value at : 5 (4)" << std::endl;
	
	std::cout << "List size : " << list->size() << std::endl;
	
	List *list2 = new List();
	
	ListObject *l2obj1 = new ListObject(200);
	ListObject *l2obj2 = new ListObject(201);
	ListObject *l2obj3 = new ListObject(202);
	ListObject *l2obj4 = new ListObject(203);
	
	list2->append(l2obj1);
	list2->append(l2obj2);
	list2->append(l2obj3);
	list2->append(l2obj4);
	
	list->insert(3, list2);
	
	//iterating list, maybe implement a Iterator interface

	ListNode *current = list->getFirst();
	//ListNode *current = first;
	
	while(current != nullptr)
	{
		int value = (dynamic_cast<ListObject*>( current->getElement() ))->getValue();
		std::cout << "\t -> " << value << std::endl;
		current = current->getNext();
	}
	
	std::cout << "List size : " << list->size() << std::endl;
	
	/* List
	*  To Implemented :
	*	-remove node
 	*   -pop (remove and return last item)
	*/
	
	std::cout << "StiPersist : Serialization Test" <<std::endl;
	NestedObject *obj = new NestedObject();
	
	obj->save("test.obj");
	
	/*SimpleObject *obj2 = new SimpleObject();
	
	obj2->load("test.obj");*/
	
	return 0;
}
