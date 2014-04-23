#include "ArrayTest.h"
#include "ArrayField.h"
#include "ArrayIterator.h"
#include "FieldsObject.h"
#include <iostream>

using namespace StiPersist;
using namespace Data;
using namespace Container;

ArrayTest::ArrayTest()
{
	array = new Array();
}

ArrayTest::ArrayTest(unsigned int length) : Persistable()
{
	array = new Array(length);
}

ArrayTest::~ArrayTest(){}

void ArrayTest::add(Persistable *element)
{
	array->append(element);
}
	
void ArrayTest::fromFields(void)
{
	array = getField<ArrayField>("array")->getArray();
}

void ArrayTest::print(void)
{
	ArrayIterator *it = array->getIterator();
	
	while(it->moveNext())
	{
		FieldsObject *obj = it->getElement<FieldsObject>();
		std::cout << " i: " << it->getIndex() << std::endl;
		std::cout << "x: " << obj->getInt("x") << std::endl;
		std::cout << "y: " << obj->getInt("y") << std::endl;
	}
	
}

void ArrayTest::populateFields(void)
{
	ArrayField *afield = CreateField<ArrayField>("array");
	afield->setArray(array);
	
	fields.push_back(afield);
}