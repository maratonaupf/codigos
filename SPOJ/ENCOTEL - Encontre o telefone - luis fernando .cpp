#include<iostream>
#include<sstream>
#include <ctype.h>


using namespace std;

int main ()
{
    string in ;

    while (cin  >> in )
    {
        stringstream out;
        for(char xar : in )
        {
            xar = toupper(xar);
            switch (xar)
            {
            case 'A' :
            case 'B' :
            case 'C' :
                out  << '2' ;
                continue;
            case 'D' :
            case 'E' :
            case 'F' :
                out  << '3' ;
               continue;
            case 'G' :
            case 'H' :
            case 'I' :
                out  << '4' ;
               continue;
            case 'J' :
            case 'K' :
            case 'L' :
                out  << '5' ;
               continue;
            case 'M' :
            case 'N' :
            case 'O' :
                out  << '6' ;
               continue;
            case 'P' :
            case 'Q' :
            case 'R' :
            case 'S' :
                out  << '7' ;
               continue;
            case 'T' :
            case 'U' :
            case 'V' :
                out  << '8' ;
               continue;
            case 'W' :
            case 'X' :
            case 'Y' :
            case 'Z' :
                out  << '9' ;
               continue;
            default  :
                out << xar ;
            }
        }
        string c;
        for(auto k : in){
            out >> c;
        }
        cout << c  << endl;
    }

    return 0 ;
}
