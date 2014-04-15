#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "Iterator.h"
#include "List.h"

namespace StiPersist
{
	namespace Container
	{
		class ListIterator :
			public Iterator
		{
		public:
			ListIterator(List *m_list);
			virtual ~ListIterator();
			
			bool hasNext(void);
			bool moveNext(void);
			
			IPersist* getElement(void);
			IteratorType getType(void);
		private:
			List *list;
			ListNode *current;
			bool started;
		};
	}
}

#endif