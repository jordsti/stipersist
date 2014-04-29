#include "ObjectField.h"
#include "Buffer.h"
#include "Logger.h"
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

		void ObjectField::fromDataChunk(Chunk *dataChunk)
		{
			Logger::Warning("ObjectField::fromDataChunk is not supposed to be called !");
		}

		Chunk* ObjectField::getDataChunk(void)
		{
			Buffer *buffer = object->getChunkBuffer();
			Chunk *chunk = buffer->getChunk();
			//buffer->clear(); not needed now, autoClear
			delete buffer;
			return chunk;
		}

		void ObjectField::setObject(Persistable *m_object)
		{
			object = m_object;
		}

		Persistable* ObjectField::getObject(void)
		{
			return object;
		}
	}

}
