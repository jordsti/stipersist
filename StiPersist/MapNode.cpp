#include "MapNode.h"

namespace StiPersist
{
	namespace Container
	{
		MapNode::MapNode() : INode()
		{
			key = "";
			element = nullptr;
			next = nullptr;
		}
		
		MapNode::MapNode(std::string m_key, IPersist *m_element) : INode()
		{
			key = m_key;
			element = m_element;
			next = nullptr;
		}
		
		MapNode::MapNode(std::string m_key, IPersist *m_element, MapNode *m_next) : INode()
		{
			key = m_key;
			element = m_element;
			next = m_next;
		}
		
		MapNode::~MapNode()
		{
			//todo
		}
		
		void MapNode::setNext(MapNode *m_next)
		{
			next = m_next;
		}
		
		MapNode* MapNode::getNext(void)
		{
			return next;
		}
		
		void MapNode::setElement(IPersist *m_element)
		{
			element = m_element;
		}
		
		IPersist* MapNode::getElement(void)
		{
			return element;
		}
		
		void MapNode::setKey(std::string m_key)
		{
			key = m_key;
		}
		
		std::string MapNode::getKey(void)
		{
			return key;
		}
		
		bool MapNode::hasNext(void)
		{
			return (next != nullptr);
		}
		
		bool MapNode::isEmpty(void)
		{
			return (element == nullptr);
		}
	}
}