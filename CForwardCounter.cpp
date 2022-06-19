#include "CForwardCounter.hpp"

CForwardCounter::CForwardCounter() : CCounter() 
{
}

void CForwardCounter::count() 
{ //m_value +=1, aber das konnen wir nicht machen, weil m_value privat ist
	int value = getValue();
	setValue (value + 1);
	//setValue (getValue()+1);
}
