
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace seneca 
{
    template <typename T, int CAPACITY>
    class Collection {
        T m_elements[CAPACITY];
        static T m_dummy;
	size_t m_size;
    public:
        Collection();
	virtual ~Collection();
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        virtual bool add(const T& item);
        T operator[](const int index) const;
    };

    template <typename T, int CAPACITY>
    T Collection<T, CAPACITY>::m_dummy{};
    template <>
    Pair Collection<Pair, 100>::m_dummy("No Key", "No Value");
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::Collection() 
	{
		m_size = {};
	}
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::~Collection() {};
	template <typename T, int CAPACITY>
	size_t Collection<T, CAPACITY>::size() const 
	{
		return m_size;
	}

	template<typename T, int CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& ostr)const 
	{
		ostr << "----------------------" << std::endl;
		ostr << "| Collection Content |" << std::endl;
		ostr << "----------------------" << std::endl;
		for (auto i = 0ul; i < m_size; ++i)
			ostr << m_elements[i] << std::endl;
		ostr << "----------------------" << std::endl;
		return ostr;
	}

	template <typename T, int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item) 
	{
		bool check = false;
		if (m_size < CAPACITY - 1)
		{
			m_elements[m_size++] = item;
			check = true;
		}
		return check;
	}

	template<typename T, int CAPACITY>
	T Collection<T, CAPACITY>::operator[](const int index)const 
	{
		T tempDummy;
		if (index < (int)m_size)
		{
			tempDummy = m_elements[index];
		}
		else
		{
			tempDummy = m_dummy;
		}
		return tempDummy;
	
	}

}
#endif