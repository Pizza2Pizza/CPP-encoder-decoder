/*!\file CEntry.cpp
 * \brief
 *
 *  Created on: 10 May 2020
 *      Author: alinc
 */


#include "CEntry.hpp"

CEntry:: CEntry() : m_symbol(""){
	++m_number;
}

CEntry::~CEntry(){
	--m_number;
}

const string& CEntry::getSymbol() const{
	return m_symbol;
}

void CEntry::setSymbol(string symbol){
	m_symbol = symbol;
}

unsigned int CEntry:: m_number{0};

unsigned int CEntry::getNumber(){
	return m_number;
}
