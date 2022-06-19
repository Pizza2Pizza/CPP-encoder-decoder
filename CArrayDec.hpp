/*!\file CArrayDec.hpp
 * \brief Klasse CArrayDec implementiert ein LZW Algorithm fur Message decoding
 * um ein Array zu bekommen
 * Note: CArrayDec erbt von CDec
 */
#include "CDec.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

class CArrayDec: public CDec{
public:
	/*!
	* Deklaration des parameterlosen Konstruktors
	* in der Konstruktors werden die ersten 256 ASCII Werte in Dictionary gespeichert
	*/
    CArrayDec();
    /*!
    * Function decode wird für decodieren den encodierete Message(bei LZW algorithm) benutz
    * @param ein reference zu vector von unsigned int fur decode
    * @return ein decodierte string
    */
    string decode (const vector<unsigned int>&);//pointer onto the vector
private:
    /*!
    * Private Membervariable m_symbolTable
    * wird in Konstruktor mit ersten 256 ASCII Werte initialisiert
    * Als Datentyp des Arrays ist das Klassentemplate CArray mit Parameters CEntry,LZW_DICT_SIZE benutzt
    * LZW_DICT_SIZE ist die grosse von Dictionary
    */
  CArray<CEntry,LZW_DICT_SIZE>m_symbolTable;

  //int searchInTable(const string&);

  /*!
   * Private Membervariable fur speichern del letzten gespeicherte string zu speichern
   * wird in Konstruktor initialisieren
   */
  int lastIndex;

};
