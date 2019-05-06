#include "format.h"
#include "Parser.h"

const string CParser::C_FOR               = string("for");
const string CParser::C_IF                = string("if");
const string CParser::C_ELSE              = string("else");
const string CParser::C_DO                = string("do");
const string CParser::C_WHILE             = string("while");
const string CParser::C_SWITCH            = string("switch");
const string CParser::C_CASE              = string("case");
const string CParser::C_BREAK             = string("break");
const string CParser::C_DEFAULT           = string("default");
const string CParser::C_CLASS             = string("class");
const string CParser::C_STRUCT            = string("struct");
const string CParser::C_UNION             = string("union");
const string CParser::C_ENUM              = string("enum");
const string CParser::C_TYPEDEF           = string("typedef");
const string CParser::C_INTERFACE         = string("interface");
const string CParser::C_NAMESPACE         = string("namespace");
const string CParser::C_EXTERN            = string("extern");
const string CParser::C_PUBLIC            = string("public");
const string CParser::C_PROTECTED         = string("protected");
const string CParser::C_PRIVATE           = string("private");
const string CParser::C_CONST             = string("const");
const string CParser::C_VIRTUAL           = string("virtual");
const string CParser::C_STATIC            = string("static");
const string CParser::C_SYNCHRONIZED      = string("synchronized");
const string CParser::C_OPERATOR          = string("operator");
const string CParser::C_TEMPLATE          = string("template");
const string CParser::C_GOTO              = string("goto");
const string CParser::C_TRY               = string("try");
const string CParser::C_CATCH             = string("catch");
const string CParser::C_FINALLY           = string("finally");
const string CParser::C_THROWS            = string("throws");
const string CParser::C_ASM               = string("asm");
const string CParser::C_LOCK              = string("lock");
const string CParser::C_UNSAFE            = string("unsafe");
const string CParser::C_RETURN            = string("return");
const string CParser::C_EXTERN_C          = string("EXTERN_C");
const string CParser::C_BAR_DEFINE        = string("define");
const string CParser::C_BAR_UNDEF         = string("undef");
const string CParser::C_BAR_INCLUDE       = string("include");
const string CParser::C_BAR_IF            = string("if");
const string CParser::C_BAR_IFDEF         = string("ifdef");
const string CParser::C_BAR_IFNDEF        = string("ifndef");
const string CParser::C_BAR_ELSE          = string("else");
const string CParser::C_BAR_ENDIF         = string("endif");
const string CParser::C_BAR_ERROR         = string("error");
const string CParser::C_BAR_ELIF          = string("elif");
const string CParser::C_BAR_LINE          = string("line");
const string CParser::C_BAR_PRAGMA        = string("pragma");
const string CParser::C_BAR               = string("#");
const string CParser::C_BAR_BAR           = string("##");
const string CParser::C_DOT               = string(".");
const string CParser::C_OPEN_BRACKET      = string("{");
const string CParser::C_CLOSE_BRACKET     = string("}");
const string CParser::C_OPEN_PAREN        = string("(");
const string CParser::C_CLOSE_PAREN       = string(")");
const string CParser::C_OPEN_BLPAREN      = string("[");
const string CParser::C_CLOSE_BLPAREN     = string("]");
const string CParser::C_SINGLE_QUOTE      = string("'");
const string CParser::C_DOUBLE_QUOTE      = string("\"");
const string CParser::C_SLASHES           = string("\\");
const string CParser::C_OPEN_TINEPAREN    = string("<");
const string CParser::C_CLOSE_TINEPAREN   = string(">");
const string CParser::C_OPEN_LINE_COMMENT = string("//");
const string CParser::C_OPEN_COMMENT      = string("/*");
const string CParser::C_CLOSE_COMMENT     = string("*/");
const string CParser::C_ASSIGN            = string("=");
const string CParser::C_PLUS_ASSIGN       = string("+=");
const string CParser::C_MINUS_ASSIGN      = string("-=");
const string CParser::C_MULT_ASSIGN       = string("*=");
const string CParser::C_DIV_ASSIGN        = string("/=");
const string CParser::C_MOD_ASSIGN        = string("%=");
const string CParser::C_OR_ASSIGN         = string("|=");
const string CParser::C_AND_ASSIGN        = string("&=");
const string CParser::C_XOR_ASSIGN        = string("^=");
const string CParser::C_GR_GR_ASSIGN      = string(">>=");
const string CParser::C_LS_LS_ASSIGN      = string("<<=");
const string CParser::C_GR_GR_GR_ASSIGN   = string(">>>=");
const string CParser::C_LS_LS_LS_ASSIGN   = string("<<<=");
const string CParser::C_EQUAL             = string("==");
const string CParser::C_PLUS_PLUS         = string("++");
const string CParser::C_MINUS_MINUS       = string("--");
const string CParser::C_NOT_EQUAL         = string("!=");
const string CParser::C_GR_EQUAL          = string(">=");
const string CParser::C_GR_GR             = string(">>");
const string CParser::C_GR_GR_GR          = string(">>>");
const string CParser::C_LS_EQUAL          = string("<=");
const string CParser::C_LS_LS             = string("<<");
const string CParser::C_LS_LS_LS          = string("<<<");
const string CParser::C_ARROW             = string("->");
const string CParser::C_AND               = string("&&");
const string CParser::C_OR                = string("||");
const string CParser::C_COLON_COLON       = string("::");
const string CParser::C_PLUS              = string("+");
const string CParser::C_MINUS             = string("-");
const string CParser::C_MULT              = string("*");
const string CParser::C_DIV               = string("/");
const string CParser::C_MOD               = string("%");
const string CParser::C_GR                = string(">");
const string CParser::C_LS                = string("<");
const string CParser::C_NOT               = string("!");
const string CParser::C_BIT_OR            = string("|");
const string CParser::C_BIT_AND           = string("&");
const string CParser::C_BIT_NOT           = string("~");
const string CParser::C_BIT_XOR           = string("^");
const string CParser::C_QUESTION          = string("?");
const string CParser::C_COLON             = string(":");
const string CParser::C_COMMA             = string(",");
const string CParser::C_SEMICOLON         = string(";");
const string CParser::C_POINT_POINT       = string("**");
const string CParser::C_FOREACH           = string("foreach");

