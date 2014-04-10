#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		Field::Field()
		{
			name = "none";
			type = FT_UNDEFINED;
		}
		
		Field::Field(std::string m_name, int m_type)
		{
			name = m_name;
			type = m_type;
		}
		
		Field::~Field()
		{
			//nothing to do here...
		}
	
		Chunk* Field::getNameChunk(void)
		{
			return ChunkFromString(name);
		}
		
		FieldMarker* Field::getMarker(void)
		{
			FieldMarker *marker = new FieldMarker();
			marker->type = type;
			return marker;
		}
		
		void Field::updateMarker(FieldMarker *marker)
		{
			marker->type = type;
		}
		
		int Field::getType(void)
		{
			return type;
		}
		
		std::string Field::getName(void)
		{
			return name;
		}
	}
}