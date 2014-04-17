#include "DefaultResolver.h"
#include "StringField.h"
#include "IntegerField.h"
#include "UIntegerField.h"
#include "FloatField.h"
#include "DoubleField.h"
#include "BoolField.h"
#include "RawField.h"
#include <iostream>
#include "Logger.h"
namespace StiPersist
{

	DefaultResolver::DefaultResolver() {}

	DefaultResolver::~DefaultResolver() {}

	bool DefaultResolver::isHandled(Data::FieldType type)
	{
		return (
			type == Data::FT_RAW ||
			type == Data::FT_STRING ||
			type == Data::FT_INTEGER ||
			type == Data::FT_UINTEGER ||
			type == Data::FT_DOUBLE ||
			type == Data::FT_FLOAT ||
			type == Data::FT_OBJECT ||
			type == Data::FT_DOUBLE
		);
	}
	
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
			
			parent->fromFields();
		}
	}
	
	Data::Field* DefaultResolver::getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk)
	{
		Data::Field *field = nullptr;
		std::string name = nameChunk->toString();
		Logger::Message(name);
		Logger::Message("Name Length : " + std::to_string(nameChunk->getLength()));
		Logger::Message("Type : " + std::to_string(type));
		
		// need to rework here with Field::fromDataChunk
		
		if(type == Data::FT_STRING)
		{	
			Data::StringField *sfield = new Data::StringField(name);
			//sfield->setText(dataChunk->toString());
			//return sfield;
			field = sfield;
		}
		else if(type == Data::FT_RAW)
		{
			Data::RawField *rfield = new Data::RawField(name);
			field = rfield;
		}
		else if(type == Data::FT_INTEGER)
		{

			Data::IntegerField *ifield = new Data::IntegerField(name);
			/*int ivalue = 0;
			char *data = dataChunk->getData();

			Data::IntStruct *istruct = reinterpret_cast<Data::IntStruct*>(data);
			ivalue = istruct->value;
			ifield->setInteger(ivalue);*/
			
			//return ifield;
			field = ifield;
		}
		else if(type == Data::FT_UINTEGER)
		{
			Data::UIntegerField *uifield = new Data::UIntegerField(name);
			field = uifield;
		}
		else if(type == Data::FT_FLOAT)
		{
			Data::FloatField *ffield = new Data::FloatField(name);
			/*char *data = dataChunk->getData();
			Data::FloatStruct *fstruct = reinterpret_cast<Data::FloatStruct*>(data);
			ffield->setFloat(fstruct->value);*/
			//return ffield;
			field = ffield;
		}
		else if(type == Data::FT_DOUBLE)
		{
			Data::DoubleField *dfield = new Data::DoubleField(name);
			
			field = dfield;
		}
		else if(type == Data::FT_BOOL)
		{
			Data::BoolField *bfield = new Data::BoolField(name);
			
			field = bfield;
		}
		else
		{
			Logger::Error("Field type not recognized !");
		}
		
		if(field != nullptr || field != 0)
		{
			field->fromDataChunk(dataChunk);
		}
	

		return field;
	}

}