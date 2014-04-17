#ifndef MAPTEST_H
#define MAPTEST_H

#include "IPersist.h"
#include "Map.h"

class MapTest :
	public StiPersist::IPersist
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