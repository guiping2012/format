#ifndef FORMAT_H
#define FORMAT_H
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<exception>
using namespace std;
#ifdef _MSC_VER
#pragma warning( disable:4786 )
#endif
#define INIT_CONTAINER(container, value)     {if ( (container) != NULL ) delete (container); (container) = (value); }
#define DELETE_CONTAINER(container)          {if ( (container) != NULL ) delete (container) ; }
#define MAX_LINE_LENGTH                      80
#define BREAK_LINE_INDEX                     4

#define FORMAT_HTML                          1
#define FORMAT_C                             2

#define IS_OPTION(arg,op)          ((arg).compare(op)==0)
#define IS_OPTIONS(arg,a,b)        (IS_OPTION((arg),(a)) || IS_OPTION((arg),(b)))

#define IS_PARAM_OPTION(arg,op)    ((arg).COMPARE(0, strlen(op) , string(op))==0)
#define IS_PARAM_OPTIONS(arg,a,b)  (IS_PARAM_OPTION((arg),(a)) || IS_PARAM_OPTION((arg),(b)))

#define GET_PARAM(arg,op)          ((arg).substr(strlen(op)))
#define GET_PARAMS(arg,a,b)        (IS_PARAM_OPTION((arg),(a)) ? GET_PARAM((arg),(a)) : GET_PARAM((arg),(b)))
#define DEBUG(str)                  if (debug()) cout << "[debug] " << (str) << endl;
#define echo                        cout <<

bool debug();

typedef map <string,string> MAPSTR;
vector<string> *explode( const string &delimiter, const string &explodeme);
const string strtolower(string s);
string ltrim(const string& str);
string rtrim(const string& str);
string trim(const string& str);
string trim(const string& str, const string& search);
string ltrim(const string& str, const string& search);
string rtrim(const string& str, const string& search);

string file_get_contents(const string &file);
string getNumSpace(int num);


#include "Statement.h"
#include "Token.h"
#include "TokenSet.h"
#include "Parser.h"
#include "HtmlTag.h"




class CTwin
{
    //CToken *lpToken; //暂时不用指针，如果出现内存不够，以后修改为指针方式
    //CToken *rpToken;
    int start;
    int end;
public:
    CTwin();
    bool hasStart();
    bool hasEnd();
    //bool eqLeftToken(CToken *pToken);
    //bool eqRightToken(CToken *pToken);
    void setStartIndex(int index);
    void setEndIndex(int index);
    int getStartIndex();
    int getEndIndex();
    //CToken *getLeftToken();
    //CToken *getRightToken();
};

#endif
