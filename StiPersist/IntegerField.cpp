#include "IntegerField.h"

namespace StiPersist
{
	namespace Data
	{
		const int IntegerField::INTEGER_LENGTH = 4;
	
		IntegerField::IntegerField(std::string m_name) :
			Field(m_name, FT_INTEGER)
		{
			integer = 0;
		}
		
		IntegerField::~IntegerField() {}
		
		Chunk* IntegerField::getDataChunk(void)
		{
			char* data = new char[INTEGER_LENGTH];
			
			data[0] = integer & 0x000000ff;
			data[1] = (integer & 0x0000ff00) >> 8;
			data[2] = (integer & 0x00ff0000) >> 16;
			data[3] = (integer & 0xff000000) >> 24;
			
			Chunk *chunk = new Chunk(data, INTEGER_LENGTH);
			return chunk;
		}
		
		void IntegerField::setInteger(int m_integer)
		{
			integer = m_integer;
		}
		
		int IntegerField::getInteger(void)
		{
			return integer;
		}
	}
}