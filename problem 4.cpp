#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int a = 5, b = 10;
int c;
int* p1, * p2;
p1 = &a;    // STORING ADDRESS OF a
p2 = &b;    // STORING ADDRESS OF b
c = *p1;    // STORING  VALUE AT P1 IN C
cout << "*(p1++) =" << *(p1++) << endl; // THIS *(P1++) MEANS IT FIRST PRINT A VALUE WHICH IS STORE IN IT AND THEN DECREMENT IT.
cout << "value of p1 " << p1 << endl;   // P1 IS A INTEGER POINTER WHICH STORE ADDRESS OF a AND a VARUABLE STORE 5 SO P1 STORE THE ADDRESS OF a.
cout << "*(++p1) =" << *(++p1) << endl; // THIS *(++P1) FIRST DECREMENT AND THEN PRINT P1 VALUE. IN THIS CASE IT WILL BE PRINT A GARBAAG VALUE
cout << "value of p1 " << p1 << endl;  // THIS P1 GIVE US ADDRESS OF SOME GARBAAG VALUE BECAUSE OF THE ABOVE CONDITION.
cout << "(*p1)++ =" << (*p1)++ << endl; // THIS (*P1)++  FIRST DECREMENT AND THEN PRINT P1 VALUE. IN THIS CASE IT WILL BE PRINT A GARBAAG VALUE.
cout << "value of p1 " << p1 << endl;   // THIS P1 GIVE US ADDRESS OF SOME GARBAAG VALUE BECAUSE OF THE ABOVE CONDITION.
cout << "++(*p1) =" << ++(*p1) << endl; // THIS ++(*P1) FIRST DECREMENT AND THEN PRINT P1 VALUE. IN THIS CASE IT WILL BE PRINT SOME GARBAAG VALUE.
cout << "value of p1 " << p1 << endl;    // P1 WILL PRINT SOME ADDRESS OF GARBAAG VALUE.
return 0;
}