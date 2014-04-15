#include "DefaultResolver.h"
#include "StringField.h"
#include "IntegerField.h"
#include "FloatField.h"
#include <iostream>

namespace StiPersist
{

	DefaultResolver::DefaultResolver() {}

	DefaultResolver::~DefaultResolver() {}

	void DefaultResolver::buildObjectField(Data::Chunk *nameChunk, Data::Chunk *dataChunk, IPersist *parent)
	{
		//todo
		std::string name = nameChunk->toString();
		
		IPersist *child = parent->getChild(name);
		
		if(child != nullptr)
		{
			char *data = dataChunk->getData();
			unsigned int length = dataChunk->getLength();
			unsigned int current = 0;
			Data::FieldMarker *marker;
			int m_size = sizeof(Data::FieldMarker);
			Data::Chunk *cnameChunk;
			Data::Chunk *cdataChunk;
			
			char *fm_buffer = new char[m_size];
			
			for(int i=0; i<m_size; i++)
			{
				fm_buffer[i] = data[i];
			}
			
			marker = reinterpret_cast<Data::FieldMarker*>(fm_buffer);
			
			current += m_size;
			
			while(marker->type != Data::FT_EOF)
			{
				char *f_name = new char[marker->nameLength];
				char *f_data = new char[marker->dataLength];
				//reading name
				for(int i=0; i<marker->nameLength; i++)
				{
					f_name[i] = data[current+i];
				}
				
				current += marker->nameLength;
				
				cnameChunk = new Data::Chunk(f_name, marker->nameLength);
				
				//reading data
				
				for(int i=0; i<marker->dataLength; i++)
				{
					f_data[i] = data[current+i];
				}
				
				current += marker->dataLength;
				
				cdataChunk = new Data::Chunk(f_data, marker->dataLength);
				
				if(marker->type == Data::FT_OBJECT)
				{
					buildObjectField(cnameChunk, cdataChunk, parent->getChild(cnameChunk->toString()));
				}
				else
				{
					Data::Field *field = getField(marker->type, cnameChunk, cdataChunk);
					if(field != nullptr)
					{
						parent->addField(field);
					}
				}
				
				//reading next marker
				for(int i=0; i<m_size; i++)
				{
					fm_buffer[i] = data[current+i];
				}
				
				marker = reinterpret_cast<Data::FieldMarker*>(fm_buffer);
				current += m_size;
			}
			
		}
	}
	
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