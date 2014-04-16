#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace StiPersist
{
	namespace Logger
	{
		#ifdef DEBUG
		const bool DebugMode = true;
		#endif
		
		#ifdef RELEASE
		const bool DebugMode = false;
		#endif
	
		//Error, shown in both mode
		void Error(std::string message);
		
		//Warning only shown in Debug
		void Warning(std::string message);
		
		//Message only shown in Debug
		void Message(std::string message);
	}
	
}

#endif