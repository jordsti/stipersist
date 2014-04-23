#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H

#include "Array.h"
#include "Iterator.h"

namespace StiPersist
{
	namespace Container
	{
		/// \class ArrayIterator
		/// \brief Iterate over a single dimension array
		class ArrayIterator :
			public Iterator
		{
		public:
			/// \brief Constructor
			/// \param m_array Array Pointer
			ArrayIterator(Array *m_array);
			
			/// \brief Destructor
			virtual ~ArrayIterator();
			
			/// \brief Has a next element
			/// \return has next
			bool hasNext(void);
			
			/// \brief Move to the next element
			/// \return has next
			bool moveNext(void);
			
			/// \brief Get current element
			/// \return Element
			Persistable *getElement(void);
			
			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(getElement());
			}
			
			/// \brief Get the iterator type
			/// \return Type
			IteratorType getType(void);
			
			/// \brief Get current index
			/// \return Index
			unsigned int getIndex(void);
			
		protected:
			/// \brief Started
			bool started;
			
			/// \brief Current index
			unsigned int index;
			
			/// \brief Array
			Array *array;
		};
	}
}

#endif