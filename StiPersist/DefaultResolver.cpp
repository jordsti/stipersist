#include "DefaultResolver.h"
#include "StringField.h"
#include "IntegerField.h"

#include <iostream>

namespace StiPersist
{

	DefaultResolver::DefaultResolver() {}

	DefaultResolver::~DefaultResolver() {}

	Data::Field* DefaultResolver::getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk)
	{
		Data::Field *field = nullptr;
		std::string name = nameChunk->toString();
		std::cout << name << std::endl;
		std::cout << "Name Length : " << nameChunk->getLength() << std::endl;
		std::cout << "Type : " << type << std::endl;
		if(type == Data::FT_STRING)
		{	
			std::cout << "String" << std::endl;
			std::cout << name << std::endl;
			Data::StringField *sfield = new Data::StringField(name);
			sfield->setText(dataChunk->toString());
			std::cout << "Text : " << sfield->getText() << std::endl;
			return sfield;
		}
		else if(type == Data::FT_INTEGER)
		{
			std::cout << "Integer" << std::endl;
			Data::IntegerField *ifield = new Data::IntegerField(name);
			int ivalue = 0;
			char *data = dataChunk->getData();
			ivalue = ivalue | data[3];
			ivalue = ivalue << 8;
			ivalue = ivalue | data[2];
			ivalue = ivalue << 8;
			ivalue = ivalue | data[1];
			ivalue = ivalue << 8;
			ivalue = ivalue | data[0];
			ifield->setInteger(ivalue);
			return ifield;
		}
	

		return field;
	}

}