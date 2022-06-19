
#include "CKnot.hpp"

CKnot::CKnot() : CEntry(), m_parent(-2)
{

}

CKnot::~CKnot()
{
}

int CKnot::getParent() const
{
	return m_parent;
}

void CKnot::setParent(int parent)
{
	m_parent = parent;
}
