

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>
#include <string>

namespace seneca 
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
		Pair(); 
		bool operator==(const Pair& src);
		std::ostream& display(std::ostream& ostr)const;

	};

	std::ostream& operator<<(std::ostream& ostr, const Pair& rhs);

}

#endif
