#include "MapTest.h"
#include "Point.h"
#include "FieldsObject.h"
#include "MapIterator.h"
#include "MapField.h"
#include <iostream>

using namespace StiPersist;
using namespace Data;
using namespace Container;

MapTest::MapTest() : IPersist()
{
	map = new Map();
}

MapTest::~MapTest() {}

void MapTest::add(std::string key, int x, int y)
{
	Point *pt = new Point(x, y);
	
	map->append(key, pt);
}

void MapTest::print(void)
{
	MapIterator *it = map->getIterator();
	
	while(it->moveNext())
	{
		FieldsObject *obj = dynamic_cast<FieldsObject*>(it->getElement());
		
		std::cout << "Key : " << it->getKey() << std::endl;
		std::cout << "x : " << obj->getInt("x") << std::endl;
		std::cout << "y : " << obj->getInt("y") << std::endl;
		std::cout << "------------" << std::endl;
	}
}

void MapTest::fromFields(void)
{
	map = (dynamic_cast<MapField*>(getField("map")))->getMap();
}

void MapTest::populateFields(void)
{
	MapField *field = new MapField("map");
	field->setMap(map);
	
	fields.push_back(field);
}