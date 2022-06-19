/*!\file CKnot.hpp
 * \brief erweitet die CEntry klasse um die Adresse des übergeordneten Knotens
 * CKnot() ist der parameterlose Konstruktor
 * Konstuktor initialisiert private Membervariable m_parent mit -2
 * ~CKnot() ist der Destruktor
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_

#include "CEntry.hpp"

class CKnot : public CEntry {
public:
	/*!
	* Deklaration des parameterlosen Konstruktors.
	* Konstuktor initialisiert private Membervariable m_parent mit dem Wert -2
	*/
	CKnot();
	/*!
	* Destruktor von CKnot
	*/
	virtual ~CKnot();
	/*!
	* die funktion gibt gespeicherte parent zuruck
	*/
	int getParent() const;
	/*!
	* die funktion setz einen Parent an private Membervariable m_parent
	*/
	void setParent(int parent);

private:
	int m_parent;//!< Private Membervariable die Index von parent spreichert
};

#endif /* CKNOT_HPP_ */
