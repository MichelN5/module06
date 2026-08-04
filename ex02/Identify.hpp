/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:00:00 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/04 21:06:07 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp"
# include <iostream>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
