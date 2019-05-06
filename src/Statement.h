#if !defined(C_STATEMENT_H)
#define C_STATEMENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToken;
class CTokenSet;
class CStatement
{
public:
    
    static const int C_STATEMENT_NORMAL_TYPE;     //∆’Õ®”Ôæ‰
    static const int C_STATEMENT_CONTROL_TYPE;
    static const int C_STATEMENT_IF_CONTROL_TYPE;
    static const int C_STATEMENT_DO_CONTROL_TYPE;
    static const int C_STATEMENT_COMPLEX_TYPE; //∏¥∫œ”Ôæ‰£¨{}¿®∫≈¿®∆¿¥µƒ”Ôæ‰
    static const int C_STATEMENT_FUNCTION_TYPE;
    static const int C_STATEMENT_CLASS_TYPE;
    static const int C_STATEMENT_STRUCT_TYPE;
    static const int C_STATEMENT_UNION_TYPE;
    static const int C_STATEMENT_ENUM_TYPE;
    static const int C_STATEMENT_TYPEDEF_TYPE;
    static const int C_STATEMENT_COMMENT_TYPE;
    static const int C_STATEMENT_LINE_COMMENT_TYPE;
    static const int C_STATEMENT_PRE_PROCESSOR_TYPE;
    static const int C_STATEMENT_CASE_TYPE;
    static const int C_STATEMENT_LABEL_TYPE;
    static const int C_STATEMENT_CLASS_LABEL_TYPE;
    static const int C_STATEMENT_PHP_TAG_TYPE;
    static const int C_STATEMENT_TEMPLATE_TYPE;
   
    
    CStatement(void);
public:
    virtual ~CStatement(void);
public:
    virtual int getType(void);
    virtual string toString();
    virtual string getClassName();
protected:
    int m_indent;
    CTokenSet* m_tokens;

    
public:
    void setTokenSet(CTokenSet* tokens);
public:
    int getIndent(void);
public:
    int setIndent(int indent);
public:
    string replaceName(string name);
};

class CComplexStatement :
    public CStatement
{
public:
    virtual int getType(void);
    virtual string toString();
    virtual string getClassName();
    CComplexStatement(void);
public:
    virtual ~CComplexStatement(void);
};



#endif
