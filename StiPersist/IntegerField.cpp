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
			char* data = new char[sizeof(IntegerStruct)];
			
			IntegerStruct *istruct = new IntegerStruct();
			
			istruct->value = integer;
			
			data = reinterpret_cast<char*>(istruct);
			
			Chunk *chunk = new Chunk(data, INTEGER_LENGTH);
			return chunk;
		}
		
		void IntegerField::fromDataChunk(Chunk *dataChunk)
		{
			char *data = dataChunk->getData();
			
			IntegerStruct *istruct = reinterpret_cast<IntegerStruct*>(data);
			
			integer = istruct->value;
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