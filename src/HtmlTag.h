#ifndef C_HTML_TAG_H
#define C_HTML_TAG_H
#include "TokenSet.h"

class CHtmlTag :public CTokenSet
{
public:
    static const int HTML_OPEN_TAG;
    static const int HTML_CLOSE_TAG;
    static const int HTML_SINGLE_TAG;
    static const int HTML_DOC_TAG;
    void setTokenSet(CTokenSet*);
    CHtmlTag(void);
    int setType(int);
    int getType();
    string getTagName();
    virtual string getClassName();
    virtual string toString();
public:
    ~CHtmlTag(void);
protected:
    int _type;
    string _tag;
};

class CHtmlElement
{
protected:
    CHtmlTag* _startTag;
    CHtmlTag* _endTag;
    vector<CHtmlElement*>* _children;
public:
    CHtmlElement(void);
    virtual ~CHtmlElement(void);
    virtual string toString(int);
    virtual string getClassName();
    void addStartTag(CHtmlTag*);
    void addEndTag(CHtmlTag*);
    void addChild(CHtmlElement*);
    void setChildren(vector<CHtmlElement*>*);
};
class CHtmlElementText :public CHtmlElement
{
protected:
    CTokenSet *pTokenSet;
public:
    CHtmlElementText();
    virtual ~CHtmlElementText();
    void setTokenSet(CTokenSet *);
    virtual string toString(int);
    virtual string getClassName();

};
class CHtmlElementSingle :public CHtmlElement
{
public:
    CHtmlElementSingle();
    virtual ~CHtmlElementSingle();
    virtual string toString(int);
    virtual string getClassName();
};
class CHtmlElementScript :public CHtmlElementText
{
public:
    CHtmlElementScript();
    virtual ~CHtmlElementScript();
    virtual string toString(int);
    virtual string getClassName();
};
#endif
