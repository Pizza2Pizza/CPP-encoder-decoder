/*!\file XOutOfBounds.hpp
 * \brief Verlängerung von exception klasse
 *
 *  Created on: 23 May 2020
 *      Author: alinc
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_
#include <exception>
#include <string>
using namespace std;

class XOutOfBounds :public exception{

private:
	string m_msg;//!< Private Membervariable die zeigt error message
public:
	/*!
	* Konstruktor, die initialisiert der private Membervariable m_msg
	*/
	XOutOfBounds(const char* msg);
	/*!
	* Parameterloser Destruktor, die darf keine Fehlerobjekte werfen
	*/
	virtual ~XOutOfBounds() throw();//the exception class shouldn't allow exception itself
	//exception is technically not allowing some exception but limiting the number of exception
	//throw() == noexcept
	/*!
	* Methode liefert eine Zeiger auf const char zurück, darf aber nichts von object verändern
	* darf auch keine exception werfen
	*/
	virtual const char* what() const noexcept;


};

#endif /* XOUTOFBOUNDS_HPP_ */
