/*!\file CDoubleHashing.hpp
 * \brief berechnen den hashwert zweier Integer I und J mittels
 * \brief doppelten Hashing fur Hashtabelle fur Grosse dict_size
 *
 *  Created on: 31 May 2020
 *      Author: alinc
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_


class CDoubleHashing {
public:
	/*!
	 *
	 * @return Gibt die einzige Instanz der Klasse zuruck
	 */

	static CDoubleHashing& getInstance();

	/*!
	 *
	 * @param I der beliegebige int wert
	 * @param J der beliegebige int wert
	 * @param dict_size is die grosse der Hashtabelle
	 * @param attempt is der Zahler fur doppeltes hashing
	 * @return schlusserte wert von zwei integer
	 */
	unsigned int hash(unsigned int I,unsigned int J, unsigned int dict_size, unsigned int attempt);
private:
	/*!
	 * Deklaration des privaten parameterlosen Konstruktors
	 */
	CDoubleHashing();
	/*!
	 * Private Kopierkonstruktor verbieten gemass Singletonmuster
	 * @param other
	 */
	CDoubleHashing(const CDoubleHashing& other)=delete;
	/*!
	 * Der private Zuweisungsoperator verbieten gemäss Singletonmuster
	 * @param other
	 * @return the function operator not defined, since we don't want any other instances
	 */

	CDoubleHashing operator=(CDoubleHashing& other)=delete;
	/*!
	 * die einzige Instanz
	 */
	static CDoubleHashing m_instance;
};

#endif /* CDOUBLEHASHING_HPP_ */
