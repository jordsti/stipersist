#include "Array2DIterator.h"

namespace StiPersist
{
	namespace Container
	{
	
		Array2DIterator::Array2DIterator(Array2D *m_array)
		{
			started = false;
			current_i = 0;
			current_j = 0;
			array = m_array;
		}
		
		Array2DIterator::~Array2DIterator() {}
		
		bool Array2DIterator::hasNext(void)
		{
			if(!started)
			{
				return !(array->isEmpty());
			}
		}
		
		bool Array2DIterator::moveNext(void)
		{
			if(started)
			{
				current_j++;
				
				if(current_j == array->getjLength())
				{
					//current_i = 0;
					current_i++;
					
					if(current_i == array->getiLength())
					{
						return false;
					}
					else
					{
						current_j = 0;
						return true;
					}
					
				}
				else
				{
					return true;
				}
				
			}
			else
			{
				started = true;
				
				return true;
			}
		}
		
		Persistable* Array2DIterator::getElement(void)
		{
			return array->get(current_i, current_j);
		}
		
		IteratorType Array2DIterator::getType(void)
		{
			return IT_ARRAY2D;
		}
		
		unsigned int Array2DIterator::getI(void)
		{
			return current_i;
		}
		
		unsigned int Array2DIterator::getJ(void)
		{
			return current_j;
		}

	}
}