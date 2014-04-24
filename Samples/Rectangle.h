#ifndef RECTANGLE_H
#define RECTANGLE_H

//Examples of a Persistable object
//Rectangle object that can be serialized

#include "Persistable.h"

class Rectangle :
	public StiPersist::Persistable
{
public:
	Rectangle();
	virtual ~Rectangle();
	
	void setX(int m_x);
	int getX(void);
	
	void setY(int m_y);
	int getY(void);
	
	void setWidth(int m_width);
	int getWidth(void);
	
	void setHeight(int m_height);
	int getHeight(void);

	//method to override for reading object from file
	
	void fromFields(void);
	
protected:
	//method to override for writing object to file
	
	void populateFields(void);
	
private:
	//members
	int x;
	int y;
	int width;
	int height;
};

#endif