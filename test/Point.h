#ifndef POINT_H
#define POINT_H

#include "Persistable.h"

class Point :
	public StiPersist::Persistable
{
public:
	Point();
	Point(int m_x, int m_y);
	virtual ~Point();
	
	int getX(void);
	int getY(void);
	
	void setX(int m_x);
	void setY(int m_y);
	
	void fromFields(void);
protected:
	int x;
	int y;
	
	void populateFields(void);
};

#endif