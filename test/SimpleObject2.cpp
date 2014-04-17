#include "SimpleObject2.h"
#include "StringField.h"
#include "IntegerField.h"
#include "DoubleField.h"

using namespace StiPersist;
using namespace Data;

SimpleObject2::SimpleObject2()
{
	StringField *sf = new StringField("text1");
	IntegerField *ifield = new IntegerField("int1");
	
	DoubleField *df = new DoubleField("double1");
	
	fields.push_back(sf);
	fields.push_back(ifield);
	fields.push_back(df);
}

SimpleObject2::~SimpleObject2()
{

}