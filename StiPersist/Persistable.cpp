#include "Persistable.h"
#include <iostream>
#include <fstream>
#include "Resolver.h"
#include "DefaultResolver.h"
#include "Logger.h"
namespace StiPersist
{
	//static
	Resolver* Persistable::_defaultResolver = new DefaultResolver();

	void Persistable::SetDefaultResolver(Resolver *m_resolver)
	{
		_defaultResolver = m_resolver;
	}
	
	//end static
	Persistable::Persistable()
	{
		populated = false;
		resolver = _defaultResolver;
	}

	Persistable::~Persistable()
	{
	
	}

	bool Persistable::isPopulated(void)
	{
		return populated;
	}
	
	void Persistable::addChild(std::string childName, Persistable *child)
	{
		childs.insert(std::make_pair(childName, child));
	}
	
	void Persistable::addField(Data::Field *field)
	{
		fields.push_back(field);
	}
	
	Data::Field* Persistable::getField(std::string fname)
	{
		std::list<Data::Field*>::iterator lit(fields.begin()), lend(fields.end());
		
		for(;lit!=lend;++lit)
		{
			if((*lit)->getName() == fname)
			{
				return (*lit);
			}
		}
		
		return nullptr;
	}
	
	Persistable* Persistable::getChild(std::string childName)
	{
		return childs[childName];
	}
	
	Data::Buffer* Persistable::getChunkBuffer(void)
	{
		_populateFields();
		
		Data::Buffer *buffer = new Data::Buffer();

		std::list<Data::Field*>::iterator lit(fields.begin()), lend(fields.end());
		for(;lit!=lend;++lit)
		{
			Data::FieldMarker *marker = new Data::FieldMarker();
			Data::Chunk *nameChunk;
			Data::Chunk *dataChunk;
			Data::Chunk *markerChunk;
		
			marker->type = (*lit)->getType();

			nameChunk = (*lit)->getNameChunk();
			dataChunk = (*lit)->getDataChunk();
			
			marker->nameLength = nameChunk->getLength();
			marker->dataLength = dataChunk->getLength();
			
			markerChunk = Data::Chunk::FromFieldMarker(marker);
			
			buffer->append(markerChunk);
			buffer->append(nameChunk);
			buffer->append(dataChunk);
		}
		
		Data::FieldMarker *endMarker = new Data::FieldMarker();
		endMarker->type = Data::FT_EOF;
		endMarker->nameLength = 0;
		endMarker->dataLength = 0;
		
		Data::Chunk *endMarkerChunk = Data::Chunk::FromFieldMarker(endMarker);
		
		buffer->append(endMarkerChunk);
		
		return buffer;
	}
	
	void Persistable::load(std::string source)
	{
		if(childs.size() == 0)
		{
			_populateChilds();
		}
	
		Data::FieldMarker *marker = new Data::FieldMarker();
		Data::Chunk *nameChunk;
		Data::Chunk *dataChunk;
		
		std::ifstream infile (source.c_str(), std::ifstream::binary | std::ifstream::in);
		infile.seekg(0, infile.beg);

		infile.read((char*)marker, sizeof(Data::FieldMarker));
	
		while(marker->type != Data::FT_EOF)
		{	
			char *n_data = new char[marker->nameLength];
			char *f_data = new char[marker->dataLength];
			
			infile.read(n_data, marker->nameLength);
			infile.read(f_data, marker->dataLength);
			
			nameChunk = new Data::Chunk(n_data, marker->nameLength);
			dataChunk = new Data::Chunk(f_data, marker->dataLength);

			if(marker->type == Data::FT_OBJECT)
			{
				resolver->buildObjectField(nameChunk, dataChunk, this);
			}
			else
			{
				Data::Field *field = resolver->getField(marker->type, nameChunk, dataChunk);
				
				if(field != nullptr)
				{
					fields.push_back(field);
					Logger::Message(field->getName());
				}
			}
			
			delete nameChunk;
			delete dataChunk;
			
			infile.read((char*)marker, sizeof(Data::FieldMarker));
		}
		
		delete marker;
		
		infile.close();
		
		_fromFields();
	}
	
	void Persistable::save(std::string destination)
	{
		Data::Buffer *buffer = getChunkBuffer();
		
		std::ofstream outfile (destination.c_str(), std::ofstream::binary);
		
		Data::Chunk *main_chunk = buffer->getChunk();
		
		outfile.write(main_chunk->getData(), main_chunk->getLength());
		
		outfile.close();

		buffer->clear();

		delete main_chunk;
		delete buffer;
	}
	
	void Persistable::_populateChilds(void)
	{
		std::map<std::string, Persistable*>::iterator lit(childs.begin()), lend(childs.end());
		for(;lit!=lend;++lit)
		{
			std::string name = lit->first;
			Persistable *child = lit->second;
			
			Data::ObjectField *ofield = new Data::ObjectField(name);
			ofield->setObject(child);
			
			fields.push_back(ofield);
			
		}
	}
	
	void Persistable::_populateFields(void)
	{
		if(!populated)
		{
			populateFields();
			_populateChilds();
		}
	}

	void Persistable::_fromFields(void)
	{
		if(!populated)
		{
			fromFields();
			populated = true;
		}
	}

}
