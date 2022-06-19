#include "CArrayDec.hpp"
using namespace std;

CArrayDec::CArrayDec(){
  for(int i = 0; i<256; i++){
    m_symbolTable[i].setSymbol(intToString(i));
    lastIndex= i;
  }
};

string CArrayDec::decode (const vector<unsigned int>& num){
  string out;
  for(unsigned int i = 0; i<num.size(); i++){
    int pos = num[i];//the number we are at
    if(pos<=lastIndex ){//means we didn't reach the end and our number should be inside the book
      out= out+ m_symbolTable[pos].getSymbol();//am ende des string die dekodierte buchstabe reinpacken
      //cout<<"Adding symbol from the table "<<out<<endl;
      if(i!=0){
        //the last string + the first letter of the current string
        string n=m_symbolTable[num[i-1]].getSymbol()+m_symbolTable[num[i]].getSymbol()[0];
        m_symbolTable[lastIndex+1].setSymbol(n);
        //cout<<"Adding new symbols in table "<< n <<endl;
        lastIndex++;
      }
    }
    else{
      string mu = m_symbolTable[num[i-1]].getSymbol()+m_symbolTable[num[i-1]].getSymbol()[0];
      m_symbolTable[lastIndex+1].setSymbol(mu);
     // cout<<"Special case "<<mu<<endl;
      lastIndex++;
      out+= mu;
    }
  }
  return out;
}
