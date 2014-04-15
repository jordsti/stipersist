#include "List.h"
#include "ListIterator.h"

namespace StiPersist
{
	namespace Container
	{
		List::List()
		{
			first = nullptr;
			clearMemory = true;
		}
		
		List::~List()
		{
			//to be analyzed
		}
		
		void List::clear(void)
		{
			first = nullptr;
			//must add an attribute clearMemory to delete all node
		}
		
		ListNode* List::getFirst(void)
		{
			return first;
		}
		
		ListNode* List::get(int index)
		{
			if(index == 0)
			{
				return first;
			}
			else
			{
				int ni = 0;
				ListNode *current = first;
				
				while(current != nullptr)
				{
					if(index == ni)
					{
						return current;
					}
					
					ni++;
					
					if(current->getNext() == nullptr)
					{
						return current;
					}
					
					current = current->getNext();
				}
			}
		}
		
		void List::append(ListNode *node)
		{
			if (first == nullptr)
			{
				first = node;
			}
			else
			{
				ListNode* last = getLast();
				last->setNext(node);
			}
		}
		
		void List::append(IPersist *element)
		{
			ListNode *node = new ListNode(element);
			append(node);
		}
		
		void List::append(List *list)
		{
			ListNode *last = getLast();
			ListNode *nlist = list->getFirst();
			
			if(nlist != nullptr)
			{
				last->setNext(nlist);
			}
		}
		
		void List::insert(int index, ListNode *node)
		{
			ListNode *before = get(index);
			ListNode *after = before->getNext();
			
			before->setNext(node);
			node->setNext(after);
		}
		
		void List::insert(int index, IPersist *element)
		{
			ListNode *before = get(index);
			ListNode *after = before->getNext();
			
			ListNode *n_node = new ListNode(element);
			
			before->setNext(n_node);
			n_node->setNext(after);
		}
		
		void List::insert(int index, List *list)
		{
			ListNode *before = get(index);
			ListNode *after = before->getNext();
			
			before->setNext(list->getFirst());
			list->getLast()->setNext(after);
		}
		
		void List::remove(ListNode *node)
		{
			ListNode *current = first;
			ListNode *prev = nullptr;

			while(current != nullptr)
			{
				if(current == node)
				{
					if(current == first)
					{
						first = nullptr;
						break;
					}
					else
					{
						prev->setNext(current->getNext());
						break;
					}
				}
			
				prev = current;
				current = current->getNext();
			}
		}
		
		ListNode* List::remove(IPersist *element)
		{
			ListNode *current = first;
			ListNode *prev = nullptr;

			while(current != nullptr)
			{
				if(current->getElement() == element)
				{
					if(current == first)
					{
						first = nullptr;
						return current;
					}
					else
					{
						prev->setNext(current->getNext());
						return current;
					}
				}
			
				prev = current;
				current = current->getNext();
			}
		}
		
		ListNode* List::remove(int index)
		{
			ListNode *item = get(index);
			
			remove(item);
			
			return item;
		}
			
		ListNode* List::pop(void)
		{
			ListNode *last = getLast();
			ListNode *current = first;
			
			while(current != nullptr && current->getNext() != nullptr)
			{
				if(last == current->getNext())
				{
					current->setNext(nullptr);
					return last;
				}
				
				current = current->getNext();
			}
			
			return last;
		}
		
		ListNode* List::getLast(void)
		{
			ListNode *current = first;
			
			if(first == nullptr)
			{
				return first;
			}
			else
			{
				while(current->getNext() != nullptr)
				{
					current = current->getNext();
				}
				
				return current;
			}
			
		}
		
		int List::size(void)
		{
			int count = 0;
			
			ListNode *current = first;
			
			if(first == nullptr)
			{
				return count;
			}
			else
			{
				count++;
				
				while(current->getNext() != nullptr)
				{
					current = current->getNext();
					count++;
				}
				
				return count;
			}
		}
		
		bool List::isEmpty(void)
		{
			return (first == nullptr);
		}
		
					
		void List::setClearMemory(bool m_clearMemory)
		{
			clearMemory = m_clearMemory;
		}
		
		bool List::getClearMemory(void)
		{
			return clearMemory;
		}
		
		ListIterator* List::getIterator(void)
		{
			ListIterator *iterator = new ListIterator(this);
			return iterator;
		}
		
	}
}