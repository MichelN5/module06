/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:30:00 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/04 19:36:45 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &)
{
}

Serializer &Serializer::operator=(const Serializer &)
{
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data * d)
{
	return reinterpret_cast<uintptr_t>(d);
}

Data *Serializer::deserialize(uintptr_t du)
{
	return reinterpret_cast<Data*>(du);
}
