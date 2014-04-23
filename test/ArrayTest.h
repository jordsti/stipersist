#ifndef ARRAYTEST_H
#define ARRAYTEST_H

#include "Array.h"
#include "Persistable.h"

class ArrayTest :
	public StiPersist::Persistable
{
public:
	ArrayTest();
	ArrayTest(unsigned int length);
	virtual ~ArrayTest();
	
	void add(Persistable *element);
	void print(void);
	void fromFields(void);
protected:
	void populateFields(void);
	
	StiPersist::Container::Array *array;
	
};

#endif