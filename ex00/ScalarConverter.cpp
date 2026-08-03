/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:11:15 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/03 21:46:56 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isCharLiteral(const std::string &literal)
{
	if(literal.length() != 1)
		return false;
	if(std::isdigit(static_cast<unsigned char>(literal[0])))
		return false;
	return std::isprint(static_cast<unsigned char>(literal[0]));
}

bool ScalarConverter::isIntegerLiteral(const std::string &literal)
{
	std::string::size_type i = 0;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return false;
		i++;
	}
	return true;
}



void ScalarConverter::convert(const std::string &)
{
}
