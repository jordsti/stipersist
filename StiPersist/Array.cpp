#include "Array.h"
#include "Logger.h"
#include "ArrayIterator.h"

namespace StiPersist
{
	namespace Container
	{
		Array::Array()
		{
			length = 0;
		}
		
		Array::Array(unsigned int m_length)
		{
			length = m_length;
		}
		
		Array::~Array()
		{
		
		}
		
		Persistable* Array::operator[](unsigned int index)
		{
			return get(index);
		}
		
		void Array::insert(int i, Persistable *element)
		{
			if(elements.size() < length)
			{
				std::vector<Persistable*>::iterator it (elements.begin());
				
				elements.insert(it, i, element);
			}
			else
			{
				Logger::Error("Array out of range ->insert(i ,element)");
			}
		}
		
		void Array::append(Persistable *element)
		{
			if(elements.size() < length)
			{
				elements.push_back(element);
			}
			else
			{
				Logger::Error("Array out of range ->append(element)");
			}
		}
		
		Persistable* Array::get(int i)
		{
			if(i < length)
			{
				return elements[i];
			}
			else
			{
				Logger::Error("Array out of range ->get([i])");
			}
		}
		
		unsigned int Array::getLength(void)
		{
			return length;
		}
		
		ArrayIterator* Array::getIterator(void)
		{
			return new ArrayIterator(this);
		}
		
		bool Array::isEmpty(void)
		{
			return (length == 0);
		}
			
	}
}