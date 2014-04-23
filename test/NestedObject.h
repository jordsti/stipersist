#ifndef NESTEDOBJECT_H
#define NESTEDOBJECT_H

#include "Persistable.h"
#include "SimpleObject.h"

class NestedObject : 
	public StiPersist::Persistable
{
public:
	NestedObject();
	virtual ~NestedObject();
	void fromFields(void);
protected:
	void populateFields(void);
	SimpleObject *object1;
	std::string text2;
};

#endif