#ifndef FIELD_H
#define FIELD_H

#include "Chunk.h"
#include <string>

namespace StiPersist
{
	namespace Data
	{
		struct FieldMarker {
			int type;
		};
	
		enum FieldType {
			FT_UNDEFINED = -1024,
			FT_INTEGER = 1,
			FT_STRING = 2
		};
	
		class Field
		{
		public:
			virtual ~Field();
			
			Chunk* getNameChunk(void);
			virtual Chunk* getDataChunk(void) = 0;
			
			int getType(void);
			std::string getName(void);
			FieldMarker* getMarker(void);
			void updateMarker(FieldMarker *marker);
		protected:
			Field();
			Field(std::string m_name, int m_type);
			std::string name;
			int type;
		};
	}
}

#endif