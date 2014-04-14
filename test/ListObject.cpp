#include "ListObject.h"

using namespace StiPersist;

ListObject::ListObject() : IPersist()
{
	value = 0;
}

ListObject::ListObject(int m_value) : IPersist()
{
	value = m_value;
}

ListObject::~ListObject()
{

}

void ListObject::setValue(int m_value)
{
	value = m_value;
}

int ListObject::getValue(void)
{
	return value;
}

void ListObject::populateFields(void)
{

}

void ListObject::fromFields(void)
{

}