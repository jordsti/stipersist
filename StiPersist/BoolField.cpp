#include "BoolField.h"

namespace StiPersist
{
	namespace Data
	{
		/*const char BF_TRUE = 0x01;
		const char BF_FALSE = 0x00;*/
	
		BoolField::BoolField(std::string m_name)
			: Field(m_name, FT_BOOL)
		{
			value =  false;
		}
		
		BoolField::~BoolField() {}
			
		char BoolField::GetCharValue(bool value)
		{
			if(value)
			{
				return BF_TRUE;
			}
			else
			{
				return BF_FALSE;
			}
		}
		
		bool BoolField::GetBoolValue(char value)
		{
			if(value == BF_TRUE)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
			
		Chunk* BoolField::getDataChunk(void)
		{
			char *m_data = new char[1];
			
			m_data[0] = GetCharValue(value);
			
			Chunk *chunk = new Chunk(m_data, 1);
			
			return chunk;
		}
		
		void BoolField::fromDataChunk(Chunk *dataChunk)
		{
			value = GetBoolValue(dataChunk->getData()[0]);
		}
			
		void BoolField::setBool(bool m_value)
		{
			value = m_value;
		}
		
		bool BoolField::getBool(void)
		{
			return value;
		}
	}

}