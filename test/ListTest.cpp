#include "ListTest.h"
#include "Point.h"
#include "FieldsObject.h"
#include <iostream>
#include "ListIterator.h"
#include "ListField.h"

using namespace StiPersist;
using namespace Data;
using namespace Container;

ListTest::ListTest() : IPersist()
{
	list = new List();
}

ListTest::~ListTest() {}

void ListTest::add(int x, int y)
{
	Point *pt = new Point(x, y);
	
	list->append(pt);
}

void ListTest::print(void)
{
	ListIterator *it = list->getIterator();
	
	while(it->moveNext())
	{
		FieldsObject *pt = dynamic_cast<FieldsObject*>(it->getElement());
	
		std::cout << "x : " << pt->getInt("x") << std::endl;
		std::cout << "y : " << pt->getInt("y") << std::endl;
		std::cout << "-----------------" << std::endl;
	}
}

void ListTest::fromFields(void)
{
	list = (dynamic_cast<ListField*>(getField("list")))->getList();
}

void ListTest::populateFields(void)
{
	ListField *field = new ListField("list");
	
	field->setList(list);
	
	fields.push_back(field);
}