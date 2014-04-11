#include "DefaultResolver.h"
#include "StringField.h"
#include "IntegerField.h"
#include "FloatField.h"
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

			Data::IntStruct *istruct = reinterpret_cast<Data::IntStruct*>(data);
			ivalue = istruct->value;
			ifield->setInteger(ivalue);
			
			std::cout << "Integer : " << ivalue << std::endl;
			
			return ifield;
		}
		else if(type == Data::FT_FLOAT)
		{
			Data::FloatField *ffield = new Data::FloatField(name);
			std::cout << "Float" << std::endl;
			char *data = dataChunk->getData();
			Data::FloatStruct *fstruct = reinterpret_cast<Data::FloatStruct*>(data);
			ffield->setFloat(fstruct->value);
			std::cout << "FL value : " << ffield->getFloat() <<std::endl;
			return ffield;
		}
	

		return field;
	}

}