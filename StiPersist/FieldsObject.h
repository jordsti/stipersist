#ifndef FIELDSOBJECT_H
#define FIELDSOBJECT_H

#include "Persistable.h"

namespace StiPersist
{
	/// \class FieldsObject
	/// \brief Implementation of Persistable. This class is used to populate container element has a FieldsObject
	class FieldsObject :
		public Persistable
	{
	public:
		/// \brief Constructor
		FieldsObject();
		
		/// \brief Destructor
		virtual ~FieldsObject();
		
		/// \brief Implementation of Persistable
		void fromFields(void);
		
		/// \brief Create fields from Chunk
		/// \param chunk Data Chunk
		void fromChunk(Data::Chunk *chunk);
		
		/// \brief Set String Value
		/// \param fname Field Name
		/// \param value String Value
		void setString(std::string fname, std::string value);
				
		/// \brief Set Integer Value
		/// \param fname Field Name
		/// \param value Integer Value
		void setInt(std::string fname, int value);
				
		/// \brief Set Double Value
		/// \param fname Field Name
		/// \param value Double Value
		void setDouble(std::string fname, double value);
				
		/// \brief Set Float Value
		/// \param fname Field Name
		/// \param value Float Value
		void setFloat(std::string fname, float value);
				
		/// \brief Set Raw Value
		/// \param fname Field Name
		/// \param value Raw Value
		/// \param length Data Length
		void setRaw(std::string fname, char *value, unsigned int length);
				
		/// \brief Set unsigned Integer Value
		/// \param fname Field Name
		/// \param value unsigned Integer Value
		void setUInt(std::string fname, unsigned int value);
				
		/// \brief Set Bool Value
		/// \param fname Field Name
		/// \param value Bool Value
		void setBool(std::string fname, bool value);
		
		/// \brief Get String Value
		/// \param fname Field Name
		/// \return String
		std::string getString(std::string fname);
		
		/// \brief Get Integer Value
		/// \param fname Field Name
		/// \return Integer
		int getInt(std::string fname);
		
		/// \brief Get Double Value
		/// \param fname Field Name
		/// \return Double
		double getDouble(std::string fname);
		
		/// \brief Get Float Value
		/// \param fname Field Name
		/// \return Float
		float getFloat(std::string fname);
		
		/// \brief Get Raw Value
		/// \param fname Field Name
		/// \return Raw
		char* getRaw(std::string fname);
		
		/// \brief Get Unsigned Integer Value
		/// \param fname Field Name
		/// \return Unsigned Integer
		unsigned int getUInt(std::string fname);
		
		/// \brief Get Bool Value
		/// \param fname Field Name
		/// \return Bool
		bool getBool(std::string fname);
		
		/// \brief Get all fields information
		/// \return List of Field Info
		std::list<Data::FieldInfo*>* getFieldsName(void);
	protected:
		/// \brief Implementation of IPersist
		void populateFields(void);
	};

}

#endif