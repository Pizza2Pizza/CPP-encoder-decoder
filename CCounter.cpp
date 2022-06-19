 /*! \file CCounter.cpp
 *  \brief Definitionen der Klasse CCounter
 *
 *  Die bei den Deklarationen in CCounter.hpp genannten Informationen müssen hier nicht mehr wiederholt werden.
 *  Dieses File CCounter.cpp bekommen Anwender der Klasse nicht zu Gesicht, daher sind die Kommentare in
 *  diesem File als Informationen für Programmierer gedacht, nicht für den Anwender.
 *
 *  Im vorliegenden File werden im wesentlichen die Inhalte der geschweiften Klammern dokumentiert,
 *  aber nur dort, wo der Inhalt nicht ohnehin selbsterklärend ist.
 */
#include "CCounter.hpp"

CCounter::CCounter() : m_value(0) {
}
//man kann auch schreiben m_value=0;
CCounter::~CCounter() {

}

int CCounter::getValue() const {//this function can't change m_value, because of const
	return m_value;
}

void CCounter::setValue(int value) {
	m_value = value;
}

void CCounter::count() {
	//m_value +=1;     // Zeile auskommentieren für Aufgabe_3 in Übungsblatt 2
	//wenn oberklasse eine funktion hat die unterklasse uberschreiben sollen wir diese funktion auskommentieren
}

bool CCounter::operator<(const CCounter& other) const {
	return m_value < other.m_value;
}

bool CCounter::operator>(const CCounter& other) const {
	return m_value > other.m_value;
}
