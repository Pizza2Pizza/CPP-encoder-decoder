/*!\file XOutOfBounds.cpp
 * \brief
 *
 *  Created on: 23 May 2020
 *      Author: alinc
 */

#include "XOutOfBounds.hpp"

XOutOfBounds::XOutOfBounds(const char* msg): m_msg(msg) {
}

XOutOfBounds::~XOutOfBounds() throw() {
}

const char* XOutOfBounds:: what() const throw(){
	return m_msg.c_str();
}

