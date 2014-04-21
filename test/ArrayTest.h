#ifndef ARRAYTEST_H
#define ARRAYTEST_H

#include "Array.h"
#include "IPersist.h"

class ArrayTest :
	public StiPersist::IPersist
{
public:
	ArrayTest();
	ArrayTest(unsigned int length);
	virtual ~ArrayTest();
	
	void add(IPersist *element);
	void print(void);
	void fromFields(void);
protected:
	void populateFields(void);
	
	StiPersist::Container::Array *array;
	
};

#endif