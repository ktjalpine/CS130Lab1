//Lab 1A
//COSC130
//Converts different data types and outputs the mathmatical operation between 2 numbers.
//Kyle James
//08 / 31 / 2018

#include <iostream>
#include <string>
using namespace std;

//Prototypes for the functions that you will write

//Converts a Char to an Int
int  CharToInt(char v){
    int a = v;
    return a;
}


//Converts an Int to a Char
char IntToChar(int v){
    v = v + '0';
    return v;
}

//Converts a String to an Int
int StringToInt(string val) {
    int temp = 0, sign = 1;
    int i = 0;

    //Checks if negative
    if(val.at(0) == '-'){
        sign = -1;
        i++;
    }

    //Converts the string to int and adds the values
    while(val[i] >= '0' && val[i] <= '9') {
        temp *= 10;
        temp += val[i] - '0';
        i++;
    }

    return temp * sign;
}

//Converts Int to String
string IntToString(int val){
    string finalString;


    int i,remainder,len = 0, j;

    //Handles if the value is negative
    if(val < 0){
        val *= -1;
        j = val;
        while(j != 0) {
            len++;
            j/= 10;
        }

        //Handles converting the int using the IntToChar function
        for(i = 0; i < len; i++){
            remainder = val % 10;
            val = val / 10;
            finalString = IntToChar(remainder) + finalString;
        }

        finalString[len] = '\0';
        finalString = "-" + finalString;
    }

    //Handles all other values but negatives
    else {
        j = val;
        while (j != 0) {
            len++;
            j /= 10;
        }

        //Handles converting the int using the IntToChar function
        for (i = 0; i < len; i++) {
            remainder = val % 10;
            val = val / 10;
            finalString = IntToChar(remainder) + finalString;
        }

        finalString[len] = '\0';
    }

    //If the finalString is empty, aka 0, this replaces the empty value with 0.
    if(finalString == ""){
        finalString = "0";
    }

    return finalString;
}


int main(int argc, char *argv[])
{
        string sresult;
        int left;
        int right;
        char op;

        if (4 != argc) {
                printf("Usage: %s <left> <op> <right>\n", argv[0]);
                return -1;
        }
        //Notice that this calls your StringToInt. So, make sure you debug
        //StringToInt() to make sure that left and right get a proper
        //value.
        left = StringToInt(argv[1]);
        right = StringToInt(argv[3]);
        op = argv[2][0];
        //Calculate based on the op. Notice that this calls IntToString,
        //so debug your IntToString() function to make sure that sresult
        //is given the proper result. This assumes your StringToInt already
        //works.
        switch (op)
        {
                case 'x':
                        sresult = IntToString(left * right);
                        break;
                case '/':
                        sresult = IntToString(left / right);
                        break;
                case '+':
                        sresult = IntToString(left + right);
                        break;
                case '-':
                        sresult = IntToString(left - right);
                        break;
                case '%':
                        sresult = IntToString(left % right);
                        break;
                default:
                        sresult = IntToString(left);
                        break;
        }

        //Remember, printf is the only output function you may use for this lab!
        //The format string is %d %c %d = %s. This means that the first argument
        //is %d (decimal / integer), %c (character), %d (decimal /integer),
        //%s (string). Notice that because printf() is a C-style function, you
        //must pass strings as character arrays. We can convert a C++ string
        //to a character array (C-style string) by using the c_str() member function.
        printf("%d %c %d = %s\n", left, op, right, sresult.c_str());
        return 0;
}
