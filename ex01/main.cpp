/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:36:59 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/04 19:48:08 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data d;
	Data *unser;

	d.value = 100;
	uintptr_t ser = Serializer::serialize(&d);

	std::cout << "Serialized : " << ser << std::endl;
	unser = Serializer::deserialize(ser);
	if (unser != &d)
	{
		std::cout << "Pointers do not match" << std::endl;
		return 1;
	}
	std::cout << "Pointers match" << std::endl;
	std::cout << "Deserialized : " << unser->value << std::endl;
	return 0;
}
