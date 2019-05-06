// TokenSet.h: interface for the CTokenSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOKENSET_H__461D2ED7_C3B5_4E76_BF25_948C54BAEA4F__INCLUDED_)
#define AFX_TOKENSET_H__461D2ED7_C3B5_4E76_BF25_948C54BAEA4F__INCLUDED_

#include "Token.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToken;
class CTwin;
class CHtmlElement;
class CHtmlElementText;
class CHtmlElementSingle;
class CHtmlElementScript;
class CHtmlTag;
class CTokenSet  
{
protected:
	vector<CToken *> *pTokens;    
public:
    void debugShow();
	int size();
    bool isEmpty();
	CTokenSet();
    CTokenSet* push_back(CToken*);    
    CTokenSet* getChildSet(int,int);    
    void initTwinSet(vector<CTwin *> *);    
    void initStatementSet(vector<CStatement *> *, int);
    //void initHtmlTags(vector<CTokenSet *> *);
    void initHtmlElements(vector <CHtmlElement*>*);  
    void initHtmlElementsFromTags(vector <CHtmlElement*>*, vector <CTokenSet*>*);
    vector<CTokenSet *> *getHtmlTagSet();


    void appendTokenSet(CTokenSet*);
    int getTwinIndex(vector<CTwin*>* pTwinSet, int start);
    int getNextNotEmptyTokenIndex(int);
    int getPrevNotEmptyTokenIndex(int);

    int getNextEnterTokenIndex(int);

    CToken *getEndToken();
    CToken *getStartToken();
    CToken *getToken(int);
    vector<CToken *> *getTokens();
    virtual string toString();
	virtual ~CTokenSet();
    virtual string getClassName();

};

#endif // !defined(AFX_TOKENSET_H__461D2ED7_C3B5_4E76_BF25_948C54BAEA4F__INCLUDED_)
