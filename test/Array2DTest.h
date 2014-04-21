#ifndef ARRAY2DTEST_H
#define ARRAY2DTEST_H

#include "IPersist.h"
#include "Array2D.h"

class Array2DTest :
	public StiPersist::IPersist
{
public:
	Array2DTest();
	Array2DTest(int i, int j);
	virtual ~Array2DTest();
	
	void add(int i, StiPersist::IPersist *obj);

	void print(void);
	
	void fromFields(void);
protected:
	void populateFields(void);
	
	StiPersist::Container::Array2D *array;
	
};

#endif