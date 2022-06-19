#include "CArrayEnc.hpp"
using namespace std;

//initialisuerung "dictionary book" m_symbolTable mit ASCII_code
CArrayEnc::CArrayEnc(){
  for(int i = 0; i<256; i++){
    m_symbolTable[i].setSymbol(intToString(i));//setSymbol implementiert in CEntry
    lastIndex = i;//last symbol in dictionary in position i
  }
};

//suchen nach string in dictinary book
int CArrayEnc::searchInTable(const string& needle){
	//std::cout<<"The needle is "<<needle<<std::endl;
  for(int i = 0; i<=lastIndex; i++){//durchsuche von m_symbolTable
	  //std::cout<<"the symbol table get "<<m_symbolTable[i].getSymbol()<<std::endl;
	  if (m_symbolTable[i].getSymbol().compare(needle)== 0){
	 // cout<<i<<endl;
      return i;
      }
    }
    //needle ist nicht in der Liste
  	//cout << -1 <<endl;
    return -1;
}

vector<unsigned int> CArrayEnc::encode(const string& decoding){
  unsigned int i =0;
  vector<unsigned int> thisword;
  int index_in_dict = 0;//for remebering what we already added in dictionary and on what position
  if(decoding.length()==0){
    return thisword;//vector is leer am anfang an
  }
    while(i<decoding.length()) {
      if(searchInTable(decoding.substr(index_in_dict,i-index_in_dict+1)) != -1){//this characters are already in dictionary, we don't need them
        i++;
      }
      else{
        //add non-found string in the dictionary
        m_symbolTable[lastIndex+1].setSymbol(decoding.substr(index_in_dict, i-index_in_dict+1));
        //index_in_dict= i;//new position of last added string
        thisword.push_back(searchInTable(decoding.substr(index_in_dict,i-index_in_dict)));//we added the substring that can be found in dictionary to vector
        index_in_dict= i;//new position of last added string
        //int cur = searchInTable(decoding.substr(index_in_dict,i-1-index_in_dict));
        //std::cout << cur<<std:: endl;

        lastIndex++;
      }
  }
  //adding the character in the end of the string
  thisword.push_back(searchInTable(decoding.substr(index_in_dict,i-index_in_dict)));
  return thisword;
}