const string CParser::C_PHP_ARRAY_EVAL    = string("=>");
const string CParser::C_PHP_STR_ASSIGN    = string(".=");
const string CParser::C_PHP_LTAG          = string("<?");
const string CParser::C_PHP_FULL_LTAG     = string("<?php");
const string CParser::C_PHP_RTAG          = string("?>");

CParser* CParser::_instance = NULL ;



CParser::CParser(void)
{
    //separators = {"#", "{", "}", "(", ")", "[", "]", ";", "\\"}
    separators.push_back(&C_BAR);                 // "#"
    separators.push_back(&C_DOT);                 // "."
    separators.push_back(&C_OPEN_BRACKET);        // "{"
    separators.push_back(&C_CLOSE_BRACKET);       // "}"
    separators.push_back(&C_OPEN_PAREN);          // "("
    separators.push_back(&C_CLOSE_PAREN);         // ")"
    separators.push_back(&C_OPEN_BLPAREN);        // "["
    separators.push_back(&C_CLOSE_BLPAREN);       // "]"
    separators.push_back(&C_SEMICOLON);           // ";"
    separators.push_back(&C_SLASHES);             // "\\"

    //oneCharOPS={"+", "-", "*", "/", "%", ">", "<", "!", "&",
    //            "|", "~", "^", "?", ":", "=", ",", "."}
    oneCharOPS.push_back(&C_BAR);                 // "#"
    oneCharOPS.push_back(&C_DOT);                 // "."
    oneCharOPS.push_back(&C_OPEN_BRACKET);        // "{"
    oneCharOPS.push_back(&C_CLOSE_BRACKET);       // "}"
    oneCharOPS.push_back(&C_OPEN_PAREN);          // "("
    oneCharOPS.push_back(&C_CLOSE_PAREN);         // ")"
    oneCharOPS.push_back(&C_OPEN_BLPAREN);        // "["
    oneCharOPS.push_back(&C_CLOSE_BLPAREN);       // "]"
    oneCharOPS.push_back(&C_SEMICOLON);           // ";"

    oneCharOPS.push_back(&C_PLUS);                // "+"
    oneCharOPS.push_back(&C_MINUS);               // "-"
    oneCharOPS.push_back(&C_MULT);                // "*"
    oneCharOPS.push_back(&C_DIV);                 // "/"
    oneCharOPS.push_back(&C_MOD);                 // "%"
    oneCharOPS.push_back(&C_GR);                  // ">"
    oneCharOPS.push_back(&C_LS);                  // "<"
    oneCharOPS.push_back(&C_NOT);                 // "!"
    oneCharOPS.push_back(&C_BIT_OR);              // "&"
    oneCharOPS.push_back(&C_BIT_AND);             // "!"
    oneCharOPS.push_back(&C_BIT_NOT);             // "~"
    oneCharOPS.push_back(&C_BIT_XOR);             // "^"
    oneCharOPS.push_back(&C_QUESTION);            // "?"
    oneCharOPS.push_back(&C_COLON);               // ":"
    oneCharOPS.push_back(&C_ASSIGN);              // "="
    oneCharOPS.push_back(&C_COMMA);               // ","
    oneCharOPS.push_back(&C_DOT);                 // "."

    //twoCharOPS={"+=", "-=", "*=", "/=", "%=", "|=", "&=", "^=","==", "!=",
    //">=", "<=", "++", "--", ">>", "<<", "&&", "||", "::", "=>", "->", "**"}
    twoCharOPS.push_back(&C_PLUS_ASSIGN);         // "+="
    twoCharOPS.push_back(&C_MINUS_ASSIGN);        // "-="
    twoCharOPS.push_back(&C_MULT_ASSIGN);         // "*="
    twoCharOPS.push_back(&C_DIV_ASSIGN);          // "/="
    twoCharOPS.push_back(&C_MOD_ASSIGN);          // "%="
    twoCharOPS.push_back(&C_OR_ASSIGN);           // "|="
    twoCharOPS.push_back(&C_AND_ASSIGN);          // "&="
    twoCharOPS.push_back(&C_XOR_ASSIGN);          // "^="
    twoCharOPS.push_back(&C_EQUAL);               // "=="
    twoCharOPS.push_back(&C_NOT_EQUAL);           // "!="
    twoCharOPS.push_back(&C_GR_EQUAL);            // ">="
    twoCharOPS.push_back(&C_LS_EQUAL);            // "<="
    twoCharOPS.push_back(&C_PLUS_PLUS);           // "++"
    twoCharOPS.push_back(&C_MINUS_MINUS);         // "--"
    twoCharOPS.push_back(&C_GR_GR);               // ">>"
    twoCharOPS.push_back(&C_LS_LS);               // "<<"
    twoCharOPS.push_back(&C_AND);                 // "&&"
    twoCharOPS.push_back(&C_OR);                  // "||"
    twoCharOPS.push_back(&C_COLON_COLON);         // "::"
    twoCharOPS.push_back(&C_ARROW);               // "->"
    twoCharOPS.push_back(&C_POINT_POINT);         // "**"
    twoCharOPS.push_back(&C_BAR_BAR);             // "##"

    twoCharOPS.push_back(&C_PHP_ARRAY_EVAL);      // "=>"
    twoCharOPS.push_back(&C_PHP_STR_ASSIGN);      // ".="

    twoCharOPS.push_back(&C_PHP_LTAG);             // "<?"
    twoCharOPS.push_back(&C_PHP_RTAG);             // "<?"


    //threeCharOPS={">>=", "<<=", ">>>"}
    threeCharOPS.push_back(&C_GR_GR_ASSIGN);      // ">>="
    threeCharOPS.push_back(&C_LS_LS_ASSIGN);      // "<<="
    threeCharOPS.push_back(&C_LS_LS_LS);          // ">>>"

    //fourCharOPS={">>>=", "<<<=")
    fourCharOPS.push_back(&C_GR_GR_GR_ASSIGN);
    fourCharOPS.push_back(&C_LS_LS_LS_ASSIGN);

    //fiveCharOPS={"<?php"}
    fiveCharOPS.push_back(&C_PHP_FULL_LTAG);


    //splitTokens.push_back(&C_SEMICOLON);
    splitTokens.push_back(&C_IF);
    splitTokens.push_back(&C_WHILE);
    splitTokens.push_back(&C_DO);
    splitTokens.push_back(&C_FOR);
    splitTokens.push_back(&C_SWITCH);
    splitTokens.push_back(&C_FOREACH);
    splitTokens.push_back(&C_ELSE);
    splitTokens.push_back(&C_OPEN_BRACKET);
    splitTokens.push_back(&C_CLOSE_BRACKET);
    splitTokens.push_back(&C_BAR);
    splitTokens.push_back(&C_RETURN);
    splitTokens.push_back(&C_ASM);
    splitTokens.push_back(&C_THROWS);
    splitTokens.push_back(&C_PUBLIC);
    splitTokens.push_back(&C_PROTECTED);
    splitTokens.push_back(&C_PRIVATE);
    splitTokens.push_back(&C_GOTO);

    controlTokens.push_back(&C_IF);
    controlTokens.push_back(&C_WHILE);
    controlTokens.push_back(&C_DO);
    controlTokens.push_back(&C_FOR);
    controlTokens.push_back(&C_SWITCH);
    controlTokens.push_back(&C_FOREACH);

    htmlEvent.push_back(string("onactivate"));
    htmlEvent.push_back(string("onafterupdate"));
    htmlEvent.push_back(string("onbeforeactivate"));
    htmlEvent.push_back(string("onbeforecopy"));
    htmlEvent.push_back(string("onbeforecut"));
    htmlEvent.push_back(string("onbeforedeactivate"));
    htmlEvent.push_back(string("onbeforeeditfocus"));
    htmlEvent.push_back(string("onbeforepaste"));
    htmlEvent.push_back(string("onbeforeupdate"));
    htmlEvent.push_back(string("onblur"));
    htmlEvent.push_back(string("onclick"));
    htmlEvent.push_back(string("oncontextmenu"));
    htmlEvent.push_back(string("oncontrolselect"));
    htmlEvent.push_back(string("oncopy"));
    htmlEvent.push_back(string("oncut"));
    htmlEvent.push_back(string("ondblclick"));
    htmlEvent.push_back(string("ondeactivate"));
    htmlEvent.push_back(string("ondrag"));
    htmlEvent.push_back(string("ondragend"));
    htmlEvent.push_back(string("ondragenter"));
    htmlEvent.push_back(string("ondragleave"));
    htmlEvent.push_back(string("ondragover"));
    htmlEvent.push_back(string("ondragstart"));
    htmlEvent.push_back(string("ondrop"));
    htmlEvent.push_back(string("onerrorupdate"));
    htmlEvent.push_back(string("onfilterchange"));
    htmlEvent.push_back(string("onfocus"));
    htmlEvent.push_back(string("onfocusin"));
    htmlEvent.push_back(string("onfocusout"));
    htmlEvent.push_back(string("onhelp"));
    htmlEvent.push_back(string("onkeydown"));
    htmlEvent.push_back(string("onkeypress"));
    htmlEvent.push_back(string("onkeyup"));
    htmlEvent.push_back(string("onload"));
    htmlEvent.push_back(string("onlayoutcomplete"));
    htmlEvent.push_back(string("onlosecapture"));
    htmlEvent.push_back(string("onmousedown"));
    htmlEvent.push_back(string("onmouseenter"));
    htmlEvent.push_back(string("onmouseleave"));
    htmlEvent.push_back(string("onmousemove"));
    htmlEvent.push_back(string("onmouseout"));
    htmlEvent.push_back(string("onmouseover"));
    htmlEvent.push_back(string("onmouseup"));
    htmlEvent.push_back(string("onmousewheel"));
    htmlEvent.push_back(string("onmove"));
    htmlEvent.push_back(string("onmoveend"));
    htmlEvent.push_back(string("onmovestart"));
    htmlEvent.push_back(string("onpaste"));
    htmlEvent.push_back(string("onpropertychange"));
    htmlEvent.push_back(string("onreadystatechange"));
    htmlEvent.push_back(string("onresize"));
    htmlEvent.push_back(string("onresizeend"));
    htmlEvent.push_back(string("onresizestart"));
    htmlEvent.push_back(string("onscroll"));
    htmlEvent.push_back(string("onselectstart"));
    htmlEvent.push_back(string("ontimeerror"));

    pMap = new MAPSTR;

}

