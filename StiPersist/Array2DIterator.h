#ifndef ARRAY2DITERATOR_H
#define ARRAY2DITERATOR_H

#include "Iterator.h"
#include "Array2D.h"

namespace StiPersist
{
	namespace Container
	{
		class Array2DIterator :
			public Iterator
		{
		public:
			Array2DIterator(Array2D *m_array);
			
			virtual ~Array2DIterator();
			
			bool hasNext(void);
			bool moveNext(void);
			
			IPersist* getElement(void);
			
			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(getElement());
			}
			
			
			IteratorType getType(void);
			
			unsigned int getI(void);
			unsigned int getJ(void);
		
		private:
			bool started;
			unsigned int current_i;
			unsigned int current_j;
			Array2D *array;
		};
	}
}

#endif