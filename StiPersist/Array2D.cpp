#include "Array2D.h"
#include "Array2DIterator.h"
#include "Logger.h"
namespace StiPersist
{
	namespace Container
	{
		Array2D::Array2D()
		{
			i_length = 0;
			j_length = 0;

			clearData = false;
		}
		
		Array2D::Array2D(unsigned int m_i_length, unsigned m_j_length)
		{
			i_length = m_i_length;
			j_length = m_j_length;

			elements.reserve(i_length);
			
			for(int i=0; i<i_length; i++)
			{
				elements.push_back(std::vector<IPersist*>());
				elements[i].reserve(j_length);
			}
			
			clearData = true;
		}
		
		Array2DIterator* Array2D::getIterator(void)
		{
			return new Array2DIterator(this);
		}
			
		IPersist* Array2D::get(int i, int j)
		{
			if(i < i_length && j < j_length)
			{
				return elements[i][j];
			}
			else
			{
				Logger::Error("Array2D out of range -> get(i,j)");
				return nullptr;
			}
		}
		
		void Array2D::insert(int i, int j, IPersist *element)
		{
			if(i < i_length && j < j_length)
			{
				std::vector<IPersist*>::iterator lit (elements[i].begin());
				
				elements[i].insert(lit, j, element);
			}
			else
			{
				Logger::Error("Array2D out of range -> insert(i,j,element)");
			}
		}
		
		void Array2D::append(int i, IPersist *element)
		{
			if(i < i_length)
			{
				if(elements[i].size() < j_length)
				{
					elements[i].push_back(element);
				}
				else
				{
					Logger::Error("Array2D out of range -> insert(i,[j],element)");
				}
			}
			else
			{
				Logger::Error("Array2D out of range -> insert([i],j,element)");
			}
		}
			
		Array2D::~Array2D()
		{
			//todo
			if(clearData && i_length > 0 && j_length > 0)
			{
				std::vector< std::vector<IPersist*> >::iterator lit(elements.begin()), lend(elements.end());
				
				for(;lit!=lend;++lit)
				{
					std::vector<IPersist*>::iterator lit2 ((*lit).begin()), lend2((*lit).end());
					for(;lit2!=lend2;++lit2)
					{
						delete (*lit2);
					}
				}
			}
		}
			
		bool Array2D::isEmpty(void)
		{
			return (i_length == 0 && j_length == 0);
		}
			
		unsigned int Array2D::getiLength(void)
		{
			return i_length;
		}
		
		unsigned int Array2D::getjLength(void)
		{
			return j_length;
		}
		
		void Array2D::setClearData(bool m_clearData)
		{
			m_clearData = clearData;
		}
		
		bool Array2D::getClearData(void)
		{
			return clearData;
		}

	}
}