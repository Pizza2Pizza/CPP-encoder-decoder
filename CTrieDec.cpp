#include "CTrieDec.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

CTrieDec::CTrieDec(){
  for(int i = 0; i<256; i++){
    m_symbolTable[i].setParent(-1);
    m_symbolTable[i].setSymbol(intToString(i));
  }
}

//wir suchen nach leeren CKnot
int CTrieDec::calculate_index(const char buchstabe, int parent_index){
  CForwardCounter attempt_counter;//TODO CForwardCounter
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
//gibt eine kette von buctaben zuruck
//von gegebene buchtabe bis buchtabe mit parent index -1
string CTrieDec::stringmaker(int index){
  string out;
  while(1){
    if(m_symbolTable[index].getParent() == -1){
      out = out+m_symbolTable[index].getSymbol();
      break;
    }
    out =out+m_symbolTable[index].getSymbol();
    int parent_index = m_symbolTable[index].getParent();
    index = parent_index;
  }
  //since unseres sring reversed ist
  reverse(out.begin(), out.end());
  return out;
}

string CTrieDec::decode (const vector<unsigned int>& input){
  string out;
  //unsigned int parent_index;
  for(unsigned int i = 0; i<input.size(); i++){
	int pos = input[i];
    if(i==0){
    out= out+ m_symbolTable[pos].getSymbol();
   // cout <<"Position in input: " <<pos<< " symbol : "<<m_symbolTable[pos].getSymbol()<<endl;
    }
    if(i !=0){
      if(m_symbolTable[pos].getParent() !=-2){//when unsere element in book ist
        //index represents nicht eine buchstabe, sondern eine kette von buchtaben!
        out= out+stringmaker(pos);
      //  cout << "string :"<<stringmaker(pos)<<" with end in position: " <<pos<<endl;
        //neue CKnot in tabelle hinzufugen
        char buch = stringmaker(pos)[0];////wir wollen die erste buchstabe von string buchtaben
        int index = calculate_index(buch, input[i-1]);
        m_symbolTable[index].setParent(input[i-1]);
        m_symbolTable[index].setSymbol(string(1,buch));
      }
      else{//wir haben den code nicht in der tabellee
        out += stringmaker(input[i-1])+stringmaker(input[i-1])[0];
        //cout << "Code nicht in der tabelle. String :"<<stringmaker(input[i-1])+stringmaker(input[i-1])[0]<<endl;
        m_symbolTable[input[i]].setParent(input[i-1]);
        char buch = stringmaker(input[i-1])[0];
        m_symbolTable[input[i]].setSymbol(string(1,buch));
      }
    }
  }
  return out;
}
