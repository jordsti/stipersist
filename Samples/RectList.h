#ifndef RECTLIST_H
#define RECTLIST_H

#include <list>
#include "Persistable.h"
#include "Rectangle.h"

class RectList :
	public StiPersist::Persistable
{
public:
	RectList();
	virtual ~RectList();
	
	void createRect(int nb);
	
	void fromFields(void);
protected:
	void populateFields(void);
	
	std::list<Rectangle*> rects;
};

#endif