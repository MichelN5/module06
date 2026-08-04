/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:11:15 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/04 17:16:15 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

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

static bool isCharLiteral(const std::string &literal)
{
	if(literal.length() != 1)
		return false;
	if(std::isdigit(static_cast<unsigned char>(literal[0])))
		return false;
	return std::isprint(static_cast<unsigned char>(literal[0]));
}

static bool isIntegerLiteral(const std::string &literal)
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

static bool isFloatLiteral(const std::string &literal)
{
	std::string::size_type i = 0;
	int dotCount = 0;
	bool digitFound = false;

	if (literal.empty())
		return false;
	if(literal[literal.length() - 1] != 'f')
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;


	for(; i < literal.length() - 1; i++)
	{
		if(literal[i] == '.')
			dotCount++;
		else if(std::isdigit(static_cast<unsigned char>(literal[i])))
			digitFound = true;
		else
			return false;
	}

	return (digitFound && dotCount == 1);
}

static bool isDoubleLiteral(const std::string &literal)
{
	std::string::size_type i = 0;
	int dotCount = 0;
	bool digitFound = false;

	if (literal.empty())
		return false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;


	for(; i < literal.length(); i++)
	{
		if(literal[i] == '.')
			dotCount++;
		else if(std::isdigit(static_cast<unsigned char>(literal[i])))
			digitFound = true;
		else
			return false;
	}

	return (digitFound && dotCount == 1);
}

static bool isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "-inf"
		|| literal == "+inff" || literal == "-inff");
}

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void convertCharLiteral(const std::string &literal)
{
	char characterValue = literal[0];
	int integerValue = static_cast<int>(characterValue);
	float floatValue = static_cast<float>(characterValue);
	double doubleValue = static_cast<double>(characterValue);

	std::cout << "char: '" << characterValue << "'" << std::endl;
	std::cout << "int: " << integerValue << std::endl;
	std::cout << "float: " << floatValue << ".0f" << std::endl;
	std::cout << "double: " << doubleValue << ".0" << std::endl;
}

static void convertIntegerLiteral(const std::string &literal)
{
	std::istringstream stream(literal);
	int integerValue = 0;

	stream >> integerValue;
	if (stream.fail())
	{
		printImpossible();
		return;
	}
	if (integerValue < static_cast<int>(std::numeric_limits<char>::min())
		|| integerValue > static_cast<int>(std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char characterValue = static_cast<char>(integerValue);

		if (std::isprint(static_cast<unsigned char>(characterValue)))
			std::cout << "char: '" << characterValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << integerValue << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(integerValue) << "f"
		<< std::endl;
	std::cout << "double: " << static_cast<double>(integerValue) << std::endl;
}

static void convertFloatLiteral(const std::string &literal)
{
	std::string numericPart = literal.substr(0, literal.length() - 1);
	std::istringstream stream(numericPart);
	float floatValue = 0;
	double wideValue;

	stream >> floatValue;
	if (stream.fail())
	{
		printImpossible();
		return;
	}


	wideValue = static_cast<double>(floatValue);
	if (wideValue <= static_cast<double>(std::numeric_limits<char>::min()) - 1.0
		|| wideValue >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char characterValue = static_cast<char>(floatValue);

		if (std::isprint(static_cast<unsigned char>(characterValue)))
			std::cout << "char: '" << characterValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}


	if (wideValue <= static_cast<double>(std::numeric_limits<int>::min()) - 1.0
		|| wideValue >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;

	if (std::floor(wideValue) == wideValue)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << floatValue << "f" << std::endl;
	std::cout << "double: " << wideValue << std::endl;
}

static void convertDoubleLiteral(const std::string &literal)
{
	std::istringstream stream(literal);
	double doubleValue = 0;

	stream >> doubleValue;

	if (stream.fail())
	{
		printImpossible();
		return;
	}

	if (doubleValue <= static_cast<double>(std::numeric_limits<char>::min()) - 1.0
		|| doubleValue >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char characterValue = static_cast<char>(doubleValue);

		if (std::isprint(static_cast<unsigned char>(characterValue)))
			std::cout << "char: '" << characterValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (doubleValue <= static_cast<double>(std::numeric_limits<int>::min()) - 1.0
		|| doubleValue >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;


	if (std::floor(doubleValue) == doubleValue)
		std::cout << std::fixed << std::setprecision(1);

	if (doubleValue < -static_cast<double>(std::numeric_limits<float>::max())
		|| doubleValue > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;

	std::cout << "double: " << doubleValue << std::endl;

}

static void convertPseudoLiteral(const std::string &literal)
{
	bool floatSource = (literal == "nanf" || literal == "+inff"
		|| literal == "-inff");
	bool nanValue = (literal == "nan" || literal == "nanf");
	bool positiveInfinity = (literal == "+inf" || literal == "+inff");
	float floatValue = 0;
	double doubleValue = 0;

	if (floatSource)
	{
		if (nanValue)
			floatValue = std::numeric_limits<float>::quiet_NaN();
		else if (positiveInfinity)
			floatValue = std::numeric_limits<float>::infinity();
		else
			floatValue = -std::numeric_limits<float>::infinity();
		doubleValue = static_cast<double>(floatValue);
	}
	else
	{
		if (nanValue)
			doubleValue = std::numeric_limits<double>::quiet_NaN();
		else if (positiveInfinity)
			doubleValue = std::numeric_limits<double>::infinity();
		else
			doubleValue = -std::numeric_limits<double>::infinity();
		floatValue = static_cast<float>(doubleValue);
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (positiveInfinity)
		std::cout << std::showpos;
	std::cout << "float: " << floatValue << "f" << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
	std::cout << std::noshowpos;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		convertPseudoLiteral(literal);
	else if (isCharLiteral(literal))
		convertCharLiteral(literal);
	else if (isIntegerLiteral(literal))
		convertIntegerLiteral(literal);
	else if (isFloatLiteral(literal))
		convertFloatLiteral(literal);
	else if (isDoubleLiteral(literal))
		convertDoubleLiteral(literal);
	else
		printImpossible();


}
