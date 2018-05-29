/**
 * Codat Checker main.cpp
 * Purpose: check if every tag has a closing tag in the right order
 * @author: Owais Majid
 * @version: 1.0.0
*/

#include<iostream>
#include<string>
#include<stack>
#include <fstream>

using namespace std;

// Prototypes
string readfiletostring(char * filePath);
bool isopening(char ch);
bool isoclosing(char ch);
bool ismatch(char open, char close);

char otags[] = {'{', '[', '(', '<'}; // opning tages array
char ctags[] = {'}', ']', ')', '>'}; // closing tags array
int tagssize = (sizeof otags / sizeof otags[0]); // the size of tags array

int main(int argc, char* argv[]){
    string str(argv[1]);
    stack<char> stk;

    if(str == "-f")
        str = readfiletostring(argv[2]);

    for(int i=0; i<str.length();i++){
        char ch = str[i];
        if(isopening(ch)){
            stk.push(ch);
            continue;
        }

        if(isoclosing(ch)){
            char openinig = stk.top();
            if(ismatch(openinig, ch)){
                stk.pop();
                continue;
            }else{
                cout << "missing closing for " << openinig << endl;
                exit(1);
            }

        }
    }
    if(!stk.empty()){
         cout << "missing closing for " << stk.top() << endl;
    }
    else{
        cout << "Every thing is ok\n";
    }
}

/**
 * Checks if the given character is an opening tag
 * @param ch as char 
 * @return bool
*/
bool isopening(char ch){
    for(int i=0; i<tagssize ; i++)
        if (otags[i] == ch) return true;
    return false;
}

/**
 * Checks if the given character is an closing tag
 * @param ch as char 
 * @return bool
*/
bool isoclosing(char ch){

    for(int i=0; i<tagssize ; i++)
        if (ctags[i] == ch) return true;
    return false;
}

/**
 * Checks if open tag and close tag are match
 * @param open as char 
 * @param close as char
 * @return bool
*/
bool ismatch(char open, char close){
    for(int i=0; i<tagssize ; i++)
        if (otags[i] == open){
            if(ctags[i] == close) return true;
    }
    return false;
}

/**
 * Reads file from given file path
 * @param filePath as char*
 * @return string
*/
string readfiletostring(char * filePath){
    string file(filePath);
    std::ifstream ifs(file);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()) );
    return content;
}