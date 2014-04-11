#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include "Field.h"
#include "IPersist.h"

namespace StiPersist
{

	namespace Data
	{
		class ObjectField :
			public Field
		{
		public:
			ObjectField(std::string m_name);
			virtual ~ObjectField();
			
			Chunk* getDataChunk(void);
			
			void setObject(IPersist *m_object);
			IPersist* getObject(void);
			
		protected:
			IPersist *object;
		};
	}

}

#endif