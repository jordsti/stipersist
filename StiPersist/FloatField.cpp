#include "FloatField.h"

namespace StiPersist
{

	namespace Data
	{
		FloatField::FloatField(std::string m_name) : 
			Field(m_name, FT_FLOAT)
		{
			value = 0;
		}
		
		FloatField::~FloatField()
		{
		
		}
		
		Chunk* FloatField::getDataChunk()
		{
			unsigned int length = sizeof(FloatStruct);
			FloatStruct *str = new FloatStruct();
			str->value = value;
			char *data = new char[length];
			data = reinterpret_cast<char*>(str);
			
			Chunk *chunk = new Chunk(data, length);
			return chunk;
		}

		void FloatField::setFloat(float m_value)
		{
			value = m_value;
		}
		
		float FloatField::getFloat(void)
		{
			return value;
		}
	}

}