#include "Logger.h"
#include <iostream>

namespace StiPersist
{
	namespace Logger
	{

		void Error(std::string message)
		{
			std::cout << "StiPersist [error] : " << message << std::endl;
		}
			

		void Warning(std::string message)
		{
			if(DebugMode)
			{
				std::cout << "StiPersist [warning] : " << message << std::endl;
			}
		}
			
		void Message(std::string message)
		{
			if(DebugMode)
			{
				std::cout << "StiPersist : " << message << std::endl;
			}
		}
	
	}
}