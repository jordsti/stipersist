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
			ListNode(IPersist *m_element);
			ListNode(IPersist *m_element, ListNode *m_next);
			
			void setElement(IPersist *m_element);
			IPersist* getElement(void);
			
			void setNext(ListNode *m_next);
			ListNode* getNext(void);
		
			bool hasNext(void);
			bool isEmpty(void);
			
			bool getClearMemory(void);
			void setClearMemory(bool m_clearMemory);
			
		private:
			ListNode *next;
			IPersist *element;
			bool clearMemory;
		};
	
	}

}

#endif