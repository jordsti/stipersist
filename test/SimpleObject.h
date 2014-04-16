#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "IPersist.h"
#include "StringField.h"
#include "IntegerField.h"
#include "FloatField.h"
class SimpleObject : 
	public StiPersist::IPersist
{
public:
	SimpleObject();
	virtual ~SimpleObject();
	void fromFields(void);
protected:
	void populateFields(void);
private:
	int integer;
	std::string text;
	float fl;

};

#endif