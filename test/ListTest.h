#ifndef LISTTEST_H
#define LISTTEST_H

#include "Persistable.h"
#include "List.h"

class ListTest :
	public StiPersist::Persistable
{
public:
	ListTest();
	virtual ~ListTest();
	
	void print(void);
	
	void add(int x, int y);
	
	void fromFields(void);
protected:
	void populateFields(void);

	StiPersist::Container::List *list;
};

#endif