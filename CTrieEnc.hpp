/*!\file CTrieEnc.hpp
 * \brief Klasse CTrieEnc implementiert ein LZW Algorithm
 * um zu ein Array als Trie encodieren
 * Note: CTrieEnc erbt von CEnc
 */
#include "CEnc.hpp"
#include "CArray.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

class CTrieEnc: public CEnc{
public:
  /*!
  * Deklaration des parameterlosen Konstruktors
  * in der Konstruktors werden die ersten 256 ASCII Werte in Dictionary gespeichert
  * Parent index für die erste 256 ASCII Werte soll -1 sein
  */
  CTrieEnc();
  /*!
   * Function encode wird für encodieren den string bei LZW algorithm benutz
   * @param string fur encode
   * @return in vector der string in code representiert
   */
  vector<unsigned int>encode(const string&);

private:
  /*!
   * Private Membervariable m_symbolTable
   * wird in Konstruktor mit ersten 256 ASCII Werte initialisiert
   * Als Datentyp des Arrays ist das Klassentemplate CArray mit Parameters CEntry,LZW_DICT_SIZE benutzt
   * LZW_DICT_SIZE ist die grosse von Dictionary
   */
  CArray<CKnot,LZW_DICT_SIZE>m_symbolTable;
  /*!
   * Funktion ist benutz um zu Index von char mit gegebenen parent index zuruck zu geben
   * @param buchstabe ein char zu finden
   * @param parent_index fur gegebene char
   * @return index von dictionary wo gegebene buchstabe gespecihert wurde
   * wenn gegebene buchstabe nicht gefunden wurde, wird int -1 zuruckgegeben sein
   */

  int searchinTable(const char buchstabe, int parent_index);
  /*!
   * Diese Methode ist benutz um zu leere Knote in Dictionary zu finden
   * Das bedeutet das wir gegebene buchstabe da speichern können
   * @param buchstabe ein char. gebraucht fur hash function
   * @param parent_index fur gegebene char. gebraucht fur hash function
   * @return index von leeren Cknote
   * falls keine leeren CKnoten gefunden wurde, wird die function -1 zuruck geben
   */
  int calculate_index(const char buchstabe, int parent_index);
};
