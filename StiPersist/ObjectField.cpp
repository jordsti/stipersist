#include "ObjectField.h"
#include "Buffer.h"
namespace StiPersist
{

	namespace Data
	{
		ObjectField::ObjectField(std::string m_name) :
			Field(m_name, FT_OBJECT)
		{
			object = nullptr;
		}
		
		ObjectField::~ObjectField() {}
		
		Chunk* ObjectField::getDataChunk(void)
		{
			Buffer *buffer = object->getChunkBuffer();
			Chunk *chunk = buffer->getChunk();
			buffer->clear();
			delete buffer;
			return chunk;
		}
		
		void ObjectField::setObject(IPersist *m_object)
		{
			object = m_object;
		}
		
		IPersist* ObjectField::getObject(void)
		{
			return object;
		}
	}

}