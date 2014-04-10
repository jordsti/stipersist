#include "SimpleObject.h"

using namespace StiPersist;
using namespace Data;

SimpleObject::SimpleObject() : IPersist()
{
	integer = 2000;
	text = "bla bla bla testing one two";
}

SimpleObject::~SimpleObject() {}

void SimpleObject::populateFields(void)
{
	IntegerField *ifield = new IntegerField("integer");
	ifield->setInteger(integer);
	
	StringField *sfield = new StringField("text");
	sfield->setText(text);
	
	fields.push_back(ifield);
	fields.push_back(sfield);
}

void SimpleObject::fromFields(void) {}