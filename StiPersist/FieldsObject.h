#ifndef FIELDSOBJECT_H
#define FIELDSOBJECT_H

#include "IPersist.h"

namespace StiPersist
{
	class FieldsObject :
		public IPersist
	{
	public:
		FieldsObject();
		virtual ~FieldsObject();
		
		void fromFields(void);
		
		void fromChunk(Data::Chunk *chunk);
		
		void setString(std::string fname, std::string value);
		void setInt(std::string fname, int value);
		void setDouble(std::string fname, double value);
		void setFloat(std::string fname, float value);
		void setRaw(std::string fname, char *value, unsigned int length);
		void setUInt(std::string fname, unsigned int value);
		void setBool(std::string fname, bool value);
		
		std::string getString(std::string fname);
		int getInt(std::string fname);
		double getDouble(std::string fname);
		float getFloat(std::string fname);
		char* getRaw(std::string fname);
		unsigned int getUInt(std::string fname);
		bool getBool(std::string fname);
		
		std::list<Data::FieldInfo*>* getFieldsName(void);
	protected:
		void populateFields(void);
	};

}

#endif