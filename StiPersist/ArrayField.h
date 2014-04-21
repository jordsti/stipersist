#ifndef ARRAYFIELD_H
#define ARRAYFIELD_H

#include "Field.h"
#include "Array.h"

namespace StiPersist
{
	namespace Data
	{
		struct ArrayHeader
		{
			unsigned int length;
		};
		
		struct ArrayNodeMarker
		{
			unsigned int length;
		};
	
		class ArrayField :
			public Field
		{
		public:
			ArrayField(std::string m_name);
			virtual ~ArrayField();
			
			Chunk* getDataChunk(void);
			void fromDataChunk(Chunk *dataChunk);
			
			void setArray(Container::Array *m_array);
			Container::Array* getArray(void);
			
		private:
			Container::Array *array;
		};
	}
}

#endif