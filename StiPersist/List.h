#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

namespace StiPersist
{
	namespace Container
	{
		class ListIterator;

		class List
		{
		public:
			List();
			virtual ~List();

			ListNode* getFirst(void);
			ListNode* get(int index);

			void clear(void);

			void append(ListNode *node);
			void append(Persistable *element);
			void append(List *list);

			void insert(int index, ListNode *node);
			void insert(int index, Persistable *element);
			void insert(int index, List *list);

			ListNode* operator[](unsigned int index);
			
			void remove(ListNode *node);
			ListNode* remove(Persistable *element);
			ListNode* remove(int index);

			ListNode* pop(void);

			ListNode* getLast(void);
			int size(void);

			bool isEmpty(void);

			void setClearMemory(bool m_clearMemory);
			bool getClearMemory(void);

			ListIterator* getIterator(void);

		private:
			ListNode *first;
			bool clearMemory;
		};
	}

}

#endif
