#ifndef ARRAY2DITERATOR_H
#define ARRAY2DITERATOR_H

#include "Iterator.h"
#include "Array2D.h"

namespace StiPersist
{
	namespace Container
	{
		/// \class Array2DIterator
		/// \brief Iterate over a Array2D, going over second index and after first index, ( j -> i )
		class Array2DIterator :
			public Iterator
		{
		public:
			/// \brief Constructor
			/// \param m_array Array2D to iterate
			Array2DIterator(Array2D *m_array);
			
			/// \brief Destructor
			virtual ~Array2DIterator();
			
			/// \brief Has a next element
			/// \return Has Next
			bool hasNext(void);
			
			/// \brief Move to the next element
			/// \return Has Next
			bool moveNext(void);
			
			/// \brief Get Current Element
			/// \return Element
			IPersist* getElement(void);
			
			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(getElement());
			}
			
			/// \brief Get Iterator type
			/// \return Type
			IteratorType getType(void);
			
			/// \brief Get First Index
			/// \return First Index
			unsigned int getI(void);
			
			/// \brief Get Second Index
			/// \return Second Index
			unsigned int getJ(void);
		
		private:
			/// \brief Started
			bool started;
			
			/// \brief Current i
			unsigned int current_i;
			
			/// \brief Current j
			unsigned int current_j;
			
			/// \brief Array2D to iterate
			Array2D *array;
		};
	}
}

#endif