CParser *CParser::getInstance()
{
    if (_instance == NULL) {
        _instance = new CParser();
    }
    return _instance;
}
CParser::~CParser(void)
{
    DELETE_CONTAINER(pMap);
}
void CParser::setReplaceFile(string file)
{
    ifstream in(file.c_str());
    if (in) {
        string line;
        while (getline(in, line)) {
            if (line[0] == '#' || line[0] == ';')
                continue;
            vector<string> *pvline = explode(string(" "), line);
            string key = (*pvline)[0];
            string name = (*pvline)[1];
            addReplace(key, name);
        }
        in.close();
    }
}

void CParser::addReplace(string key, string name)
{
    if (key != string())
        (*pMap)[key] = name;
}
MAPSTR * CParser::getWordMap()
{
    return pMap;
}
string CParser::mapName(string name)
{
    if (pMap->find(name) != pMap->end())
        name = (*pMap)[name];
    return name;
}
CTokenSet * CParser::getTokenSetFromFile(string file, int type)
{
    string content = file_get_contents(file);
    return getTokenSetFromString(content, type);
}
CTokenSet * CParser::getTokenSetFromString(string content, int type)
{
    DEBUG(" CParser::getTokenSetFromString");
    CTokenSet * pTokenSet = new CTokenSet();
    parseString(pTokenSet, content, type);
    return pTokenSet;
}

