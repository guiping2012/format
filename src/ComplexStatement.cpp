#include "format.h"
#include "Statement.h"


CComplexStatement::CComplexStatement(void)
{
}

CComplexStatement::~CComplexStatement(void)
{
}
int CComplexStatement::getType(void)
{
    return C_STATEMENT_COMPLEX_TYPE;
}

string CComplexStatement::toString()
{
    if (m_tokens != NULL) {
        int size = m_tokens->size();        
        CTokenSet* p = m_tokens->getChildSet(1, size-2);   
        vector<CStatement *> * pStatementSet = new vector<CStatement *>;
        p->initStatementSet(pStatementSet, getIndent() + BREAK_LINE_INDEX);
        string s = string();
        size = pStatementSet->size();        
        for (int i=0; i<size;i++) {
            s += (*pStatementSet)[i]->toString() + string("\n");
        }
        return "{\n" + s + getNumSpace(getIndent()) + "}";
    } else {
        return string();
    }
}
string CComplexStatement::getClassName()
{
    return string("CComplexStatement");
}