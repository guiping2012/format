// TokenSet.cpp: implementation of the CTokenSet class.
//
//////////////////////////////////////////////////////////////////////
#include "format.h"

#define PRINT_INDEV_V(v)  {int maxsize = (v)->size();for(int ii=0;ii<maxsize;ii++) cout << (*(v))[ii] <<":"<< getToken((*(v))[ii])->toString()<<endl; cout << "**" <<endl;}
#define PRINT_TOKEN_V(v)  {int maxsize = (v)->size();for(int ii=0;ii<maxsize;ii++) cout << ((*(v))[ii])->getStartIndex() << ":" << getToken(((*(v))[ii])->getStartIndex())->toString() \
    << "    "<< ((*(v))[ii])->getEndIndex() << ":"<< getToken(((*(v))[ii])->getEndIndex())->toString() << endl;cout << "**" <<endl;}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTokenSet::CTokenSet()
{
    pTokens = new vector<CToken *>;
}

CTokenSet::~CTokenSet()
{
    DELETE_CONTAINER(pTokens);
}

CTokenSet* CTokenSet::push_back(CToken *pToken)
{
    pTokens->push_back(pToken);
    return this;
}

string CTokenSet::toString()
{
    string str = string();
    int size = pTokens->size();
    for (int i=0; i < size; i++) {
        CToken *t = (*pTokens)[i];
        str += t->toString();
    }
    return str;
}

int CTokenSet::size()
{
    return pTokens->size();
}
bool CTokenSet::isEmpty()
{
    return pTokens->empty();
}
vector<CToken *> *CTokenSet::getTokens()
{
    return pTokens;
}
void CTokenSet::appendTokenSet(CTokenSet* sTokenSet)
{
    vector<CToken *> *sTokens = sTokenSet->getTokens();
    int size = sTokens->size();
    for (int i=0;i<size;i++)
        pTokens->push_back((*sTokens)[i]);
}
CToken* CTokenSet::getToken(int i)
{
    if (pTokens != NULL) {
        int maxTokenNum = pTokens->size();
        if (i >= 0 && i < maxTokenNum)
            return (*pTokens)[i];
        else if (i < 0 && maxTokenNum + i >= 0) {
            return (*pTokens)[maxTokenNum + i];
        } else
            return new CToken();
            //return NULL;
    }
    else
        return new CToken();
        //return NULL;
}

CTokenSet* CTokenSet::getChildSet(int start,int end)
{
    CTokenSet *set = new CTokenSet();
    for (int i=start; i<=end;i++) {
        CToken *pToken = getToken(i);
        if (pToken != NULL)  {
            set->push_back(pToken);
        }
    }
    return set;
}
CToken *CTokenSet::getEndToken()
{
    int ret = getPrevNotEmptyTokenIndex(size());
    if (ret >0) {
        return getToken(ret);
    } else {
        return new CToken();
    }
}
CToken *CTokenSet::getStartToken()
{
    int ret = getNextNotEmptyTokenIndex(-1);
    if (ret >0) {
        return getToken(ret);
    } else {
        return new CToken();
    }
}
int CTokenSet::getNextEnterTokenIndex(int i)
{
    int ret = -1;
    if (pTokens != NULL) {
        int maxTokenNum = pTokens->size();
        for (int j=i+1;j<maxTokenNum; j++) {
            if (getToken(j)->toString() == string("\n")) {
                ret = j;
                break;
            }
        }
    }
    return ret;
}
//
// 获取i位置下一个不是空(\r \t \n ' ')的token索引
//
int CTokenSet::getNextNotEmptyTokenIndex(int i)
{
    int ret = -1;
    if (pTokens != NULL) {
        int maxTokenNum = pTokens->size();
        for (int j=i+1;j<maxTokenNum; j++) {
            if (!getToken(j)->isEmpty()) {
                ret = j;
                break;
            }

        }
    }
    return ret;
}


