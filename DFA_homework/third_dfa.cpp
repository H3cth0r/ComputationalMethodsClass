/*
===================================================
Name:   Héctor Miranda García
ID:     A01658845
Date:   03/03/2022
===================================================
This code is intended to represent the functioning
of a DFA. In this case, the problem proposes a DFA
that recognizes strings that contain an odd quantity
of 0's and 1's

===================================================
*/

#include <iostream>
#include <string>

#define Q0      0
#define Q1      1
#define Q2      2
#define Q3      3



bool check_dfa(std::string cadena, int cadena_length){
    int the_state = Q0;
    for(int i = 0; i < cadena_length; i++){

        switch(the_state){

            case Q0:
                if(cadena[i]=='0') the_state=Q1;
                else if(cadena[i] == '1')the_state=Q2;
            break;

            case Q1:
                if(cadena[i] == '0') the_state = Q0;
                else if(cadena[i] == '1') the_state = Q3;
            break;

            case Q2:
                if(cadena[i] == '0') the_state = Q3;
                else if(cadena[i] == '1') the_state = Q0;
            break;

            case Q3:
                if(cadena[i] == '0') the_state = Q2;
                else if(cadena[i] == '1') the_state = Q1;
            break;

        }

    }
    if(the_state == Q3) return true;
    return false;
};


int main(){

    
    std::string cadena = "010011";
    int cadena_length = cadena.length();

    bool result = check_dfa(cadena, cadena_length);

    if(result == true) std::cout << "Compatible string: " << cadena << "\n";
    else std::cout << "Incompatible string: " << cadena << "\n";

    return 0;
};