bool CParser::strInVector(string str, vector < const string*> & vectors)
{
    int max = vectors.size();
    for (int i = 0; i < max; i++) {
        if (*vectors[i] == str)
            return true;
    }
    return false;
}

string CParser::formatHtmlString(string content)
{
    DEBUG(" CParser::formatHtmlString");
    string str = string();
    CTokenSet* pTokenSet = getTokenSetFromString(content, FORMAT_HTML);
    if (debug())
        pTokenSet->debugShow();
    replaceTokenSet(pTokenSet, FORMAT_HTML);
    vector <CHtmlElement*>* pElementSet = new vector <CHtmlElement*>;
    pTokenSet->initHtmlElements(pElementSet);
    int size = pElementSet->size();
    for(int i=0;i<size;i++) {
        CHtmlElement *pEle = (*pElementSet)[i];
        if (str == string())
            str += pEle->toString(0);
        else
            str = trim(str) + string("\n") + pEle->toString(0);
    }
    return trim(str);
}
string CParser::formatString(string content)
{
    DEBUG(" CParser::formatString...start");
    string str = string();
    CTokenSet* pTokenSet = getTokenSetFromString(content, FORMAT_C);
    if (debug())
        pTokenSet->debugShow();
    replaceTokenSet(pTokenSet, FORMAT_C);
    vector<CStatement *> * pStatementSet = new vector<CStatement *>;
    pTokenSet->initStatementSet(pStatementSet, 0);
    int size=pStatementSet->size();
    for (int i=0; i<size;i++) {
        str += (*pStatementSet)[i]->toString();
    }
    DEBUG(" CParser::formatString...end");
    return str;
}

