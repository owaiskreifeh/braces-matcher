#include<iostream>
#include<string>
#include<stack>
#include <fstream>

using namespace std;
bool isopening(char ch);
bool isoclosing(char ch);
bool ismatch(char open, char close);

int main(int argc, char* argv[]){
    string str(argv[1]);
    if(str == "-f"){
        string file(argv[2]);
        std::ifstream ifs(file);
        std::string content( (std::istreambuf_iterator<char>(ifs) ),
                             (std::istreambuf_iterator<char>()) );
        str = content;
    }
    stack<char> stk;
    for(int i=0; i<str.length();i++){
        char ch = str[i];
        if(isopening(ch)){
            stk.push(ch);
            continue;
        }
        if(isoclosing(ch)){
            char openinig = stk.top();
            stk.pop();
            if(ismatch(openinig, ch)){
                continue;
            }else{
                cout << "missing closing for " << openinig << endl;
                exit(1);
            }
        }
    }
    cout << "Every thing is ok\n";
}

bool isopening(char ch){
    if(
        (ch == '{') 
        || (ch == '(')
        || (ch == '[')
        || (ch == '<')
        )
        return true;
    return false;
}

bool isoclosing(char ch){
    if(
        (ch == '}') 
        || (ch == ')')
        || (ch == ']')
        || (ch == '>')
        )
        return true;
    return false;
}

bool ismatch(char open, char close){
    if(
        (open == '{' && close == '}')
        || (open == '(' && close == ')')
        || (open == '[' && close == ']')
        || (open == '<' && close == '>')
        )
        return true;
    return false;
}
