#include "NestedObject.h"
#include "ObjectField.h"
using namespace StiPersist;
using namespace Data;

NestedObject::NestedObject() :
	IPersist()
{
	object1 = new SimpleObject();
	text2 = "ets ets ets ets ets";
	
	addChild("object1", object1);
}

NestedObject::~NestedObject()
{

}

void NestedObject::fromFields(void)
{

}

void NestedObject::populateFields(void)
{
	StringField *sf = new StringField("text2");
	sf->setText(text2);
	
	/*ObjectField *of = new ObjectField("object1");
	of->setObject(object1);*/
	
	fields.push_back(sf);
	//fields.push_back(of);
}