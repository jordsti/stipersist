#ifndef ARRAY_H
#define ARRAY_H

#include "IPersist.h"
#include <vector>

namespace StiPersist
{
	namespace Container
	{
		class ArrayIterator;
	
		class Array
		{
		public:
			Array();
			Array(unsigned int m_length);
			
			void insert(int i, IPersist *element);
			void append(IPersist *element);
			
			IPersist* get(int i);
			
			template <typename T>
			T* get(int i)
			{
				return dynamic_cast<T*>(get(i));
			}
			
			unsigned int getLength(void);
			
			ArrayIterator* getIterator(void);
			
			bool isEmpty(void);
			
		protected:
			unsigned int length;
			std::vector<IPersist*> elements;
		};
	}
}

#endif