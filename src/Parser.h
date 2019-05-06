// Token.h: interface for the CToken class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(C_PARSER_H)
#define C_PARSER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTokenSet;
class CToken;
class CStatement;
class CParser
{
public:
    vector<const string*> oneCharOPS;      //一元操作符集
    vector<const string*> twoCharOPS;      //二元操作符集
    vector<const string*> threeCharOPS;    //三元操作符集
    vector<const string*> fourCharOPS;     //四元操作符集
    vector<const string*> fiveCharOPS;     //五元操作符集
    vector<const string*> separators;      //分隔字符集
    vector<const string*> splitTokens;     //语句分开标志集
    vector<const string*> controlTokens;   //控制语句标志集合
protected:
    //CTokenSet *pTokenSet;
    MAPSTR *pMap;
    vector<string> htmlEvent;
    static CParser *_instance;
public:
    static const string C_FOR;
    static const string C_IF;
    static const string C_ELSE;
    static const string C_DO;
    static const string C_WHILE;
    static const string C_SWITCH;
    static const string C_CASE;
    static const string C_BREAK;
    static const string C_DEFAULT;
    static const string C_CLASS;
    static const string C_STRUCT;
    static const string C_UNION;
    static const string C_ENUM;
    static const string C_TYPEDEF;
    static const string C_INTERFACE;
    static const string C_NAMESPACE;
    static const string C_EXTERN;
    static const string C_PUBLIC;
    static const string C_PROTECTED;
    static const string C_PRIVATE;
    static const string C_CONST;
    static const string C_VIRTUAL;
    static const string C_STATIC;
    static const string C_SYNCHRONIZED;
    static const string C_OPERATOR;
    static const string C_TEMPLATE;
    static const string C_GOTO;
    static const string C_TRY;
    static const string C_CATCH;
    static const string C_FINALLY;
    static const string C_THROWS;
    static const string C_ASM;
    static const string C_LOCK;
    static const string C_UNSAFE;
    static const string C_RETURN;
    static const string C_EXTERN_C;
    static const string C_BAR_DEFINE;
    static const string C_BAR_UNDEF;
    static const string C_BAR_INCLUDE;
    static const string C_BAR_IF;
    static const string C_BAR_IFDEF;
    static const string C_BAR_IFNDEF;
    static const string C_BAR_ELSE;
    static const string C_BAR_ENDIF;
    static const string C_BAR_ERROR;
    static const string C_BAR_ELIF;
    static const string C_BAR_LINE;
    static const string C_BAR_PRAGMA;
    static const string C_BAR;
    static const string C_BAR_BAR;
    static const string C_DOT;
    static const string C_OPEN_BRACKET;
    static const string C_CLOSE_BRACKET;
    static const string C_OPEN_PAREN;
    static const string C_CLOSE_PAREN;
    static const string C_OPEN_BLPAREN;
    static const string C_CLOSE_BLPAREN;
    static const string C_SINGLE_QUOTE;
    static const string C_DOUBLE_QUOTE;
    static const string C_SLASHES;
    static const string C_OPEN_TINEPAREN;
    static const string C_CLOSE_TINEPAREN;
    static const string C_OPEN_LINE_COMMENT;
    static const string C_OPEN_COMMENT;
    static const string C_CLOSE_COMMENT;
    static const string C_ASSIGN;
    static const string C_PLUS_ASSIGN;
    static const string C_MINUS_ASSIGN;
    static const string C_MULT_ASSIGN;
    static const string C_DIV_ASSIGN;
    static const string C_MOD_ASSIGN;
    static const string C_OR_ASSIGN;
    static const string C_AND_ASSIGN;
    static const string C_XOR_ASSIGN;
    static const string C_GR_GR_ASSIGN;
    static const string C_LS_LS_ASSIGN;
    static const string C_GR_GR_GR_ASSIGN;
    static const string C_LS_LS_LS_ASSIGN;
    static const string C_EQUAL;
    static const string C_PLUS_PLUS;
    static const string C_MINUS_MINUS;
    static const string C_NOT_EQUAL;
    static const string C_GR_EQUAL;
    static const string C_GR_GR;
    static const string C_GR_GR_GR;
    static const string C_LS_EQUAL;
    static const string C_LS_LS;
    static const string C_LS_LS_LS;
    static const string C_ARROW;
    static const string C_AND;
    static const string C_OR;
    static const string C_COLON_COLON;
    static const string C_PLUS;
    static const string C_MINUS;
    static const string C_MULT;
    static const string C_DIV;
    static const string C_MOD;
    static const string C_GR;
    static const string C_LS;
    static const string C_NOT;
    static const string C_BIT_OR;
    static const string C_BIT_AND;
    static const string C_BIT_NOT;
    static const string C_BIT_XOR;
    static const string C_QUESTION;
    static const string C_COLON;
    static const string C_COMMA;
    static const string C_SEMICOLON;
    static const string C_POINT_POINT;
    static const string C_FOREACH;

    static const string C_PHP_ARRAY_EVAL;
    static const string C_PHP_STR_ASSIGN;
    static const string C_PHP_LTAG;
    static const string C_PHP_FULL_LTAG;
    static const string C_PHP_RTAG;
    static CParser *getInstance();

public:
    ~CParser(void);
    CTokenSet *getTokenSetFromFile(string file, int type= FORMAT_C);
    CTokenSet *getTokenSetFromString(string content, int type= FORMAT_C);
    bool strInHtmlEvent(string name);
    bool replaceTokenSet(CTokenSet *pTokenSet, int type=FORMAT_C);
    //CTokenSet *getReplaceTokenSet(string content, int type);
    string replaceOutputString(string file, int type= FORMAT_C);
    string getReplaceString(string content, int type= FORMAT_C);

    void setReplaceFile(string file);
    void addReplace(string key, string name);

    string formatHtmlFile(string);
    string formatFile(string);
    string formatHtmlString(string);
    string formatString(string);

    string mapName(string name);

    MAPSTR *getWordMap();
    bool strInVector(string str, vector < const string*> & vectors);

protected:
    void parseString(CTokenSet*, string, int);
    CParser(void);
    //CToken* createToken(CToken * token);
};

#endif // !defined(C_PARSER_H)
