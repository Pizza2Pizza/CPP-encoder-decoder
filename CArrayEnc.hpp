/*!\file CArrayEnc.hpp
 * \brief Klasse CArrayEnc implementiert ein LZW Algorithm als Array
 * um zu ein Array encodieren
 * Note: CArrayEnc erbt von CEnc
 */
#include "CEnc.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

class CArrayEnc: public CEnc{
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors
	 * in der Konstruktors werden die ersten 256 ASCII Werte in Dictionary gespeichert
	 */
    CArrayEnc();
    /*!
     * Function encode wird für encodieren den string bei LZW algorithm benutz
     * @param string fur encode
     * @return ein vector der string in code representiert
     */
    vector<unsigned int> encode(const string&);
private:
  /*!
   * Private Membervariable m_symbolTable
   * wird in Konstruktor mit ersten 256 ASCII Werte initialisiert
   * Als Datentyp des Arrays ist das Klassentemplate CArray mit Parameters CEntry,LZW_DICT_SIZE benutzt
   * LZW_DICT_SIZE ist die grosse von Dictionary
   */
  CArray<CEntry,LZW_DICT_SIZE>m_symbolTable;
  /*!
   * Funktion ist benutz um zu Index von gegebene string zu return
   * @param string das gefunden werden soll
   * @return index von gegeben string
   */

  int searchInTable(const string&);
  /*!
   * Private Membervariable fur speichern del letzten gespeicherte string zu speichern
   * wird in Konstruktor initialisieren
   */
  int lastIndex;

};