string CParser::formatHtmlFile(string file)
{
    DEBUG(" CParser::formatHtmlFile");
    string content = file_get_contents(file);
    return formatHtmlString(content);
}
string CParser::formatFile(string file)
{
    DEBUG(" CParser::formatFile");
    string content = file_get_contents(file);
    return formatString(content);
}
string CParser::replaceOutputString(string file, int type)
{
    return getReplaceString(file_get_contents(file), type);
}
string CParser::getReplaceString(string content, int type)
{
    CTokenSet* pTokenSet = new CTokenSet();
    parseString(pTokenSet, content, type);
    vector<CToken*> *pTokens = pTokenSet->getTokens();
    int size = pTokens->size();
    string retContent = string();
    for (int i=0;i<size;i++) {
        string name = (*pTokens)[i]->toString();
        if (pMap->find(name) != pMap->end())
            name = (*pMap)[name];
        retContent += name;
    }
    return retContent;
}
bool CParser::replaceTokenSet(CTokenSet *pTokenSet, int type)
{
    int size = pTokenSet->size();
    bool tokenInHtmlTag = false;
    int eventIndex = -1; //存储onclick="D.test()", 类似的onlick,onload之后的调用的js代码的token索引，开始是-1,不存在
    for (int i=0;i<size;i++) {
        string name = pTokenSet->getToken(i)->toString();
        if (name == string("<") && !tokenInHtmlTag)
            tokenInHtmlTag = true;
        if (name == string(">") && tokenInHtmlTag)
            tokenInHtmlTag = false;

        if (tokenInHtmlTag && type == FORMAT_HTML && strInHtmlEvent(name)) {
            int nextIndex = pTokenSet->getNextNotEmptyTokenIndex(i);
            if (nextIndex > 0) {
                if (pTokenSet->getToken(nextIndex)->toString() == string("=")) {
                    int nextnextIndex = pTokenSet->getNextNotEmptyTokenIndex(nextIndex);
                    if (nextnextIndex > 0) {
                        eventIndex = nextnextIndex; //找到事件之后的=之后的token, 可能有bug,如果onload=test.a()，这样的没有引号引起来的会出问题
                    }
                }
            }
        }
        if (pMap->find(name) != pMap->end()) {
            pTokenSet->getToken(i)->setContent((*pMap)[name]);
        }
        if (eventIndex > 0 && eventIndex == i) {
            string eventContent = pTokenSet->getToken(i)->toString();
            if (pTokenSet->getToken(i)->getType() == CToken::C_TOKEN_QUOTE_TYPE) {
                string quotestr = string(1, eventContent[0]);
                eventContent = eventContent.substr(1,eventContent.length()-2);
                eventContent = quotestr +getReplaceString(eventContent, type)+quotestr;
                pTokenSet->getToken(i)->setContent(eventContent);
            } else {
                pTokenSet->getToken(i)->setContent(getReplaceString(eventContent, type));
            }
            eventIndex = -1; //重置eventIndex
        }
    }
    return false;
}
bool CParser::strInHtmlEvent(string name)
{
    string lname = strtolower(name);
    int size = htmlEvent.size();
    for (int i=0; i<size;i++) {
        if (lname == htmlEvent[i])
            return true;
    }
    return false;
}

