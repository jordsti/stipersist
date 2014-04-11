#ifndef NESTEDOBJECT_H
#define NESTEDOBJECT_H

#include "IPersist.h"
#include "SimpleObject.h"

class NestedObject : 
	public StiPersist::IPersist
{
public:
	NestedObject();
	virtual ~NestedObject();
protected:
	void populateFields(void);
	void fromFields(void);
	SimpleObject *object1;
	std::string text2;
};

#endif