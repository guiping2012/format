#include "format.h"
#include "Statement.h"

const int CStatement::C_STATEMENT_NORMAL_TYPE           = 1;
const int CStatement::C_STATEMENT_CONTROL_TYPE          = 2;
const int CStatement::C_STATEMENT_IF_CONTROL_TYPE       = 3;
const int CStatement::C_STATEMENT_DO_CONTROL_TYPE       = 4;
const int CStatement::C_STATEMENT_COMPLEX_TYPE          = 5;
const int CStatement::C_STATEMENT_FUNCTION_TYPE         = 6;
const int CStatement::C_STATEMENT_CLASS_TYPE            = 7;
const int CStatement::C_STATEMENT_STRUCT_TYPE           = 8;
const int CStatement::C_STATEMENT_UNION_TYPE            = 9;
const int CStatement::C_STATEMENT_ENUM_TYPE             = 10;
const int CStatement::C_STATEMENT_TYPEDEF_TYPE          = 11;
const int CStatement::C_STATEMENT_COMMENT_TYPE          = 12;
const int CStatement::C_STATEMENT_LINE_COMMENT_TYPE     = 13;
const int CStatement::C_STATEMENT_PRE_PROCESSOR_TYPE    = 14;
const int CStatement::C_STATEMENT_CASE_TYPE             = 15;
const int CStatement::C_STATEMENT_LABEL_TYPE            = 16;
const int CStatement::C_STATEMENT_CLASS_LABEL_TYPE      = 17;
const int CStatement::C_STATEMENT_PHP_TAG_TYPE          = 18;
const int CStatement::C_STATEMENT_TEMPLATE_TYPE         = 19;



CStatement::CStatement(void)
{
    m_tokens = NULL;
    m_indent = 0;
}

CStatement::~CStatement(void)
{
    DELETE_CONTAINER(m_tokens);
}

int CStatement::getType(void)
{
    return C_STATEMENT_NORMAL_TYPE;
}

string CStatement::toString()
{
    if (m_tokens != NULL) {
        CParser *sp  = CParser::getInstance();
        string space = getNumSpace(getIndent());
        int size     = m_tokens->size();
        vector<CTwin *> *pTwinSet = new vector<CTwin *>;
        m_tokens->initTwinSet(pTwinSet);
        size         = m_tokens->size();
        int index    = m_tokens->getNextNotEmptyTokenIndex(-1);
        string s     = space;
        if (index >= 0 && index < size ) {
            string startName = m_tokens->getToken(index)->getName();
            if (0 && sp->strInVector(startName, sp->splitTokens)) {
                s +=  startName + string("\n") + space;
            } else {
                s += startName;
            }
        }
        while (index < size) {
            int nindex = m_tokens->getNextNotEmptyTokenIndex(index);
            if (nindex > 0) {
                string name = m_tokens->getToken(nindex)->getName();
                if (name == CParser::C_OPEN_BRACKET) { //��ͨ���������{, ���{ǰ����=��)�Լ�����try,else֮��Ĺؼ���,����Ϊ�Ǹ������
                    int pindex = m_tokens->getPrevNotEmptyTokenIndex(nindex);
                    string pname = string();
                    if (pindex >= 0)
                        pname = strtolower(m_tokens->getToken(pindex)->getName());
                    if (pname == string(")") || pname == string("=") || pname == string("else") || pname == string("try")) {
                        int closeindex = m_tokens->getTwinIndex(pTwinSet, nindex);
                        CTokenSet* p = m_tokens->getChildSet(nindex, closeindex);
                        CStatement *sta = new CComplexStatement();
                        sta->setTokenSet(p);
                        sta->setIndent(getIndent());
                        s += " " + sta->toString();
                        index = closeindex;
                    } else {
                        int closeindex = m_tokens->getTwinIndex(pTwinSet, nindex);
                        CTokenSet* p = m_tokens->getChildSet(nindex, closeindex);
                        s += p->toString();
                        index = closeindex;
                    }

                } else if (nindex > index + 1) {
                    if (0 && sp->strInVector(name, sp->splitTokens)) {
                        s += string("\n") + space + name+ string("\n") + space;
                    } else {
                        s += " " + name;
                    }
                    index = nindex;
                } else if (nindex == index + 1) {//��ǰtoken����һ�����ǿ�
                    //if (false && sp->strInVector(name, sp->splitTokens)) {
                    //    s += string("\n") + space + name + string("\n") + space;
                    //} else
                        //s += " " + name; //���Ϊ�˵�������token list,����ָ���
                    s += name;
                    index = nindex;
                }
            } else {
                break;
            }
        }
        return s;
    } else {
        return string();
    }
}

void CStatement::setTokenSet(CTokenSet* tokens)
{
    m_tokens = tokens;
}

int CStatement::getIndent(void)
{
    return m_indent;
}

int CStatement::setIndent(int indent)
{
    m_indent = indent;
    return m_indent;
}

string CStatement::replaceName(string name)
{
    return CParser::getInstance()->mapName(name);
}

string CStatement::getClassName()
{
    return string("CStatement");
}