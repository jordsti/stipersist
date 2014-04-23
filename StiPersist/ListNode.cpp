#include "ListNode.h"

namespace StiPersist
{

	namespace Container
	{

		ListNode::ListNode() : INode()
		{
			element = nullptr;
			next = nullptr;
			clearMemory = true;
		}

		ListNode::ListNode(Persistable *m_element) : INode()
		{
			element = m_element;
			next = nullptr;
			clearMemory = true;
		}

		ListNode::ListNode(Persistable *m_element, ListNode *m_next) : INode()
		{
			element = m_element;
			next = m_next;
			clearMemory = true;
		}

		void ListNode::setElement(Persistable *m_element)
		{
			element = m_element;
		}

		Persistable* ListNode::getElement(void)
		{
			return element;
		}

		void ListNode::setNext(ListNode *m_next)
		{
			next = m_next;
		}

		ListNode* ListNode::getNext(void)
		{
			return next;
		}

		bool ListNode::hasNext(void)
		{
			return (next != nullptr);
		}

		bool ListNode::isEmpty(void)
		{
			return (element == nullptr);
		}


		bool ListNode::getClearMemory(void)
		{
			return clearMemory;
		}

		void ListNode::setClearMemory(bool m_clearMemory)
		{
			clearMemory = m_clearMemory;
		}
	}

}
