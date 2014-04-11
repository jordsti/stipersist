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
			int nameLength;
			int dataLength;
		};
	
		enum FieldType {
			//undefined..
			FT_UNDEFINED = -1024,
			//numeric fields
			FT_INTEGER = 1,
			FT_FLOAT = 2,
			//string fields
			FT_STRING = 1024,
			//complex field
			FT_OBJECT = 2048,
			//End of file
			FT_EOF = 4096
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