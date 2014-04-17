#include "RawField.h"

namespace StiPersist
{
	namespace Data
	{
		RawField::RawField(std::string m_name)
			: Field(m_name, FT_RAW)
		{
			data = 0;
			length = 0;
		}
		
		RawField::~RawField() {}
		
		Chunk* RawField::getDataChunk(void)
		{
			return new Chunk(data, length);
		}
		
		void RawField::fromDataChunk(Chunk *dataChunk)
		{
			data = dataChunk->getData();
			length = dataChunk->getLength();
		}
		
		void RawField::setData(char *m_data, unsigned int m_length)
		{
			data = m_data;
			length = m_length;
		}
		
		unsigned int RawField::getLength(void)
		{
			return length;
		}
		
		char* RawField::getData(void)
		{
			return data;
		}
	}
}