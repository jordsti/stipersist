#ifndef UINTEGERFIELD_H
#define UINTEGERFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		struct UIntegerStruct
		{
			unsigned int value;
		};
		
		class UIntegerField :
			public Field
		{
		public:
			UIntegerField(std::string m_name);
			virtual ~UIntegerField();
			
			Chunk* getDataChunk(void);
			void fromDataChunk(Chunk *dataChunk);
			
			void setUInteger(unsigned int m_value);
			unsigned int getUInteger(void);
			
		protected:
			unsigned int value;
		};
	}
}

#endif