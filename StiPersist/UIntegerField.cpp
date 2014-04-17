#include "UIntegerField.h"

namespace StiPersist
{
	namespace Data
	{
		UIntegerField::UIntegerField(std::string m_name) :
			Field(m_name, FT_UINTEGER)
		{
			value = 0;
		}
		
		UIntegerField::~UIntegerField() {}
		
		Chunk* UIntegerField::getDataChunk(void)
		{
			UIntegerStruct *uistruct = new UIntegerStruct();
			uistruct->value = value;
			
			unsigned int length = sizeof(UIntegerStruct);
			char *data = reinterpret_cast<char*>(uistruct);
			
			Chunk *chunk = new Chunk(data, length);
			return chunk;
		}
		
		void UIntegerField::fromDataChunk(Chunk *dataChunk)
		{
			UIntegerStruct *uistruct = reinterpret_cast<UIntegerStruct*>(dataChunk);
			value = uistruct->value;
		}
		
		void UIntegerField::setUInteger(unsigned int m_value)
		{
			value = m_value;
		}
		
		unsigned int UIntegerField::getUInteger(void)
		{
			return value;
		}
	
	}
}