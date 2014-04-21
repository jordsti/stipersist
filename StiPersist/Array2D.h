#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "IPersist.h"
#include <vector>

namespace StiPersist
{
	namespace Container
	{
		class Array2DIterator;
		
		class Array2D
		{
		public:
			Array2D();
			Array2D(unsigned int m_i_length, unsigned int m_j_length);
			
			IPersist* get(int i, int j);
			
			template <typename T>
			T* get(int i, int j)
			{
				return dynamic_cast<T*>(get(i, j));
			}
			
			void insert(int i, int j, IPersist *element);
			
			void append(int i, IPersist *element);
			
			virtual ~Array2D();
			
			bool isEmpty(void);
			
			unsigned int getiLength(void);
			unsigned int getjLength(void);
		
			Array2DIterator* getIterator(void);
		
			void setClearData(bool m_clearData);
			bool getClearData(void);
		protected:
			unsigned int i_length;
			unsigned int j_length;
			std::vector< std::vector<IPersist*> > elements;
			bool clearData;
		};
	}
}

#endif