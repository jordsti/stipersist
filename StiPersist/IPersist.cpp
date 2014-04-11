#include "IPersist.h"
#include <iostream>
#include <fstream>
#include "Buffer.h"
#include "DefaultResolver.h"

namespace StiPersist
{
	IPersist::IPersist()
	{
		populated = false;
		resolver = new DefaultResolver();
	}

	IPersist::~IPersist()
	{
	
	}

	bool IPersist::isPopulated(void)
	{
		return populated;
	}
	
	void IPersist::load(std::string source)
	{
		Data::FieldMarker *marker = new Data::FieldMarker();
		Data::Chunk *nameChunk;
		Data::Chunk *dataChunk;
		
		std::ifstream infile (source.c_str(), std::ifstream::binary | std::ifstream::in);
		infile.seekg(0, infile.beg);
		std::cout <<  "Pos : " << infile.tellg() << std::endl;
		infile.read((char*)marker, sizeof(Data::FieldMarker));
		std::cout << "marker type (read) : " << marker->type << std::endl;
		
		while(marker->type != Data::FT_EOF)
		{	
			char *n_data = new char[marker->nameLength];
			char *f_data = new char[marker->dataLength];
			
			infile.read(n_data, marker->nameLength);
			infile.read(f_data, marker->dataLength);
			
			nameChunk = new Data::Chunk(n_data, marker->nameLength);
			dataChunk = new Data::Chunk(f_data, marker->dataLength);

			Data::Field *field = resolver->getField(marker->type, nameChunk, dataChunk);
			
			if(field != nullptr)
			{
				fields.push_back(field);
				std::cout << field->getName() << std::endl;
			}
			
			delete nameChunk;
			delete dataChunk;
			
			infile.read((char*)marker, sizeof(Data::FieldMarker));
		}
		
		delete marker;
		
		infile.close();
	}
	
	void IPersist::save(std::string destination)
	{
		std::cout << "Saving..." << std::endl;
		_populateFields();
		
		Data::Buffer buffer = Data::Buffer();

		std::list<Data::Field*>::iterator lit(fields.begin()), lend(fields.end());
		for(;lit!=lend;++lit)
		{
			Data::FieldMarker *marker = new Data::FieldMarker();
			Data::Chunk *nameChunk;
			Data::Chunk *dataChunk;
			Data::Chunk *markerChunk;
		
			marker->type = (*lit)->getType();
			std::cout << "Marker type (fields) :" << marker->type << std::endl;
			nameChunk = (*lit)->getNameChunk();
			dataChunk = (*lit)->getDataChunk();
			
			marker->nameLength = nameChunk->getLength();
			marker->dataLength = dataChunk->getLength();
			
			markerChunk = Data::Chunk::FromFieldMarker(marker);
			
			buffer.append(markerChunk);
			buffer.append(nameChunk);
			buffer.append(dataChunk);
		}
		
		Data::FieldMarker *endMarker = new Data::FieldMarker();
		endMarker->type = Data::FT_EOF;
		endMarker->nameLength = 0;
		endMarker->dataLength = 0;
		
		Data::Chunk *endMarkerChunk = Data::Chunk::FromFieldMarker(endMarker);
		
		buffer.append(endMarkerChunk);
		
		std::ofstream outfile (destination.c_str(), std::ofstream::binary);

		/*for(int i=0; i<buffer.getChunkCount(); i++)
		{
			Data::Chunk *chunk = buffer.getChunk(i);
			outfile.write(chunk->getData(), chunk->getLength());
			outfile.flush();
		}*/
		
		Data::Chunk *main_chunk = buffer.getChunk();
		
		outfile.write(main_chunk->getData(), main_chunk->getLength());
		
		outfile.close();

		buffer.clear();

		delete main_chunk;
		delete endMarker;
	}
	
	void IPersist::_populateFields(void)
	{
		if(!populated)
		{
			populateFields();
		}
	}

	void IPersist::_fromFields(void)
	{
		if(!populated)
		{
			fromFields();
			populated = true;
		}
	}

}
