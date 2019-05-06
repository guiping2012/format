#include "format.h"
#include "HtmlTag.h"

const int CHtmlTag::HTML_OPEN_TAG       = 1;
const int CHtmlTag::HTML_CLOSE_TAG      = 2;
const int CHtmlTag::HTML_SINGLE_TAG     = 3;
const int CHtmlTag::HTML_DOC_TAG        = 4;

CHtmlTag::CHtmlTag(void)
{    
}

CHtmlTag::~CHtmlTag(void)
{
}
int CHtmlTag::setType(int type)
{
    _type = type;
    return type;
}
int CHtmlTag::getType()
{
    return _type;
}
string CHtmlTag::getTagName()
{
    return _tag;
}
string CHtmlTag::getClassName()
{
    return string("CHtmlTag");
}
string CHtmlTag::toString()
{
    string str = string();
    int size = pTokens->size();
    for (int i=0; i < size; i++) {
        CToken *t = (*pTokens)[i];
        str += t->toString();
    }
    return "<" + str + ">";
}
void CHtmlTag::setTokenSet(CTokenSet *pSet)
{    
    if (!pSet->isEmpty()) {
        DEBUG("init htmlTag..");
        string sname = pSet->getToken(0)->toString();
        string ename = pSet->getEndToken()->toString();
        _tag = sname;
        DEBUG(string("sname=") + sname + string(",ename=") + ename);
        if (sname == string("/")) {
            _tag = pSet->getToken(1)->toString();            
            setType(HTML_CLOSE_TAG);            
        } else if (sname == string("!")) {
            _tag = pSet->getToken(1)->toString();
            setType(HTML_DOC_TAG);
        } else if (ename == string("/"))
            setType(HTML_SINGLE_TAG);
        else
            setType(HTML_OPEN_TAG);
        pTokens = pSet->getTokens();
    } else {
        _tag = string();
        setType(HTML_OPEN_TAG);
    }
}


CHtmlElement::CHtmlElement(void)
{
    _startTag = NULL;
    _endTag = NULL;
    _children = new vector<CHtmlElement*>;
}
CHtmlElement::~CHtmlElement(void)
{
    DELETE_CONTAINER(_children);
}
string CHtmlElement::toString(int indent)
{
    string content = string();
    string space = getNumSpace(indent);
    string childrenSpace = getNumSpace(indent + 2);
    int size = _children->size();
    int i;        
    string start = string(),end = string(), tag = string();
    if (_startTag != NULL) start= _startTag->toString();
    if (_startTag != NULL) tag = _startTag->getTagName();
    if (_startTag != NULL) end =  _endTag->toString();
    
    int childrenSize = _children->size();     
    
    if (childrenSize >= 1) {
        CHtmlElement *pEle0 = (*_children)[0];
        string className = pEle0->getClassName();
        if (className == string("CHtmlElementScript")) { 
            content = string("\n") + pEle0->toString(indent+2);
        } else if (className == string("CHtmlElementText")) {
            content = pEle0->toString(0);
        } else {
            content = string("\n") + childrenSpace + pEle0->toString(indent+2);
        }
        for (i=1;i<size;i++) {
            CHtmlElement *pEle = (*_children)[i];
            className = pEle->getClassName();
            if (className == string("CHtmlElementScript")) { 
                content = rtrim(content) + string("\n") + pEle->toString(indent+2);
            } else if (className == string("CHtmlElementText")) {
                content = rtrim(content) + pEle->toString(0);
            //} else if (content[content.length()] == '\n') {
                //content = childrenSpace + pEle->toString(indent+2);
            } else {
                content = rtrim(content) + string("\n") + childrenSpace + pEle->toString(indent+2);
            }
        }        
        content = rtrim(content) + string("\n");        
    }
    if (trim(content) == string())
        return start + end;
    else
        return start + content + space + end;
    
}
string CHtmlElement::getClassName()
{
    return string("CHtmlElement");
}
void CHtmlElement::addStartTag(CHtmlTag* startTag)
{
    _startTag = startTag;
}
void CHtmlElement::addEndTag(CHtmlTag* endTag)
{
    _endTag = endTag;
}
void CHtmlElement::addChild(CHtmlElement* child)
{
    _children->push_back(child);
}
void CHtmlElement::setChildren(vector<CHtmlElement*>* pHtmlElements)
{
    _children = pHtmlElements;
}

CHtmlElementText::CHtmlElementText()
{
    pTokenSet = NULL;
}
CHtmlElementText::~CHtmlElementText()
{
}
void CHtmlElementText::setTokenSet(CTokenSet *pSet)
{
    pTokenSet = pSet;
}
string CHtmlElementText::toString(int indent)
{
    string space = getNumSpace(indent);
    string content = string();    
    if (pTokenSet != NULL) {
        //content = space + trim(pTokenSet->toString());
        content = pTokenSet->toString();
    }
    return content;
}
string CHtmlElementText::getClassName()
{
    return string("CHtmlElementText");
}




CHtmlElementSingle::CHtmlElementSingle()
{

}
CHtmlElementSingle::~CHtmlElementSingle()
{
}
string CHtmlElementSingle::toString(int indent)
{
    string space = getNumSpace(indent);
    if (_startTag != NULL) {
        return _startTag->toString();
    } else {
        return string();
    }
}
string CHtmlElementSingle::getClassName()
{
    return string("CHtmlElementSingle");
}



CHtmlElementScript::CHtmlElementScript()
{    
}
CHtmlElementScript::~CHtmlElementScript()
{
}
string CHtmlElementScript::toString(int indent)
{
    string space = getNumSpace(indent);
    string content = string();
    if (pTokenSet != NULL) {
        vector<CStatement *> * pStatementSet = new vector<CStatement *>;
        pTokenSet->initStatementSet(pStatementSet, indent+2);
        int size=pStatementSet->size();
        string str = string();
        for (int i=0; i<size;i++) {
            str += (*pStatementSet)[i]->toString() + string("\n");            
        }
        DELETE_CONTAINER(pStatementSet);
        content += str;
    }
    if (trim(content) == string())
        content = string();
    return content;
}
string CHtmlElementScript::getClassName()
{
    return string("CHtmlElementScript");
}