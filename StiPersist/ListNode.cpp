#include "ListNode.h"

namespace StiPersist
{

	namespace Container
	{
	
		ListNode::ListNode()
		{
			element = nullptr;
			next = nullptr;
		}
		
		ListNode::ListNode(IPersist *m_element)
		{
			element = m_element;
			next = nullptr;
		}
		
		ListNode::ListNode(IPersist *m_element, ListNode *m_next)
		{
			element = m_element;
			next = m_next;
		}
		
		void ListNode::setElement(IPersist *m_element)
		{
			element = m_element;
		}
		
		IPersist* ListNode::getElement(void)
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
	}

}