#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "IPersist.h"

class SimpleObject : 
	public StiPersist::IPersist
{
public:
	SimpleObject();
	virtual ~SimpleObject();
	void fromFields(void);
	
	void setValue(int m_integer, std::string m_text, float m_fl, bool m_b1);
	
	int getInteger(void);
	std::string getText(void);
	float getFl(void);
	bool getB1(void);
protected:
	void populateFields(void);
private:
	int integer;
	std::string text;
	float fl;
	bool b1;
};

#endif