/**
 *
 * 分析源代码content, 分解token列表， 特殊的：javascript正则表达式 模式
 *
 *   暂时定 左圆括号后跟‘/’符号，并且‘/’之后不是‘*’和‘/’的，以及‘=’号后面跟‘/’的称为模式token
 *
 *
 */
void CParser::parseString(CTokenSet* pTokenSet, string content, int type = FORMAT_C)
{
    #define PUSH_TOKEN   if (pToken->toString() != string("")) {if (strtolower(pToken->toString()) == string("script")) {if (pTokenSet->getToken(-1)->toString() == string("<")) charInHtmlScript = true; else if (pTokenSet->getToken(-1)->toString() == string("/") && pTokenSet->getToken(-2)->toString() == string("<")) charInHtmlScript = false; } pTokenSet->push_back(pToken); pToken = new CToken();}
    //#define PUSH_TOKEN   if (pToken->toString() != string("")) {DEBUG(pToken->toString());pTokenSet->push_back(pToken); pToken = new CToken();}

    bool inQuote = false;
    bool inLineComment = false;
    bool inComment = false;
    bool charInHtmlTag = false;
    bool charInHtmlScript = false;
    char quoteChar = 0;
    int i;
    int maxCharNum = content.length();
    CToken *pToken = new CToken();

    for (i=0; i<maxCharNum; i++) {
        char currChar       = content[i];
        char nextChar       = (i<maxCharNum-1)?content[i+1]:0;
        char next2Char      = (i<maxCharNum-2)?content[i+2]:0;
        char next3Char      = (i<maxCharNum-3)?content[i+3]:0;
        char next4Char      = (i<maxCharNum-4)?content[i+4]:0;
        string oneCharStr   = string(1, currChar);
        string twoCharStr   = string("");
        string threeCharStr = string("");
        string fourCharStr  = string("");
        string fiveCharStr  = string("");
        if (next4Char > 0) {
            fiveCharStr += string(1, currChar) + string(1, nextChar) + string(1, next2Char) + string(1, next3Char) + string(1, next4Char);
        }
        if (next3Char > 0) {
            fourCharStr += string(1, currChar) + string(1, nextChar) + string(1, next2Char) + string(1, next3Char);
        }
        if(next2Char > 0) {
            threeCharStr += string(1, currChar) + string(1, nextChar) + string(1, next2Char);
        }
        if (nextChar>0) {
            twoCharStr += string(1, currChar) + string(1, nextChar);
        }
        if (type == FORMAT_HTML && currChar == '<' && !charInHtmlTag)  {
            charInHtmlTag = true;
        } else if (type == FORMAT_HTML && currChar == '>' && charInHtmlTag)  {
            charInHtmlTag = false;
        }

        if (currChar == '/' && nextChar != '*' && nextChar != '/' && type != FORMAT_HTML) {
            //增加对正则表达式的处理
            bool isRegExp = false;
            int iReg = i;
            char preChar = 0;
            while (--iReg >= 0) {  //检查当前/之前的字符是不是(或者=
                preChar = content[iReg];
                if (preChar != ' ' && preChar != '\n' && preChar != '\t' && preChar != '\r')
                    break;
            }
            if (preChar == '=' || preChar == '(') { //根据前一个非空字符,判断是否是正则表达式
                isRegExp = true;
            }
            if (isRegExp) { //是正则表达式，则找到/之后， 第二个/，作为结束，并且作为token存储起来
                iReg = 0;
                bool checkReg = false;
                for (int j=i+1; i<maxCharNum;j++) {
                    if (content[j] == '/') {
                        int slashNum = 0;
                        for (int k = j-1; k>=0; k--) {
                            if (content[k] != '\\')
                                break;
                            slashNum++;
                        }
                        if (slashNum % 2 == 0) {//说明是正则表达式结束标志
                            for (iReg = i; iReg <= j; iReg++) {
                                pToken->pushChar(content[iReg]);
                            }
                            checkReg = true;
                            PUSH_TOKEN;
                            i = j;
                            break;
                        }

                    }
                }
                if (checkReg) {
                    continue; //是正则表达式就继续
                }
            }

        }
        if (inComment) {
            if (currChar == '*' && nextChar == '/') {
                pToken->pushChar(currChar);
                pToken->pushChar(nextChar);
                pToken->setType(CToken::C_TOKEN_COMMENT_TYPE);
                PUSH_TOKEN;
                inComment = false;
                i++;
            } else {
                pToken->pushChar(currChar);
            }
            continue;
        }
        if (inLineComment) {
            if (i == maxCharNum - 1) {
                pToken->pushChar(currChar);
                pToken->setType(CToken::C_TOKEN_LINE_COMMENT_TYPE);
                PUSH_TOKEN;
                inLineComment = false;
            } else if (currChar == '\n') {
                pToken->setType(CToken::C_TOKEN_LINE_COMMENT_TYPE);
                PUSH_TOKEN;
                pToken->pushChar(currChar);
                pToken->setType(CToken::C_TOKEN_ENTER_TYPE);
                PUSH_TOKEN;
                inLineComment = false;
            } else {
                pToken->pushChar(currChar);
            }
            continue;
        }
        if (inQuote) {
            if (quoteChar == currChar) {
                int slashNum = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (content[j] != '\\')
                        break;
                    slashNum++;
                }
                if (slashNum % 2 == 0) {
                    pToken->setType(CToken::C_TOKEN_QUOTE_TYPE);
                    pToken->pushChar(currChar);
                    PUSH_TOKEN;
                    inQuote = false;
                    quoteChar = 0;
                } else {
                    pToken->pushChar(currChar);
                }
            } else {
                pToken->pushChar(currChar);
            }
            continue;
        }
        if (currChar == '/' && nextChar == '*' && type != FORMAT_HTML) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_COMMENT_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);

            inComment = true;
            i++;
            continue;
        }
        if (currChar == '/' && nextChar == '/' && type != FORMAT_HTML) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_LINE_COMMENT_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);

            inLineComment = true;
            i++;
            continue;
        }
        if (((type != FORMAT_HTML) || charInHtmlTag || charInHtmlScript) && (currChar == '"' || currChar == '\'')) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_QUOTE_TYPE);
            pToken->pushChar(currChar);

            inQuote = true;
            quoteChar = currChar;
            continue;
        }
        if (currChar == ' ' || currChar == '\t' || currChar == '\r' || currChar == '\n') {
            PUSH_TOKEN;
            if (currChar == ' ')
                pToken->setType(CToken::C_TOKEN_SPACE_TYPE);
            else if (currChar == '\t')
                pToken->setType(CToken::C_TOKEN_TAB_TYPE);
            else if (currChar == '\r')
                pToken->setType(CToken::C_TOKEN_CR_TYPE);
            else
                pToken->setType(CToken::C_TOKEN_ENTER_TYPE);

            for (int j=i; j<maxCharNum; j++) {
                if (content[j] != currChar) {
                    PUSH_TOKEN;
                    i = j-1;
                    break;
                } else {
                    pToken->pushChar(content[j]);
                }
            }
            continue;
        }
        if (fiveCharStr != string("") && strInVector(fiveCharStr, fiveCharOPS)) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_OPERATE_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);
            pToken->pushChar(next2Char);
            pToken->pushChar(next3Char);
            pToken->pushChar(next4Char);
            PUSH_TOKEN;
            i += 4;
            continue;
        } else if (fourCharStr != string("") && strInVector(fourCharStr, fourCharOPS)) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_OPERATE_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);
            pToken->pushChar(next2Char);
            pToken->pushChar(next3Char);
            PUSH_TOKEN;
            i += 3;
            continue;

        } else if (threeCharStr != string("") && strInVector(threeCharStr, threeCharOPS)) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_OPERATE_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);
            pToken->pushChar(next2Char);

            PUSH_TOKEN;
            i += 2;
            continue;
        } else if (twoCharStr != string("") && strInVector(twoCharStr, twoCharOPS)) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_OPERATE_TYPE);
            pToken->pushChar(currChar);
            pToken->pushChar(nextChar);
            PUSH_TOKEN;
            i += 1;
            continue;
        } else if (oneCharStr != string("") && strInVector(oneCharStr, oneCharOPS)) {
            PUSH_TOKEN;
            pToken->setType(CToken::C_TOKEN_OPERATE_TYPE);
            pToken->pushChar(currChar);
            PUSH_TOKEN;
            continue;
        } else {
            pToken->pushChar(currChar);
            continue;
        }

    }
    if (pToken->toString() != string("")) {
        pTokenSet->push_back(pToken);
    } else {
        delete pToken;
    }
}
