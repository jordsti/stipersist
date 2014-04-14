#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

namespace StiPersist
{
	namespace Container
	{
		class List
		{
		public:
			List();
			virtual ~List();
			
			ListNode* getFirst(void);
			ListNode* get(int index);
			
			void clear(void);
			
			void append(ListNode *node);
			void append(IPersist *element);
			void append(List *list);
			
			void insert(int index, ListNode *node);
			void insert(int index, IPersist *element);
			void insert(int index, List *list);
			
			void remove(ListNode *node);
			ListNode* remove(IPersist *element);
			ListNode* remove(int index);
			
			ListNode* pop(void);
			
			ListNode* getLast(void);
			int size(void);
			
			bool isEmpty(void);
			
			void setClearMemory(bool m_clearMemory);
			bool getClearMemory(void);
		private:
			ListNode *first;
			bool clearMemory;
		};
	}

}

#endif