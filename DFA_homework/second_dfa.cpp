/*
===================================================
Name:   Héctor Miranda García
ID:     A01658845
Date:   03/03/2022
===================================================
This code is intended to represent the functioning
of a DFA. In this case, the problem proposes a DFA
that recognizes strings that start widh an 'a' and
ending with a 'b'; also it should not contain two
consecutive b's.
===================================================
*/


#include <iostream>
#include <string>


#define Q0      0
#define Q1      1
#define Q2      2
#define ERROR   3


bool check_dfa(std::string cadena, int cadena_length){
    int the_state = Q0;
    for(int i = 0; i < cadena_length; i++){
        

        switch(the_state){
            
            case Q0:
                if(cadena[i] == 'a') the_state = Q1;
                else the_state = ERROR;
            break;

            case Q1:
                if(cadena[i] == 'a') the_state = Q1;
                else if(cadena[i] == 'b') the_state = Q2;
            break;

            case Q2:
                if(cadena[i] == 'a') the_state = Q1;
              else the_state = ERROR;
            break;

        }
    }
    if(the_state==Q2) return true;
    return false;
};

int main(){

    std::string cadena = "abaabab";
    int cadena_length = cadena.length();

    bool result = check_dfa(cadena, cadena_length);

    if(result == true) std::cout << "Compatible string: " << cadena << "\n";
    else std::cout << "Incompatible string: " << cadena << "\n";


    return 0;

};
