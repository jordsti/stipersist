#ifndef DEFAULTRESOLVER_H
#define DEFAULTRESOLVER_H

#include "Resolver.h"

namespace StiPersist
{
	class IPersist;

	/// \class DefaultResolver
	/// \brief Default implementation of the Resolver. Used by IPersist
	class DefaultResolver :
		public Resolver
	{
	public:
		/// \brief Constructor
		DefaultResolver();
		
		/// \brief Destructor
		virtual ~DefaultResolver();
		
		/// \brief Create a Field from Chunks
		/// \param type Type ID
		/// \param nameChunk Chunk of the Field Name
		/// \param dataChunk Chunk of the Field Data
		/// \return Generated Field Pointer
		Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk);
		
		/// \brief Build a Object Field from Chunks
		/// \param nameChunk Chunk of the Field Name
		/// \param dataChunk Chunk of the Field Data
		/// \param parent IPersist Parent that contains child objects
		void buildObjectField(Data::Chunk *nameChunk, Data::Chunk *dataChunk, IPersist *parent);
	};


}

#endif