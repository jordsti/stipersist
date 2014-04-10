#include "StringField.h"

namespace StiPersist
{
	namespace Data
	{
		StringField::StringField(std::string m_name) : 
			Field(m_name, FT_STRING)
		{
			text = "";
		}
		
		StringField::~StringField() {}
		
		std::string StringField::getText(void)
		{
			return text;
		}
		
		void StringField::setText(std::string m_text)
		{
			text = m_text;
		}
		
		Chunk* StringField::getDataChunk(void)
		{
			return ChunkFromString(text);
		}
	}
}