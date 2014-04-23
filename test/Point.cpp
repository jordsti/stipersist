#include "Point.h"
#include "IntegerField.h"

using namespace StiPersist;
using namespace Data;

Point::Point() : Persistable()
{
	x = 0;
	y = 0;
}

Point::Point(int m_x, int m_y) : Persistable()
{
	x = m_x;
	y = m_y;
}

Point::~Point() {}

int Point::getX(void)
{
	return x;
}

int Point::getY(void)
{
	return y;
}

void Point::setX(int m_x)
{
	x = m_x;
}

void Point::setY(int m_y)
{
	y = m_y;
}

void Point::populateFields(void)
{
	IntegerField *ifield;
	
	ifield = new IntegerField("x");
	ifield->setInteger(x);
	
	fields.push_back(ifield);
	
	ifield = new IntegerField("y");
	ifield->setInteger(y);
	
	fields.push_back(ifield);
}

void Point::fromFields(void)
{
	x = (dynamic_cast<IntegerField*>(getField("x")))->getInteger();
	y = (dynamic_cast<IntegerField*>(getField("y")))->getInteger();
}