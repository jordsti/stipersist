#include "SimpleObject.h"

#include "StringField.h"
#include "IntegerField.h"
#include "FloatField.h"
#include "BoolField.h"

using namespace StiPersist;
using namespace Data;

SimpleObject::SimpleObject() : IPersist()
{
	integer = 2000;
	text = "bla bla bla testing one two";
	fl = 34.34;
	b1 = false;
}

SimpleObject::~SimpleObject() {}

int SimpleObject::getInteger(void)
{
	return integer;
}

std::string SimpleObject::getText(void)
{
	return text;
}

float SimpleObject::getFl(void)
{
	return fl;
}

bool SimpleObject::getB1(void)
{
	return b1;
}

void SimpleObject::setValue(int m_integer, std::string m_text, float m_fl, bool m_b1)
{
	integer = m_integer;
	text = m_text;
	fl = m_fl;
	b1 = m_b1;
}

void SimpleObject::populateFields(void)
{
	/*IntegerField *ifield = new IntegerField("integer");
	ifield->setInteger(integer);*/
	
	IntegerField *ifield = CreateField<IntegerField>("integer");
	ifield->setInteger(integer);
	
	StringField *sfield = new StringField("text");
	sfield->setText(text);
	
	FloatField *ffield = new FloatField("fl");
	ffield->setFloat(fl);
	
	BoolField *bfield = new BoolField("b1");
	bfield->setBool(b1);
	
	fields.push_back(ifield);
	fields.push_back(sfield);
	fields.push_back(ffield);
	fields.push_back(bfield);
}

void SimpleObject::fromFields(void) 
{
	IntegerField *ifield = getField<IntegerField>("integer");
	integer = ifield->getInteger();
	
	StringField *sfield = getField<StringField>("text");
	text = sfield->getText();
	
	FloatField *ffield = getField<FloatField>("fl");
	fl = ffield->getFloat();
	
	BoolField *bfield = getField<BoolField>("b1");
	b1 = bfield->getBool();
}