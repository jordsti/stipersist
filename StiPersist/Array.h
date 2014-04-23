#ifndef ARRAY_H
#define ARRAY_H

#include "Persistable.h"
#include <vector>

namespace StiPersist
{
	namespace Container
	{
		class ArrayIterator;
	
		/// \class Array
		/// \brief Container with fixed length, must be all populated
		class Array
		{
		public:
			/// \brief Empty Array
			Array();
			
			/// \brief Array with specified capacity
			/// \param m_length Capacity
			Array(unsigned int m_length);
			
			/// \brief Destructor
			virtual ~Array();
			
			/// \brief Insert an element at index
			/// \param i Index
			/// \param element Element
			void insert(int i, Persistable *element);
			
			/// \brief Append an element to the end of the array
			/// \param element Element
			void append(Persistable *element);
			
			/// \brief Get Element at index
			/// \param i Index
			/// \return Element
			Persistable* get(int i);
			
			Persistable* operator[](unsigned int index);
			
			template <typename T>
			T* get(int i)
			{
				return dynamic_cast<T*>(get(i));
			}
			
			/// \brief Get Array Length
			/// \return Length
			unsigned int getLength(void);
			
			/// \brief Create a new Array Iterator
			/// \return Iterator
			ArrayIterator* getIterator(void);
			
			/// \brief If the array is empty
			/// \param Empty
			bool isEmpty(void);
			
		protected:
			/// \brief Capacity
			unsigned int length;
			
			/// \brief Wrapped Vector
			std::vector<Persistable*> elements;
		};
	}
}

#endif