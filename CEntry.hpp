/*!\file CEntry.hpp
 * \brief Klasse CEntry operiert mit strings.
 * Die Klasse spreichert die zeichenketten und wird noch per Vererbung erweitert.
 *
 *  Created on: 10 May 2020
 *      Author: alinc
 */

#ifndef CENTRY_HPP_
#define CENTRY_HPP_
#include <string>
using namespace std;

class CEntry{
public:
	/*!
	* Parameterloser Konstruktor, setzt den m_symbol auf leere string
	*/
	CEntry();
	/*!
	 * Destruktor von CEntry
	 */
	virtual ~CEntry();
	/*!
	 * die funktion gibt gespeicherte Zeichenkette zuruck
	 */
	const string& getSymbol() const;//const is applied to the left of the const
	/*!
	 * die funktion speichert eine zeichenkette in m_symbol
	 */
	void setSymbol(string);
	/*!
	 * getNumber() liefert private Membervariable m_number zuruck
	 */
	static unsigned int getNumber();//since m_number is static, it's more convenient to have this function also static
	//we can call it without creating instance beforehand

private:
	string m_symbol;//!< Private Membervariable für den Zeichenkette
	//normal variable are associated with instances, while static don't
	static unsigned int m_number;//!< Private statische Membervariable m_number
	//static variable, other can't do anything to it
	//shared with every instance of the class
};




#endif /* CENTRY_HPP_ */
