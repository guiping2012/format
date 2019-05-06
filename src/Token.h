// Token.h: interface for the CToken class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOKEN_H__3E924FD2_D6C3_4695_A35A_BAEEEFFB1E5D__INCLUDED_)
#define AFX_TOKEN_H__3E924FD2_D6C3_4695_A35A_BAEEEFFB1E5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToken  
{
public:	
    static const int C_TOKEN_NORMAL_TYPE;
    static const int C_TOKEN_SPLIT_TYPE;
    static const int C_TOKEN_OPERATE_TYPE;
    static const int C_TOKEN_POIONT_OP_TYPE;
    static const int C_TOKEN_REFER_OP_TYPE;
    static const int C_TOKEN_COMMENT_TYPE;
    static const int C_TOKEN_LINE_COMMENT_TYPE;
    static const int C_TOKEN_QUOTE_TYPE;
    static const int C_TOKEN_SPACE_TYPE;
    static const int C_TOKEN_TAB_TYPE;
    static const int C_TOKEN_ENTER_TYPE;
    static const int C_TOKEN_CR_TYPE;

	int length();
	CToken();
    CToken(char ch);
    bool operator==(char *chs);
    bool operator==(string str);
    bool operator==(CToken *token);    
    bool isEmpty();
    void pushChar(char ch);
    char popChar();
    string toString();
    void setContent(string name);
    void setName(string name);
    string getName();
    string toDebugString();
	void setType(int t);
	int getType();

	virtual ~CToken();

protected:
	int m_type;
	string m_content;
    //vector <char> *chs;
};

#endif // !defined(AFX_TOKEN_H__3E924FD2_D6C3_4695_A35A_BAEEEFFB1E5D__INCLUDED_)
