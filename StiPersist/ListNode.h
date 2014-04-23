#ifndef LISTNODE_H
#define LISTNODE_H

#include "INode.h"

namespace StiPersist
{

	namespace Container
	{

		class ListNode :
			public INode
		{
		public:
			ListNode();
			ListNode(Persistable *m_element);
			ListNode(Persistable *m_element, ListNode *m_next);

			void setElement(Persistable *m_element);
			Persistable* getElement(void);

			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(element);
			}

			void setNext(ListNode *m_next);
			ListNode* getNext(void);

			bool hasNext(void);
			bool isEmpty(void);

			bool getClearMemory(void);
			void setClearMemory(bool m_clearMemory);

		private:
			ListNode *next;
			Persistable *element;
			bool clearMemory;
		};

	}

}

#endif
