#include <iostream>
#include "NestedObject.h"
#include "SimpleObject2.h"
#include "ListObject.h"
#include "List.h"
#include "ListIterator.h"
#include "ListTest.h"
#include "MapTest.h"
#include "StringField.h"

using namespace StiPersist;
using namespace Container;


int main(int argc, char** argv)
{
	/*std::cout << "StiPerist : Container Test" << std::endl;

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
	
	ListNode *last = list->pop();
	
	std::cout << (dynamic_cast<ListObject*>(last->getElement()))->getValue() << " Pop " << std::endl;
	
	current = list->getFirst();
	//ListNode *current = first;
	
	while(current != nullptr)
	{
		int value = (dynamic_cast<ListObject*>( current->getElement() ))->getValue();
		std::cout << "\t -> " << value << std::endl;
		current = current->getNext();
	}
	
	//test iterator
	
	for(int i=0; i<600; i++)
	{
		ListObject *obj = new ListObject();
		obj->setValue(i);
		list->insert(5, obj);
	}
	
	ListIterator *iterator = list->getIterator();
	std::cout << "Iterator test" << std::endl;
	while(iterator->moveNext())
	{
		std::cout << "it : " << (dynamic_cast<ListObject*>(iterator->getElement()))->getValue() << std::endl;
	}*/
	
	
	
	/* List
	*  To Implemented :
	*	-remove node
 	*   -pop (remove and return last item)
	*/
	
	std::cout << "StiPersist : Serialization Test" <<std::endl;
	//NestedObject *obj = new NestedObject();
	
	//obj->save("test.obj");
	
	/*SimpleObject *obj2 = new SimpleObject();
	
	obj2->load("test.obj");*/
	//NestedObject *obj5 = new NestedObject();
	//obj5->load("test.obj");
	
	SimpleObject *obj = new SimpleObject();
	
	obj->setValue(3200, "allo yeah !", 5.14, false);
	obj->save("test.obj");
	
	SimpleObject *obj2 = new SimpleObject();
	
	obj2->load("test.obj");
	
	std::cout << "Integer : " << obj2->getInteger() << std::endl;
	std::cout << "Text : " << obj2->getText() << std::endl;
	std::cout << "Fl : " << obj2->getFl() << std::endl;
	std::cout << "B1 : " << obj2->getB1() << std::endl;
	
	
	SimpleObject2 *obj3 = new SimpleObject2();
	
	obj3->setString("text1", "alloha alloha allohahahah");
	obj3->setInt("int1", 202033);
	obj3->setDouble("double1", 7.8330);
	
	obj3->save("test2.obj");
	
	SimpleObject2 *obj4 = new SimpleObject2();
	
	obj4->load("test2.obj");
	
	std::cout << "String : " << obj3->getString("text1") << std::endl;
	std::cout << "Int : " << obj3->getInt("int1") << std::endl;
	std::cout << "Double : " << obj3->getDouble("double1") << std::endl;
	
	
	ListTest *test = new ListTest();
	for(int i=0; i<1024; i++)
	{
		test->add(i, i*2);
	}
	
	test->save("list.obj");
	
	ListTest *test2 = new ListTest();
	test2->load("list.obj");
	test2->print();
	
	MapTest *mtest = new MapTest();
	
	mtest->add("point1", 0, 0);
	mtest->add("point2", 1, 1);
	mtest->add("point3", 2, 0);
	mtest->add("point4", 3, 3);
	mtest->add("point5", 4, 0);
	mtest->add("point6", 0, 5);
	mtest->add("point7", 6, 0);
	
	mtest->save("map.obj");
	
	MapTest *mtest2 = new MapTest();
	
	mtest2->load("map.obj");
	mtest2->print();
	
	
	std::cout << "TEST TEMPLATE " << obj->getField<Data::StringField>("text")->getText();
	
	return 0;
}
