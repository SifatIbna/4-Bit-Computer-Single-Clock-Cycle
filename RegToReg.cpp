#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#define INFINITY 999999

using namespace std;
char regToreg (string str)
{
    if(str == "$zero")
        return '0';
    else if(str == "$sp")
        return '7';
    else return str[2];
}

int main()
{
    while(1)
    {
        string str;
        cin >> str;
        char x=regToreg(str);
        cout << x;
    }
}
/*
$t1, $t2, $zero, $sp
*/
