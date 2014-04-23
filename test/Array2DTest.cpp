#include "Array2DTest.h"
#include "IntegerField.h"
#include "Array2DField.h"
#include <iostream>
#include "Array2DIterator.h"
#include "FieldsObject.h"

using namespace StiPersist;
using namespace Data;
using namespace Container;

Array2DTest::Array2DTest() : Persistable()
{
	array = new Array2D();
}

Array2DTest::Array2DTest(int i, int j) : Persistable()
{
	array = new Array2D(i, j);
}

Array2DTest::~Array2DTest() {}

void Array2DTest::add(int i, Persistable *obj)
{
	array->append(i, obj);
}

void Array2DTest::print(void)
{
	/*for(int i=0; i<array->getiLength(); i++)
	{
		for(int j=0; j<array->getjLength(); j++)
		{
			IPersist *obj = array->get(i, j);

			std::cout << "i: " << i <<", j:" << j << std::endl;
			std::cout << " x: " << obj->getField<IntegerField>("x")->getInteger() << std::endl;
			std::cout << " y: " << obj->getField<IntegerField>("y")->getInteger() << std::endl;

		}
	}*/
	
	Array2DIterator *it = array->getIterator();
	
	while(it->moveNext())
	{
		std::cout << "i: " << it->getI() << ", j:" << it->getJ() << std::endl;
		FieldsObject *obj = it->getElement<FieldsObject>();
		std::cout << "x: " << obj->getInt("x") << std::endl;
		std::cout << "y: " << obj->getInt("y") << std::endl;
	}
}

void Array2DTest::fromFields(void)
{
	array = getField<Array2DField>("array")->getArray();
}

void Array2DTest::populateFields(void)
{
	Array2DField *field = CreateField<Array2DField>("array");
	field->setArray(array);

	fields.push_back(field);
}
