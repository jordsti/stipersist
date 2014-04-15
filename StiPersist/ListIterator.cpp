#include "ListIterator.h"

namespace StiPersist
{
	namespace Container
	{
		ListIterator::ListIterator(List *m_list)
		{
			list = m_list;
			current = nullptr;
			started = false;
		}
		
		ListIterator::~ListIterator() {}
		
		bool ListIterator::hasNext(void)
		{
			if(current != nullptr)
			{
				return current->hasNext();
			}

			return false;
		}
		
		bool ListIterator::moveNext(void)
		{
			if(!started)
			{
				started = true;
				ListNode *node = list->getFirst();
				
				if(node != nullptr)
				{
					current = node;
					return true;
				}
				else
				{
					return false;
				}
			}
		
			if(current != nullptr && current->hasNext())
			{
				current = current->getNext();
				return true;
			}
			
			return false;
		}
		
		IPersist* ListIterator::getElement(void)
		{
			if(current != nullptr)
			{
				return current->getElement();
			}
			
			return nullptr;
		}
		
		IteratorType ListIterator::getType(void)
		{
			return IT_LIST;
		}

	}
}