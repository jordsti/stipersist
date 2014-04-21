#ifndef ARRAY2DFIELD_H
#define ARRAY2DFIELD_H

#include "Field.h"
#include "Array2D.h"

namespace StiPersist
{
	namespace Data
	{
		struct Array2DHeader {
			unsigned int ilength;
			unsigned int jlength;
		};
		
		struct Array2DNodeMarker {
			unsigned int length;
		};
	
		class Array2DField
			: public Field
		{
		public:
			Array2DField(std::string m_name);
			virtual ~Array2DField();
			
			Chunk *getDataChunk(void);
			void fromDataChunk(Chunk *dataChunk);
			
			void setArray(Container::Array2D *m_array);
			Container::Array2D *getArray(void);
			
		protected:
			Container::Array2D *array;
		};
	}
}

#endif