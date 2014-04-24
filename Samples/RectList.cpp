#include "RectList.h"
#include "ListField.h"
#include "ListIterator.h"
#include "FieldsObject.h"
#include "IntegerField.h"

using namespace StiPersist;


RectList::RectList() : Persistable()
{
	
}

RectList::~RectList()
{
	
}

void RectList::createRect(int nb)
{
	for(int i=0; i<nb; i++)
	{
		Rectangle *rect = new Rectangle();
		rect->setX(i);
		rect->setY(i*2);
		rect->setWidth(i*3);
		rect->setHeight(i*4);
		
		rects.push_back(rect);
	}
}

void RectList::fromFields(void)
{
	Container::List *rlist = getField<Data::ListField>("rects")->getList();
	
	Container::ListIterator *it = rlist->getIterator();
	
	while(it->moveNext())
	{
		FieldsObject *obj = it->getElement<FieldsObject>();
		
		Rectangle *rect = new Rectangle();
		
		rect->setX(obj->getField<Data::IntegerField>("x")->getInteger());
		rect->setY(obj->getField<Data::IntegerField>("y")->getInteger());
		rect->setWidth(obj->getField<Data::IntegerField>("width")->getInteger());
		rect->setHeight(obj->getField<Data::IntegerField>("height")->getInteger());
		
		rects.push_back(rect);
	}
	
}

void RectList::populateFields(void)
{
	Data::ListField *field = Data::CreateField<Data::ListField>("rects");
	Container::List *rlist = new Container::List();
	
	std::list<Rectangle*>::iterator lit(rects.begin()), lend(rects.end());
	for(;lit!=lend;++lit)
	{
		rlist->append((*lit));
	}
	
	field->setList(rlist);
	
	fields.push_back(field);
	
}