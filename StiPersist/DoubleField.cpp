#include "DoubleField.h"


namespace StiPersist
{
	namespace Data
	{
		DoubleField::DoubleField(std::string m_name) :
			Field(m_name, FT_DOUBLE)
		{
			value = 0;
		}
		
		DoubleField::~DoubleField() {}
			
		Chunk* DoubleField::getDataChunk(void)
		{
			DoubleStruct *dstruct = new DoubleStruct();
			unsigned int length = sizeof(DoubleStruct);
			
			dstruct->value = value;
			
			char *m_data = reinterpret_cast<char*>(dstruct);
			
			Chunk *chunk = new Chunk(m_data, length);
			
			return chunk;
		}
		
		void DoubleField::fromDataChunk(Chunk *dataChunk)
		{
			DoubleStruct *dstruct = reinterpret_cast<DoubleStruct*>(dataChunk->getData());
			value = dstruct->value;
		}
			
		void DoubleField::setDouble(double m_value)
		{
			value = m_value;
		}
		
		double DoubleField::getDouble(void)
		{
			return value;
		}
	}
}