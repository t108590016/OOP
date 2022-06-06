#include "./ConvString.h"
int checkInput(string input){
    int x = 0;
    try {
        for(char ch:input){
            if(!(isalpha(ch)) && !(isdigit(ch)) && ch!='[' && ch!=']'){
                throw invalid_argument(__func__);
                x=1;
            }
        }
    }
    catch(const invalid_argument& ia) {
        cout<<"The function " << ia.what() << " reports input error"<<endl;
        return 1;
    }
    return 0;
}
string convert(string input){
    string output="";
	  string temp="";
	  int times=0,conti=0,skip=0;
	  for(int i=0;i<input.length();i++){
		    if(isalpha(input[i])){
            if(skip==1){
                temp+=input[i];
            }
            else{
			          output+=input[i];
            }
        }
        else if(isdigit(input[i])){
            if(skip==1){
                temp+=input[i];
            }
            else{
                times=input[i]-'0';
            }
        }
        else if(input[i]=='['){
            conti++;
            if(skip==1){
                temp+=input[i];
            }
            else{
                skip=1;
            }
        }
        else if(input[i]==']'){
            conti-=1;
            if(skip==1){
                temp+=input[i];
            }
            if(conti==0){
                conti=0;
                skip=0;
                for(int j=0;j<times;j++){
                    output+=convert(temp);
                }
                temp="";
            }
        }
	  }
    return output;
}
