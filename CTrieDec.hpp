/*!\file CTrieDec.hpp
 * \brief Klasse CTrieDec implementiert ein LZW Algorithm fur Message decoding
 * um ein Array zu bekommen
 * Note: CArrayDec erbt von CDec
 */
#include "CDec.hpp"
#include "CArray.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

class CTrieDec: public CDec{
public:
  /*!
  * Deklaration des parameterlosen Konstruktors
  * in der Konstruktors werden die ersten 256 ASCII Werte in Dictionary gespeichert
  * Parent index für die erste 256 ASCII Werte soll -1 sein
  */
  CTrieDec();
  /*!
  * Function decode wird für decodieren den encodierete Message(bei LZW algorithm) benutz
  * @param ein reference zu vector von unsigned int fur decode
  * @return ein decodierte string
  */
  string decode (const vector<unsigned int>&);

private:
  /*!
   * Private Membervariable m_symbolTable
   * wird in Konstruktor mit ersten 256 ASCII Werte initialisiert
   * Als Datentyp des Arrays ist das Klassentemplate CArray mit Parameters CEntry,LZW_DICT_SIZE benutzt
   * LZW_DICT_SIZE ist die grosse von Dictionary
   */
  CArray<CKnot,LZW_DICT_SIZE>m_symbolTable;

//  unsigned int searchinTable(const char buchstabe, unsigned int parent_index);
  /*!
   * Diese Methode ist benutz um zu leere Knote in Dictionary zu finden
   * Das bedeutet das wir gegebene buchstabe da speichern können
   * @param buchstabe ein char. gebraucht fur hash function
   * @param parent_index fur gegebene char. gebraucht fur hash function
   * @return index von leeren Cknote
   * falls keine leeren CKnoten gefunden wurde, wird die function -1 zuruck geben
   */
 int calculate_index(const char buchstabe, int parent_index);
 /*!
  * Fur gegebe index wird diese methode den Kette von Buchstaben zuruckgeben
  * Die Kette geht von Buchtabe mit gegebenen Index bis Buchtabe mit parent index -1
  * @param index. representiert den buchtabe
  * @return ein string von gegeben Buchtabe bis anfang des trie
  */
 string stringmaker(int index);
};
