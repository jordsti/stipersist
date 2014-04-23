#ifndef MAPTEST_H
#define MAPTEST_H

#include "Persistable.h"
#include "Map.h"

class MapTest :
	public StiPersist::Persistable
{
public:
	MapTest();
	virtual ~MapTest();
	
	void add(std::string key, int x, int y);
	
	void print(void);
	
	void fromFields(void);
protected:
	StiPersist::Container::Map *map;
	
	void populateFields(void);
};

#endif