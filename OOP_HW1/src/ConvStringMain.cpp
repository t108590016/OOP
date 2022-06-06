#include "./ConvString.h"

int main(){
    string input,output;
    cin >> input;
    checkInput(input);
    output=convert(input);
    cout << output << endl;

    return 0;
}
