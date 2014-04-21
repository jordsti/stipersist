#include "ArrayIterator.h"

namespace StiPersist
{
	namespace Container
	{
		ArrayIterator::ArrayIterator(Array *m_array)
		{
			array = m_array;
			index = 0;
			started = false;
		}
		
		ArrayIterator::~ArrayIterator() {}
		
		bool ArrayIterator::hasNext(void)
		{
			return (index < array->getLength());
		}
		
		bool ArrayIterator::moveNext(void)
		{
			if(started)
			{
				index++;
				
				if(index < array->getLength())
				{
					return true;
				}
				else
				{
					index--;
					return false;
				}
			
			}
			else
			{
				if(!array->isEmpty())
				{
					started = true;
					return true;
				}
				
				return false;
			}
		}
		
		unsigned int ArrayIterator::getIndex(void)
		{
			return index;
		}
		
		IPersist* ArrayIterator::getElement(void)
		{
			return array->get(index);
		}
		
		IteratorType ArrayIterator::getType(void)
		{
			return IT_ARRAY;
		}
	}
}