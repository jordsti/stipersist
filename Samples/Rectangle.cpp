#include "Rectangle.h"
#include "IntegerField.h"

using namespace StiPersist;

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle::~Rectangle()
{
	
}
	
void Rectangle::setX(int m_x)
{
	x = m_x;
}

int Rectangle::getX(void)
{
	return x;
}

void Rectangle::setY(int m_y)
{
	y = m_y;
}

int Rectangle::getY(void)
{
	return y;
}

void Rectangle::setWidth(int m_width)
{
	width = m_width;
}

int Rectangle::getWidth(void)
{
	return width;
}

void Rectangle::setHeight(int m_height)
{
	height = m_height;
}

int Rectangle::getHeight(void)
{
	return height;
}

//method to override for reading object from file
void Rectangle::fromFields(void)
{
	x = getField<Data::IntegerField>("x")->getInteger();
	y = getField<Data::IntegerField>("y")->getInteger();
	width = getField<Data::IntegerField>("width")->getInteger();
	height = getField<Data::IntegerField>("height")->getInteger();
}

//method to override for writing object to file
void Rectangle::populateFields(void)
{
	Data::IntegerField *field = Data::CreateField<Data::IntegerField>("x");
	field->setInteger(x);
	fields.push_back(field);
	
	field = Data::CreateField<Data::IntegerField>("y");
	field->setInteger(y);
	fields.push_back(field);
	
	field = Data::CreateField<Data::IntegerField>("width");
	field->setInteger(width);
	fields.push_back(field);
	
	field = Data::CreateField<Data::IntegerField>("height");
	field->setInteger(height);
	fields.push_back(field);
}