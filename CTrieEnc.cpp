#include "CTrieEnc.hpp"
using namespace std;

CTrieEnc::CTrieEnc(){
  for(int i = 0; i<256; i++){
    m_symbolTable[i].setParent(-1);
    m_symbolTable[i].setSymbol(intToString(i));
  }
}

int CTrieEnc::searchinTable(const char buchstabe, int parent_index){
  if(parent_index == -1) {
	 // cout <<"found buchstabe at index: " <<charToInt(buchstabe)<<endl;
	  return (charToInt(buchstabe));//fall when es erste buchtabe in table ist
  }
  CForwardCounter attempt_counter;
  //unsigned int index;
  int first_index;//zum beibachtung wenn wir den crice machen
  while(1){
    int temp_index = CDoubleHashing::getInstance().hash(parent_index,(int)buchstabe,LZW_DICT_SIZE,attempt_counter.getValue());
    if(attempt_counter.getValue() == 0){
      first_index = temp_index;
    }
    //looped back
    if(attempt_counter.getValue()!=0 && first_index == temp_index){
      return -1;
    }
    //empty CKnot
    if(m_symbolTable[temp_index].getParent() ==-2){
        return -1;
    }
    //was wir suchen
    else if((m_symbolTable[temp_index].getSymbol()[0]==buchstabe) && (m_symbolTable[temp_index].getParent()==parent_index)){
      return temp_index;
    }
    //es gibt was bei CKnot aber nicht was wir suchen
    else{
      attempt_counter.count();
    }
  }
}
//wir suchen nach leeren CKnot
 int CTrieEnc::calculate_index(const char buchstabe, int parent_index){
  CForwardCounter attempt_counter;//TODO
  //unsigned int index;
  int first_index;//zum beibachtung wenn wir den crice machen
  while(1){
    int temp_index = CDoubleHashing::getInstance().hash(parent_index,(int)buchstabe,LZW_DICT_SIZE,attempt_counter.getValue());
    if(attempt_counter.getValue() == 0){
      first_index = temp_index;
    }
    //looped back
    if(attempt_counter.getValue()!=0 && first_index == temp_index){
      return -1;
    }
    //nicht empty CKnot
    if(m_symbolTable[temp_index].getParent() !=-2){
        attempt_counter.count();
    }
    //was wir suchen:empty CKnot
    else {
      return temp_index;
    }
  }
}


vector<unsigned int> CTrieEnc::encode(const string& input){
  unsigned int i =0;
  int index = 0;
  int temp_index = -1;
  vector<unsigned int> thisword;
  //die array ist leer
  if(input.length()==0){
	//cout <<"The empty string"<<endl;
    return thisword;//vector is leer am anfang an
  }
    while(i<input.length()) {
      if(searchinTable(input[i],temp_index) != -1){
        index = searchinTable(input[i],temp_index);
       // cout <<"found the input: " <<input[i]<<" with parent_index:" <<temp_index<<" at index "<<index <<endl;
        temp_index = index; //switch
        i++;
    }
      else{
    	//cout << "Couldn't find input[i] "<<input[i]<<" with parent_index:" << temp_index<<endl;
        thisword.push_back(index);

       int a = calculate_index(input[i], temp_index);//TODO
       if(a == -1){
         perror("keinen leeren Platz mehr\n");
       }
        string b = string(1,input[i]);
        //cout <<"storing the index b: " <<b<<" with parent index: " <<temp_index<<endl;
        m_symbolTable[a].setSymbol(b);//zum table hinzugefugt
        m_symbolTable[a].setParent(temp_index);
        temp_index = -1;
      }
    }
  thisword.push_back(index);
  return thisword;
}
