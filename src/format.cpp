
#include "format.h"

vector<string> *explode( const string &delimiter, const string &str)
{
    vector<string> *arr = new vector<string>;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0)
        return arr;//no change

    int i=0; 
    int k=0;
    while( i<strleng )
    {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            arr->push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    arr->push_back(  str.substr(k, i-k) );
    return arr;
}
const string strtolower(string s)
{
    const int length = s.length();
    for(int i=0; i!=length; ++i) { 
        s[i] = tolower(s[i]);
    }
    return s;
}
string ltrim(const string& str)
{
    return ltrim(str, " \n\r\t");
}
string rtrim(const string& str)
{    
    return rtrim(str, " \n\r\t");
}
string ltrim(const string& str, const string& search)
{
    if (str.find_first_not_of(search) != string::npos) {
        return str.substr(str.find_first_not_of(search)); 
    } else {
        return string();
    }
}
string rtrim(const string& str, const string& search)
{    
    if (str.find_last_not_of(search) != string::npos) {
        return str.substr(0, str.find_last_not_of(search)+1); 
    } else {
        return string();
    }
}
string trim(const string& str)
{
    return ltrim(rtrim(str));
}
string trim(const string& str, const string& search)
{
    return ltrim(rtrim(str, search), search);
}
string file_get_contents(const string &file)
{
    ifstream in(file.c_str());    
    if (!in) {
        cout << "Could not open source file " << file.c_str() << endl;
        throw exception();
    }
    string line;
    string content = string();
    while (getline(in, line)) {            
        content += line + string("\n");
    }
    in.close();
    return content;
}
void exitMsg(const char *msg, const char *msg1 = "")
{
    cout << msg <<  msg1 << endl;
    exit(1);
}

void help(char *file)
{   
    string help = string("Usage: ") + string(file) + string(" [OPTION] file...\n\n");
    help += string("OPTION:\n");        
    help += string("  -o file        output file\n");
    help += string("  -ow            output and write same file\n");
    help += string("  -map file      replace word map file\n");                
    help += string("  -n             not format (may by replace map)\n");
    help += string("  -t html|htm    type html|htm will format html code \n");    
    help += string("                 other will format c code \n");
    cout << help;
    exit(0);
}
string getNumSpace(int num)
{
    string s = string();
    for (int i=0;i<num;i++)
        s += string(" ");
    return s;
}
bool isDebug = false;
bool debug()
{
    return isDebug;
}

int main(int argc, char *argv[])
{
    string file = string();
    string replaceFile = string();
    string outputFile = string();
    string type = string();        
    bool bsave = false;
    bool bformat = true;
    
    if (argc <2) 
        help(argv[0]);	
    int i =0;
    for (i = 1; i < argc; i++) {
        string arg = strtolower(string(argv[i]));
        if ( IS_OPTION(arg, "-h") || IS_OPTION(arg, "--help") || IS_OPTION(arg, "-?")
          || IS_OPTION(arg, "/h") || IS_OPTION(arg, "/help") || IS_OPTION(arg, "/?"))
            help(argv[0]);
        else if (IS_OPTION(arg, "-map")) {
            if (i + 1 < argc) {                
                replaceFile = string(argv[++i]);                
            } else {
                help(argv[0]);
            }
        } else if (IS_OPTION(arg, "-o")) {
            if (i + 1 < argc) {                
                outputFile = string(argv[++i]);                
            } else {
                help(argv[0]);
            }
        } else if (IS_OPTION(arg, "-t")) {
            if (i + 1 < argc) {                
                type = string(argv[++i]);                
            } else {
                help(argv[0]);
            }
        } else if (IS_OPTION(arg, "-ow")) {
            bsave = true;
        } else if (IS_OPTION(arg, "-d")) {
            isDebug = true;
        } else if (IS_OPTION(arg, "-n")) {
            bformat = false;
        } else {
            file = arg;
        }
    }    
	if (file == string())
        exitMsg("No Source File Input");
    CParser *sp = CParser::getInstance();    
    //bool bReplace = false;
    if (replaceFile != string()) {
        sp->setReplaceFile(replaceFile);
    //    bReplace = true;
    }    
    if (bsave) {
        outputFile = file;
    }
    DEBUG(" Now ...Running....");
    string content = file_get_contents(file);
    //if (bReplace) {
    //    if (type == string("html") || type == string("htm")) {
    //        content = sp->replaceOutputString(file, FORMAT_HTML);
    //    } else {
    //        content = sp->replaceOutputString(file);
    //    }
    //}
    if (bformat) {
        if (type == string("html") || type == string("htm")) {        
            content = sp->formatHtmlString(content);
        } else {        
            content = sp->formatString(content);
        }       
    }
    if (outputFile != string()) {
        ofstream out(outputFile.c_str());
        if (!out)
            exitMsg("Could not open output file", outputFile.c_str());
        out << content;
        out.flush();
        out.close();
    } else {
        cout << content;
    }    
    return 0;
}
