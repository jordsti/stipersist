#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Persistable.h"
#include <vector>

namespace StiPersist
{
	namespace Container
	{
		class Array2DIterator;
		
		/// \class Array2D
		/// \brief Two Dimension Container with specific dimension
		class Array2D
		{
		public:
			/// \brief Create an empty Array2D
			Array2D();
			
			/// \brief Create a new Array2D with specified dimension
			/// \param m_i_length First Dimension
			/// \param m_j_length Second Dimension
			Array2D(unsigned int m_i_length, unsigned int m_j_length);
			
			/// \brief Get Element at index
			/// \param i First Index
			/// \param j Second Index
			/// \return Element
			Persistable* get(int i, int j);
			
			template <typename T>
			T* get(int i, int j)
			{
				return dynamic_cast<T*>(get(i, j));
			}
			
			/// \brief Insert an element after the specified index
			/// \param i First Index
			/// \param j Second Index
			/// \param element Element
			void insert(int i, int j, Persistable *element);
			
			/// \brief Put an element ot the end of the array
			/// \param First Index
			/// \param element Element
			void append(int i, Persistable *element);
			
			/// \brief Destructor
			virtual ~Array2D();
			
			/// \brief Is the array is empty
			/// \return Empty
			bool isEmpty(void);
			
			/// \brief Get First Dimension
			/// \return I Length
			unsigned int getiLength(void);
			
			/// \brief Get Second Dimension
			/// \return J Length
			unsigned int getjLength(void);
		
			/// \brief Create a new Array2DIterator
			/// \return Iterator
			Array2DIterator* getIterator(void);
		
			/// \brief Set clear data
			/// \param m_clearData Clear Data
			void setClearData(bool m_clearData);
			
			/// \brief Get Clear Data
			/// \return Clear Data
			bool getClearData(void);
		protected:
			/// \brief First Dimension
			unsigned int i_length;
			
			/// \brief Second Dimension
			unsigned int j_length;
			
			/// \brief Wrapped Vector
			std::vector< std::vector<Persistable*> > elements;
			
			/// \brief Clear Data
			bool clearData;
		};
	}
}

#endif