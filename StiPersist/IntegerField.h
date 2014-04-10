#ifndef INTEGERFIELD_H
#define INTEGERFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		class IntegerField :
			public Field
		{
		public:
			static const int INTEGER_LENGTH;
			IntegerField(std::string m_name);
			virtual ~IntegerField();
			
			Chunk* getDataChunk(void);
			
			void setInteger(int m_integer);
			int getInteger(void);
			
		protected:
			int integer;
		};
	}
}

#endif