#include "./ConvString.h"
int checkInput(string input){
    int x=0;
    int right_bracket=0,left_bracket=0;
    try {
        for(int i=0;i<=input.length();i++){
            if(!(islower(input[i])) && !(isdigit(input[i])) && input[i]!='[' && input[i]!=']' && i!=input.length()){
                x=1;
            }
            else if(isdigit(input[i]) && (input[i+1]!='[' || isdigit(input[i+1]))){
                x=1;
            }
            if(input[i]=='['){
                left_bracket++;
            }
            else if(input[i]==']'){
                right_bracket++;
            }
        }
        if(right_bracket!=left_bracket){
            x=1;
        }
        if(x==1){
            throw invalid_argument(__func__);
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
        if(skip==1){
            temp+=input[i];
        }
        else{
            if(isalpha(input[i])){
    			      output+=input[i];
            }
            else if(isdigit(input[i])){
                times=input[i]-'0';
            }
        }
        if(input[i]=='['){
            conti++;
            skip=1;
        }
        if(input[i]==']'){
            conti-=1;
            if(conti==0){
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
