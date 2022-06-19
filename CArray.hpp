/*!\file CArray.hpp
 * \brief Klasse CArray implementiert ein Datenfeld
 * CArray ist eine template Klasse fur Parameters T und N
 * T ist ein typename fur gescpeicherte elemente, inhalt des Feldes
 * N ist Anzahl den Feldelemente
 *  Created on: 23 May 2020
 *      Author: alinc
 */

#ifndef CARRAY_HPP_
#define CARRAY_HPP_
#include "XOutOfBounds.hpp"
#include <iostream>
using namespace std;

template <typename T, unsigned int N> class CArray
{
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors.
	 */
	CArray();
	/*!
	 * Deklaration des Konstruktors fur initialisierung des Inhalt von array
	 * @param initializer list fur typ T
	 */
	CArray(initializer_list<T>);
	/*!
	 * Deklaration des Kopie Konstruktors
	 * @param reference auf eigenen Klassentyp
	 */
	CArray(const CArray&);
	/*!
	* Destruktor von CArray
	*/
	virtual ~CArray();
	/*!
	 * Indexoperator fur Zugriff auf elemente des Feldes
	 * @param index von element
	 * @return reference auf Inhalt eines Feldes
	 */

	T& operator[](unsigned int);
private:
	/*!
	 * /!< Private Membervariable für ein Array
	 */
	T* entries;
};



template<typename T, unsigned int N>
CArray<T,N>::CArray() : entries(new T[N]){
	//enties = new T[N];
//	cout << "Patameterloser Konstruktor" << endl;

}
template<typename T, unsigned int N>
CArray<T,N>::CArray(const CArray & other) : entries(new T[N]){
	for(int i = 0; i<N; i++){
			entries[i]=other.entries[i];
		}
}

template<typename T, unsigned int N>
CArray<T,N>::CArray(initializer_list<T> lst) : entries(new T[N]){
//	cout << "Konstruktor mit initialisuerung liste" << endl;
	vector<T> vec(lst);
	for(int i = 0; i<N; i++){
		entries[i]=vec[i];
	}
}
template<typename T, unsigned int N>
CArray<T,N>::~CArray(){
//	cout<< "Destruktor" << endl;
	if(entries != nullptr){
		delete[] entries;//delete doesn't automatically set it as zero
		entries = nullptr;
	}
	else cout <<"Delete nullptr?"<<endl;
}

template<typename T, unsigned int N>
T& CArray<T,N>::operator [](unsigned int index){
	if(index >=N)
		throw XOutOfBounds("Index zu gross");//it's like return
	return entries[index];
}








#endif /* CARRAY_HPP_ */
