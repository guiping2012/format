// Token.cpp: implementation of the CToken class.
//
//////////////////////////////////////////////////////////////////////

#include "format.h"
#include <sstream> 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const int CToken::C_TOKEN_NORMAL_TYPE       = 1;
const int CToken::C_TOKEN_SPLIT_TYPE        = 2;
const int CToken::C_TOKEN_OPERATE_TYPE      = 3;
const int CToken::C_TOKEN_POIONT_OP_TYPE    = 4;
const int CToken::C_TOKEN_REFER_OP_TYPE     = 5;
const int CToken::C_TOKEN_COMMENT_TYPE      = 6;
const int CToken::C_TOKEN_LINE_COMMENT_TYPE = 7;
const int CToken::C_TOKEN_QUOTE_TYPE        = 8;
const int CToken::C_TOKEN_SPACE_TYPE        = 9;
const int CToken::C_TOKEN_TAB_TYPE          = 10;
const int CToken::C_TOKEN_ENTER_TYPE        = 11;
const int CToken::C_TOKEN_CR_TYPE           = 12;

CToken::CToken()
{
    m_type = CToken::C_TOKEN_NORMAL_TYPE;
    //chs = new vector<char>;
    m_content = string();
}

CToken::CToken(char ch)
{
    m_type = CToken::C_TOKEN_NORMAL_TYPE;
    //chs = new vector<char>;
    //pushChar(ch);
    m_content += string(1, ch);
}
bool CToken::isEmpty()
{
    return ( m_type == CToken::C_TOKEN_SPACE_TYPE 
          || m_type == CToken::C_TOKEN_TAB_TYPE 
          || m_type == CToken::C_TOKEN_CR_TYPE 
          || m_type == CToken::C_TOKEN_ENTER_TYPE);
}
bool CToken::operator==(char *chs)
{
    return toString() == string(chs);
}
bool CToken::operator==(string str)
{
    return str == toString();
}
bool CToken::operator==(CToken *token)
{
    return token->toString() == toString();
}
void CToken::pushChar(char c)
{    
    //chs->push_back(c);
    m_content += string(1, c);
}
void CToken::setContent(string name)
{
    m_content = name;
}
void CToken::setName(string name)
{
    setContent(name);
}
string CToken::getName()
{
    return toString();
}
string CToken::toString()
{
    /*
    string s=string("");
    for (int i=0; i<chs->size();i++) {
        s += string(1,(*chs)[i]);
    }
    return s;
    */
    return m_content;
}
string CToken::toDebugString()
{
    return "¡¾" + toString() + "¡¿";
}
CToken::~CToken()
{   
    //DELETE_CONTAINER(chs);
}

char CToken::popChar()
{
    return 0;
}

int CToken::length()
{
    return m_content.length();
}

int CToken::getType()
{
    return m_type;
}

void CToken::setType(int t)
{
    m_type = t;

}
