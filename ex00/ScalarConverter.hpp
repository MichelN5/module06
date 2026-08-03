/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:11:08 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/03 21:11:10 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cctype>


class ScalarConverter
{
private:
	static bool isIntegerLiteral(const std::string &input);
	static bool isFloatLiteral(const std::string &input);
	static bool isDoubleLiteral(const std::string &input);
	static bool isPseudoLiteral(const std::string &input);
	static bool isCharLiteral(const std::string &literal);

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static void convert(const std::string &literal);
};

#endif
