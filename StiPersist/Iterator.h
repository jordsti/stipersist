#ifndef ITERATOR_H
#define ITERATOR_H

#include "IPersist.h"

namespace StiPersist
{
	namespace Container
	{
		enum IteratorType {
			IT_NONE,
			IT_LIST,
			IT_MAP
		};
	
		class Iterator
		{
		public:			
			virtual bool hasNext(void) = 0;
			virtual bool moveNext(void) = 0;
			
			virtual IPersist* getElement(void) = 0;
			
			virtual IteratorType getType(void) = 0;
		};
	}
}

#endif