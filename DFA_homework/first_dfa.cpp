/*
===================================================
Name:   Héctor Miranda García
ID:     A01658845
Date:   03/03/2022
===================================================
This code is intended to represent the functioning
of a DFA. In this case, the problem proposes a DFA
that recognizes all strings composed of 0's and 1's
, and so that there is an even number of 0's.
I'll be using a custom Graph library. 
===================================================
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



#define Q0  0
#define Q1  1

int main(){

        int state = Q0;
        std::string cadena = "10100011100";
        int cadena_length = cadena.length();

        for(int i = 0; i < cadena_length; i++){


            switch(state){
                case Q0:
                    if(cadena[i] == '1') state = Q0;
                    else if(cadena[i] == '0') state = Q1;
                
                case Q1:
                    if(cadena[i] == '1') state = Q1;
                    else if(cadena[i] == '0') state = Q0;

            }

        }
        

        if(state == Q0) std::cout << "Compatible string" << "\n";
        else std::cout << "Incompatible string" << std::endl;



    return 0;
}