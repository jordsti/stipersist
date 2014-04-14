#ifndef LISTOBJECT_H
#define LISTOBJECT_H

#include "IPersist.h"

class ListObject : 
	public StiPersist::IPersist
{
public:
	ListObject();
	ListObject(int m_value);
	virtual ~ListObject();
	
	void setValue(int m_value);
	int getValue(void);
	
protected:
	int value;
	void populateFields(void);
	void fromFields(void);
};


#endif