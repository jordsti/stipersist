#ifndef ITERATOR_H
#define ITERATOR_H

#include "Persistable.h"

namespace StiPersist
{
	namespace Container
	{
		enum IteratorType {
			IT_NONE,
			IT_LIST,
			IT_MAP,
			IT_ARRAY2D,
			IT_ARRAY
		};
	
		class Iterator
		{
		public:			
			virtual bool hasNext(void) = 0;
			virtual bool moveNext(void) = 0;
			
			virtual Persistable* getElement(void) = 0;
			
			virtual IteratorType getType(void) = 0;
		};
	}
}

#endif