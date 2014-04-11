#ifndef FLOATFIELD_H
#define FLOATFIELD_H

#include "Field.h"

namespace StiPersist
{

	namespace Data
	{
		struct FloatStruct
		{
			float value;
		};
	
		class FloatField : 
			public Field
		{
		public:
			FloatField(std::string m_name);
			virtual ~FloatField();
			
			Chunk* getDataChunk();
		
			void setFloat(float m_value);
			float getFloat(void);
		protected:
			float value;
		};
	
	}

}

#endif