//
// 获取i位置上一个不是空(\r \t \n ' ')的token索引
//
int CTokenSet::getPrevNotEmptyTokenIndex(int i)
{
    int ret = -1;
    if (pTokens != NULL) {
        for (int j=i-1;j>=0; j--) {
            if (!getToken(j)->isEmpty()) {
                ret = j;
                break;
            }

        }
    }
    return ret;
}
int CTokenSet::getTwinIndex(vector<CTwin*>* pTwinSet, int start)
{
    int end = -1;
    if (pTwinSet != NULL) {
        int maxTwinSize = pTwinSet->size();
        for (int i = 0; i < maxTwinSize; i++) {
            CTwin *pTwin = (*pTwinSet)[i];
            if (pTwin->getStartIndex() == start)
                end = pTwin->getEndIndex();
        }
    }
    return end;
}

/**
 * 暂时只考虑js代码和php代码，目前对于c代码的#ifdef, #if分析不好
 *
 *  功能解释：
 *        源文件分隔成一个一个的token 集合后，初始化一遍，把所有{}, <>, [],（#ifdef,#endif) (#if #endif)等token组 （twin）的序号记录下来
 *        分析tokenset中， token="}" 和token=";"的位置，当作语句的分隔，对于"}", 如果之后非空的toekn是"," 或者";",那么认为该token不是语句的结束
 *     下一个才可能是
 *
 */
