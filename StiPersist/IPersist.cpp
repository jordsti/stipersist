#include "IPersist.h"
#include <iostream>
#include <fstream>
#include "Buffer.h"

namespace StiPersist
{
	IPersist::IPersist()
	{
		populated = false;
	}

	IPersist::~IPersist()
	{
	
	}

	bool IPersist::isPopulated(void)
	{
		return populated;
	}
	
	void IPersist::save(std::string destination)
	{
		std::cout << "Saving..." << std::endl;
		_populateFields();
		
		Data::Buffer buffer = Data::Buffer();
		Data::FieldMarker marker = Data::FieldMarker();

		std::list<Data::Field*>::iterator lit(fields.begin()), lend(fields.end());
		for(;lit!=lend;++lit)
		{
			(*lit)->updateMarker(&marker);
			
			std::cout << "Field : " << (*lit)->getName() << std::endl;
			
			Data::Chunk *c_marker = Data::ChunkFromFieldMarker(&marker);
			Data::Chunk *c_name = (*lit)->getNameChunk();
			Data::Chunk *c_data = (*lit)->getDataChunk();

			buffer.append(c_marker);
			buffer.append(c_name);
			buffer.append(c_data);
		}

		std::ofstream outfile (destination.c_str(), std::ofstream::binary);

		Data::Chunk *main_chunk = buffer.getChunk();

		outfile.write(main_chunk->getData(), main_chunk->getLength());

		outfile.close();

		buffer.clear();
		delete main_chunk;
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
