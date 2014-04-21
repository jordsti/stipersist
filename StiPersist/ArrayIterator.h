#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H

#include "Array.h"
#include "Iterator.h"

namespace StiPersist
{
	namespace Container
	{
		class ArrayIterator :
			public Iterator
		{
		public:
			ArrayIterator(Array *m_array);
			virtual ~ArrayIterator();
			
			bool hasNext(void);
			bool moveNext(void);
			
			IPersist *getElement(void);
			
			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(getElement());
			}
			
			IteratorType getType(void);
			
			unsigned int getIndex(void);
			
		protected:
			bool started;
			unsigned int index;
			Array *array;
		};
	}
}

#endif