void  CTokenSet::initStatementSet(vector<CStatement *> * pStatementSet, int indent)
{
    if (pStatementSet != NULL) {
        vector<CTwin *> *pTwinSet = new vector<CTwin *>;
        initTwinSet(pTwinSet);
        vector <int>  *pTokenSepIndex = new vector<int>; //分隔符号索引
        int size = pTokens->size();
        int i;
        for (i=0; i<size;i++) {
            string name = getToken(i)->getName();
            int type = getToken(i)->getType();
            if (name == CParser::C_OPEN_TINEPAREN
               || name == CParser::C_OPEN_PAREN
               || name == CParser::C_OPEN_BLPAREN) {
                   int ii = getTwinIndex(pTwinSet, i);
                   if (ii>0) {
                       i = ii;
                    continue;
                   }
            }
            if (type == CToken::C_TOKEN_COMMENT_TYPE || type == CToken::C_TOKEN_LINE_COMMENT_TYPE) {
                pTokenSepIndex->push_back(i);
            } else if (name == CParser::C_SEMICOLON) {
                pTokenSepIndex->push_back(i);
            } else if (name == CParser::C_OPEN_BRACKET) {
                i = getTwinIndex(pTwinSet, i);
                pTokenSepIndex->push_back(i);
            } else if (name == CParser::C_PHP_FULL_LTAG) {
                pTokenSepIndex->push_back(i);
            }
        }
        size = pTokenSepIndex->size();
        vector <int>  *pNewTokenSepIndex = new vector<int>; //分隔符号新索引，去掉}后面是,或者;的情况
        for (i=0; i<size; i++) {
            int index = (*pTokenSepIndex)[i];
            string name = getToken(index)->getName();
            int type = getToken(index)->getType();
            if (name == CParser::C_SEMICOLON || name == CParser::C_PHP_FULL_LTAG) {
                pNewTokenSepIndex->push_back(index);
            } else if (name == CParser::C_CLOSE_BRACKET) {
                int nindex = getNextNotEmptyTokenIndex(index);
                if (nindex > 0) {
                    name = getToken(nindex)->getName();
                    if (name != CParser::C_SEMICOLON && name != CParser::C_COMMA) { //},
                        pNewTokenSepIndex->push_back(index);
                    }
                } else {
                    pNewTokenSepIndex->push_back(index);
                }
            } else if (type == CToken::C_TOKEN_COMMENT_TYPE || type == CToken::C_TOKEN_LINE_COMMENT_TYPE) {
                pNewTokenSepIndex->push_back(index);
            }
        }
        size = pNewTokenSepIndex->size();
        if (pNewTokenSepIndex->empty()) {
            CTokenSet* p = getChildSet(0,  pTokens->size() -1);
            CStatement *sta = new CStatement();
            sta->setTokenSet(p);
            sta->setIndent(indent);
            pStatementSet->push_back(sta);
        } else {
            int start = 0;
            int end = 0;
            for (i=0; i<size; i++) {
                end = (*pNewTokenSepIndex)[i];
                CTokenSet* p = getChildSet(start, end);
                CStatement *sta = new CStatement();
                sta->setTokenSet(p);
                sta->setIndent(indent);
                pStatementSet->push_back(sta);
                start = end + 1;
            }
            size = pTokens->size();
            if (start < size) {
                end = getPrevNotEmptyTokenIndex(size);
                if (end > start) {
                    CTokenSet* p = getChildSet(start, end);
                    CStatement *sta = new CStatement();
                    sta->setTokenSet(p);
                    sta->setIndent(indent);
                    pStatementSet->push_back(sta);
                }
            }
        }
    }
}
//特殊处理：如果是javascript脚本，并且有正则表达式，例如：str.replace(/)}]/)，这些符号就必须跳过
void  CTokenSet::initTwinSet(vector<CTwin *> * pTwinSet)
{
    if (pTwinSet != NULL) {
        int maxTokenNum = pTokens->size();
        for (int i = 0; i < maxTokenNum; i++) {
            CToken *pCurrToken = getToken(i);
            string name = pCurrToken->getName();
            if (name == CParser::C_OPEN_BRACKET // name="{"
                    || name == CParser::C_OPEN_PAREN // name="("
                    || name == CParser::C_OPEN_BLPAREN) { // name="["
                CTwin *pTwin = new CTwin();
                pTwin->setStartIndex(i);
                pTwinSet->push_back(pTwin);
            } else if (name == CParser::C_BAR_IF // name="if"
                    || name == CParser::C_BAR_IFDEF // name="ifdef"
                    || name == CParser::C_BAR_IFNDEF){ // name="ifndef
                CToken *preToken = getToken(i - 1);
                if (preToken != NULL && preToken->getName() == CParser::C_BAR) {
                    CTwin *pTwin = new CTwin();
                    pTwin->setStartIndex(i);
                    pTwinSet->push_back(pTwin);
                }
            } else if (name == CParser::C_OPEN_TINEPAREN) { // name="<" 考虑<的情况
                CToken *preToken = getToken(i - 1);
                if (preToken != NULL && preToken->getName() == CParser::C_BAR_INCLUDE) {
                    CTwin *pTwin = new CTwin();
                    pTwin->setStartIndex(i);
                    int j;
                    for (j = i + 1; j < maxTokenNum; j++) {
                        CToken *pEndToken = getToken(j);
                        if (pEndToken->getName() == CParser::C_CLOSE_TINEPAREN) {
                            pTwin->setEndIndex(j);
                            break;
                        }
                    }
                    pTwinSet->push_back(pTwin);
                    i = j;
                    continue;
                } else {//不是include之后的<>， 可能为模板或者条件判断符
                    bool isInTemplate = true; //初始认为是template
                    int templateDepth = 0;
                    int j;
                    CTwin *pTemplateTwin = new CTwin();
                    pTemplateTwin->setStartIndex(i);
                    for (j = i; j < maxTokenNum; j++) {
                        CToken *pToken1 = getToken(j);
                        string name1 = pToken1->getName();
                        int type = pToken1->getType();
                        if (name1 == CParser::C_OPEN_TINEPAREN) {
                            templateDepth++;
                        } else if (name1 == CParser::C_CLOSE_TINEPAREN) {
                            templateDepth --;
                            if (templateDepth == 0) {
                                pTemplateTwin->setEndIndex(j);
                                break;
                            }
                        }
                        else if (name1 == CParser::C_COMMA //<int, char>
                                || name1 == CParser::C_BIT_AND //<int&>
                                || name1 == CParser::C_MULT //<int*>
                                || name1 == CParser::C_COLON_COLON) {//<std::string>

                            continue;
                        }
                        else if (type == CToken::C_TOKEN_COMMENT_TYPE) { //允许模板之间有注释

                            continue;
                        }
                        else if (type != CToken::C_TOKEN_NORMAL_TYPE) { //其他情况只允许(普通类型)字母或数字标识符
                            isInTemplate = false;
                            break;
                        }
                    }
                    if (isInTemplate) {
                        pTwinSet->push_back(pTemplateTwin);
                    }
                    else {
                        DELETE_CONTAINER(pTemplateTwin);
                    }
                }
            } else if (name == CParser::C_BAR_ENDIF) {  // name="endif"
                CToken *preToken = getToken(i - 1);
                if (preToken != NULL && preToken->getName() == CParser::C_BAR) {
                    int max = pTwinSet->size();
                    for (int j = max - 1; j >= 0; j--) {
                        CTwin *ptwin = (*pTwinSet)[j];
                        if (!ptwin->hasEnd() && ptwin->hasStart()) {
                            string ltokenName = getToken(ptwin->getStartIndex())->getName();
                            if (ltokenName == CParser::C_BAR_IF // lefttokenname="if"
                                    || ltokenName == CParser::C_BAR_IFDEF // lefttokenname="ifdef"
                                    || ltokenName == CParser::C_BAR_IFNDEF){ // lefttokenname="ifndef
                                //ptwin->setRightToken(pCurrToken);
                                ((*pTwinSet)[j])->setEndIndex(i);
                                break;
                            }
                        }
                    }
                }
            } else if (name == CParser::C_CLOSE_BRACKET // name="}"
                    || name == CParser::C_CLOSE_PAREN // name=")"
                    || name == CParser::C_CLOSE_BLPAREN) { // name="]"
                int max = pTwinSet->size();
                for (int j = max - 1; j >= 0; j--) {
                    CTwin *ptwin = (*pTwinSet)[j];
                    if (!ptwin->hasEnd() && ptwin->hasStart()) {
                        string ltokenName = getToken(ptwin->getStartIndex())->getName();
                        if ((name == CParser::C_CLOSE_BRACKET && ltokenName == CParser::C_OPEN_BRACKET)
                                || (name == CParser::C_CLOSE_PAREN && ltokenName == CParser::C_OPEN_PAREN)
                                || (name == CParser::C_CLOSE_BLPAREN && ltokenName == CParser::C_OPEN_BLPAREN)) {
                            //ptwin->setRightToken(pCurrToken);
                            //((*pTwinSet)[j])->setRightToken(pCurrToken);
                            ((*pTwinSet)[j])->setEndIndex(i);
                            break;
                        }
                    }
                }
            }
        }
    }
}
vector<CTokenSet *> *CTokenSet::getHtmlTagSet()
{
    vector<CTokenSet *> * pHtmlTagSet = new vector<CTokenSet *>;
    int size = pTokens->size();
    int i,j;
    int start = 0;
    int end = 0;
    for (i=0; i<size;i++) {
        string name = getToken(i)->getName();
        if (name == CParser::C_OPEN_TINEPAREN) {//检查token中包含'<'
            string nextname = strtolower(getToken(i+1)->getName());
            for (j = i+1; j < size; j++) {
                CToken *pToken1 = getToken(j);
                string name1 = pToken1->getName();
                if (name1 == CParser::C_CLOSE_TINEPAREN) {
                    end = j;
                    break;
                }
            }
            CTokenSet *p1 = getChildSet(start, i-1);
            CTokenSet *p2 = getChildSet(i+1, end-1);
            CHtmlTag *pTag = new CHtmlTag();
            pTag->setTokenSet(p2);
            pHtmlTagSet->push_back(p1);
            pHtmlTagSet->push_back(pTag);
            start = end + 1;
            end = start;
            if (nextname == string("script")) { //单独处理javascript
                for (j = end; j < size; j++) {
                    string s1 = strtolower(getToken(j)->getName());
                    string s2 = strtolower(getToken(j+1)->getName());
                    string s3 = strtolower(getToken(j+2)->getName());
                    if (s1 == CParser::C_OPEN_TINEPAREN && s2 == string("/") && s3 == string("script")) {
                        int k;
                        for (k=j+3; k<size; k++) {
                            string s4 = getToken(k)->getName();
                            if (s4 == CParser::C_CLOSE_TINEPAREN) {
                                CTokenSet *p3 = getChildSet(start, j - 1);
                                CTokenSet *p4 = getChildSet(j+1, k-1);
                                CHtmlTag *pTag1 = new CHtmlTag();
                                pTag1->setTokenSet(p4);
                                pHtmlTagSet->push_back(p3);
                                pHtmlTagSet->push_back(pTag1);
                                start = k+1;
                                end = start;
                                i = start;
                                break;
                            }
                        }
                        break;
                    }
                }
            } else if (nextname == string("pre")) { //单独处理pre语句，pre里面的内容不进行处理，全部认为是html text类型
                bool findPreClose = false; //pre元素与其他不同，如果没有</pre>结束标志，则认为全部都是pre内容
                int preDepth = 0; //可能嵌套 <pre><pre></pre></pre>
                for (j = end; j < size; j++) {
                    string s1 = strtolower(getToken(j)->getName());
                    string s2 = strtolower(getToken(j+1)->getName());
                    string s3 = strtolower(getToken(j+2)->getName());
                    if (s1 == CParser::C_OPEN_TINEPAREN && s2 == string("pre")) {
                        preDepth ++;
                        j += 2;//跳过<pre>
                    } else if (s1 == CParser::C_OPEN_TINEPAREN && s2 == string("/") && s3 == string("pre")) {
                        if (preDepth > 0) {
                            preDepth --;
                            j += 2;
                        } else {
                            int k;
                            for (k=j+3; k<size; k++) {
                                string s4 = getToken(k)->getName();
                                if (s4 == CParser::C_CLOSE_TINEPAREN) {
                                    CTokenSet *p3 = getChildSet(start, j - 1);
                                    CTokenSet *p4 = getChildSet(j+1, k-1);
                                    CHtmlTag *pTag1 = new CHtmlTag();
                                    pTag1->setTokenSet(p4);
                                    pHtmlTagSet->push_back(p3);
                                    pHtmlTagSet->push_back(pTag1);
                                    start = k+1;
                                    end = start;
                                    i = start;
                                    findPreClose = true;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                if (!findPreClose) {//没有找到</pre>,则认为从<pre>后面到结束部分全部认为是<pre>的内容
                    CTokenSet *p3 = getChildSet(start, size - 1);
                    pHtmlTagSet->push_back(p3);
                    start = size;
                }
            }else {
                i = start;
            }
        }
    }
    if (start < size) {
        CTokenSet *p5 = getChildSet(start, size - 1);
        pHtmlTagSet->push_back(p5);
    }
    return pHtmlTagSet;
}

void CTokenSet::initHtmlElements(vector <CHtmlElement*>*pElementSet)
{
    DEBUG(" CTokenSet::initHtmlElements");
    vector<CTokenSet *> * pHtmlTags = getHtmlTagSet();
    /*for(int i=0;i<pHtmlTags->size();i++) {
        (*pHtmlTags)[i]->debugShow();
    } */
    initHtmlElementsFromTags(pElementSet, pHtmlTags);
}
void CTokenSet::initHtmlElementsFromTags(vector <CHtmlElement*>* pElementSet, vector <CTokenSet*>*pHtmlTags)
{
    DEBUG(" CTokenSet::initHtmlElementsFromTags");
    if (pHtmlTags != NULL) {
        int size=pHtmlTags->size();
        map<int,int> *pTwinMap = new map<int,int>;
        for (int i=0; i<size;i++) {
            CTokenSet *pSet = (*pHtmlTags)[i];
            if (pSet->getClassName() == string("CHtmlTag")) {
                CHtmlTag *pTag = (CHtmlTag *)pSet;
                string tag = pTag->getTagName();
                if (pTag->getType() == CHtmlTag::HTML_OPEN_TAG) {
                    (*pTwinMap)[i] = -1;
                } else if (pTag->getType() == CHtmlTag::HTML_CLOSE_TAG) {
                    map<int,int>::reverse_iterator it;
                    for(it= pTwinMap->rbegin(); it != pTwinMap->rend(); it++) {
                        string ltokenName = ((CHtmlTag *)((*pHtmlTags)[it->first]))->getTagName();
                        if (ltokenName == tag && it->second == -1) {
                            (*pTwinMap)[it->first] = i;
                            break;
                        }
                    }
                }
            }
        }
        if (debug()) {
            map<int,int>::reverse_iterator it;
            for(it= pTwinMap->rbegin(); it != pTwinMap->rend(); it++) {
                cout << it->first << ":" << it->second << endl;
            }
        }
        for (int i=0; i<size;i++) {
            CTokenSet *pSet = (*pHtmlTags)[i];
            if (pSet->getClassName() == string("CHtmlTag")) {
                CHtmlTag *pTag = (CHtmlTag *)pSet;
                if (pTag->getType() == CHtmlTag::HTML_OPEN_TAG) {
                    int endIndex = (*pTwinMap)[i];
                    if (endIndex < 0) {
                        CHtmlElementSingle *pEle = new CHtmlElementSingle();
                        pEle->addStartTag(pTag);
                        pElementSet->push_back(pEle);
                    } else {
                        CHtmlElement *pEle = new CHtmlElement();
                        CHtmlTag *pEndTag = (CHtmlTag *)((*pHtmlTags)[endIndex]);
                        pEle->addStartTag(pTag);
                        pEle->addEndTag(pEndTag);
                        string tagName = strtolower(pTag->getTagName());
                        vector <CTokenSet*>* pChildrenTags = new vector <CTokenSet*>;
                        vector <CHtmlElement*>* pChildrenElements = new vector <CHtmlElement*>;
                        for (int j=i+1; j<endIndex; j++) {
                            pChildrenTags->push_back((*pHtmlTags)[j]);
                        }

                        if (strtolower(pTag->getTagName()) == string("script")) {
                            int scriptSize = pChildrenTags->size();
                            CTokenSet *pScriptSet = new CTokenSet();
                            for (int k=0;k<scriptSize;k++)
                                pScriptSet->appendTokenSet((*pChildrenTags)[k]);
                            CHtmlElementScript *pChildEle = new CHtmlElementScript();
                            pChildEle->setTokenSet(pScriptSet);
                            pEle->addChild(pChildEle);

                        } else {
                            initHtmlElementsFromTags(pChildrenElements, pChildrenTags);
                            pEle->setChildren(pChildrenElements);
                        }
                        pElementSet->push_back(pEle);
                        i = endIndex;

                    }
                } else {
                    CHtmlElementSingle *pEle = new CHtmlElementSingle();
                    pEle->addStartTag(pTag);
                    pElementSet->push_back(pEle);
                }
            } else {
                CHtmlElementText *pEle = new CHtmlElementText();
                pEle->setTokenSet(pSet);
                pElementSet->push_back(pEle);
            }
        }
    }
}
string CTokenSet::getClassName()
{
    return string("CTokenSet");
}
void CTokenSet::debugShow()
{
    cout << "=========Token List===========================" << endl;
    int size = pTokens->size();
    for (int i=0; i<size; i++) {
        cout << i<< ":" << (*pTokens)[i]->toDebugString() << endl;
    }
    cout << "----------------------------------------------" << endl;
}