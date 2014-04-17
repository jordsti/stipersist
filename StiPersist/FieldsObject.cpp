#include "FieldsObject.h"
#include "StringField.h"
#include "IntegerField.h"
#include "FloatField.h"
#include "DoubleField.h"
#include "UIntegerField.h"
#include "BoolField.h"
#include "RawField.h"
#include "Resolver.h"

namespace StiPersist
{
	FieldsObject::FieldsObject() : IPersist() {}
	FieldsObject::~FieldsObject() {}
	
	void FieldsObject::fromFields(void) {}
	void FieldsObject::populateFields(void) {}
	
	void FieldsObject::fromChunk(Data::Chunk *chunk)
	{
		char *data = chunk->getData();
		unsigned int length = chunk->getLength();
		unsigned int m_length = sizeof(Data::FieldMarker);
		Data::FieldMarker *marker = new Data::FieldMarker();
		unsigned int current = 0;
		
		while(current < length)
		{
			char *m_data = new char[m_length];
			
			for(int i=0; i<m_length; i++)
			{
				m_data[i] = data[current+i];
			}
			
			current += m_length;
			
			marker = reinterpret_cast<Data::FieldMarker*>(m_data);
			
			char *f_name = new char[marker->nameLength];
			
			for(int i=0; i<marker->nameLength; i++)
			{
				f_name[i] = data[current+i];
			}
			
			current += marker->nameLength;
			
			Data::Chunk *nameChunk = new Data::Chunk(f_name, marker->nameLength);
			
			char *f_data = new char[marker->dataLength];
			
			for(int i=0; i<marker->dataLength; i++)
			{
				f_data[i] = data[current+i];
			}
			
			current += marker->dataLength;
			
			Data::Chunk *dataChunk = new Data::Chunk(f_data, marker->dataLength);
			
			if(marker->type == Data::FT_EOF)
			{
				break;
			}
			
			Data::Field *field = resolver->getField(marker->type, nameChunk, dataChunk);
			
			fields.push_back(field);
		}
		
	}
	
	void FieldsObject::setString(std::string fname, std::string value)
	{
		Data::StringField *field = dynamic_cast<Data::StringField*>(getField(fname));
		field->setText(value);
	}
	
	void FieldsObject::setInt(std::string fname, int value)
	{
		Data::IntegerField *field = dynamic_cast<Data::IntegerField*>(getField(fname));
		field->setInteger(value);
	}
	
	void FieldsObject::setDouble(std::string fname, double value)
	{
		Data::DoubleField *field = dynamic_cast<Data::DoubleField*>(getField(fname));
		field->setDouble(value);
	}
	
	void FieldsObject::setFloat(std::string fname, float value)
	{
		Data::FloatField *field = dynamic_cast<Data::FloatField*>(getField(fname));
		field->setFloat(value);
	}
	
	void FieldsObject::setRaw(std::string fname, char *value, unsigned int length)
	{
		Data::RawField *field = dynamic_cast<Data::RawField*>(getField(fname));
		field->setData(value, length);
	}
	
	void FieldsObject::setUInt(std::string fname, unsigned int value)
	{
		Data::UIntegerField *field = dynamic_cast<Data::UIntegerField*>(getField(fname));
		field->setUInteger(value);
	}
	
	void FieldsObject::setBool(std::string fname, bool value)
	{
		Data::BoolField *field = dynamic_cast<Data::BoolField*>(getField(fname));
		field->setBool(value);
	}
	
	std::string FieldsObject::getString(std::string fname)
	{
		return (dynamic_cast<Data::StringField*>(getField(fname)))->getText();
	}
	
	int FieldsObject::getInt(std::string fname)
	{
		return (dynamic_cast<Data::IntegerField*>(getField(fname)))->getInteger();
	}
	
	double FieldsObject::getDouble(std::string fname)
	{
		return (dynamic_cast<Data::DoubleField*>(getField(fname)))->getDouble();
	}
	
	float FieldsObject::getFloat(std::string fname)
	{
		return (dynamic_cast<Data::FloatField*>(getField(fname)))->getFloat();
	}
	
	char* FieldsObject::getRaw(std::string fname)
	{
		return (dynamic_cast<Data::RawField*>(getField(fname)))->getData();
	}

	unsigned int FieldsObject::getUInt(std::string fname)
	{
			return (dynamic_cast<Data::UIntegerField*>(getField(fname)))->getUInteger();
	}
	
	bool FieldsObject::getBool(std::string fname)
	{
			return (dynamic_cast<Data::BoolField*>(getField(fname)))->getBool();
	}
	
	std::list<Data::FieldInfo*>* FieldsObject::getFieldsName(void)
	{
		std::list<Data::FieldInfo*> *finfo = new std::list<Data::FieldInfo*>();
		
		std::list<Data::Field*>::iterator lit(fields.begin()), lend(fields.end());
		
		for(;lit!=lend;++lit)
		{
			Data::FieldInfo *info = new Data::FieldInfo();
			info->type = static_cast<Data::FieldType>((*lit)->getType());
			info->name = (*lit)->getName();
			
			finfo->push_back(info);
		}
		
		return finfo;
	}

}