#include<iostream>
#include<fstream>
using namespace std;
void indent(string st, int* count)
{   
    ofstream output;
    output.open("indent.c", ofstream::out |ofstream::app);
    string ops = "";
    if(st[st.length()-1]=='{'){
        (*count)++;
        for(int i=0;i<(*count)-1;i++){
            output<<"\t";
        }
        output<<st<<"\n";
    } else if(st[st.length()-1]=='}') {
        (*count)--;
        for(int i=0;i<(*count);i++){
            output<<"\t";
        }
        output<<st<<"\n";
    } else {
        for(int i=0;i<*count;i++){
            output<<"\t";
        }
        output<<st<<"\n";
    }
    output.close();
}
int main(int argc, char* argv[]){
    string st;
    int count = 0;
    ifstream fileOps(argv[1]);
    while(getline(fileOps,st)){
        indent(st,&count);
    }
}