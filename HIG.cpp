/** MIPS Assembly To Hex Code generator **/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>


using namespace std;
char regNameToReg(string str)
{
    if(str == "$zero")
    {
        return '0';
    }
    else if(str == "$sp")
    {
        return '7';
    }
    return str[2];
}

int main()
{
    ifstream fin;

    fin.open("input.txt");

    if(!fin)
    {
        cout << "\nError Opening File\n";
        exit(1);
    }

    ofstream logout;

    logout.open("inst.txt");

    if(logout==NULL)
    {

        printf("Cannot open logout file\n");
        exit(1);
    }

    logout << "v2.0 raw\n";
    logout << "0 ";


    int count = 0;
    while(!fin.eof() & count <=15)
    {
        string str;
        fin >> str;

        if(str == "or")
        {
            logout<< "1" ;
            string regName;
            fin>>regName;
            char rd = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rt = regNameToReg(regName);

            logout << rs << rt << rd  << " ";

        }
        else if(str == "ori")
        {
            logout<< "2" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< rs << rt << hex << constant  << " ";


        }
        else if(str == "lw")
        {
            logout<< "3" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe

            int constant;
            fin>>constant; // reg name read korbe

            fin>>regName; // reg name read korbe

            string s = regName.substr(1, 3);
            char rs = regNameToReg(s);

            if(constant > 15)
                cout << "Error in input\n";
            else logout<< rs << rt << hex << constant  << " ";

        }
        else if(str == "sw")
        {
            logout<< "4" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe

            int constant;
            fin>>constant; // reg name read korbe

            fin>>regName; // reg name read korbe

            string s = regName.substr(1, 3);
            char rs = regNameToReg(s);

            if(constant > 15)
                cout << "Error in input\n";
            else logout<< rs << rt << hex << constant  << " ";


        }
        else if(str == "and")
        {
            logout<< "5" ;
            string regName;
            fin>>regName;
            char rd = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rt = regNameToReg(regName);

            logout << rs << rt << rd  << " ";

        }
        else if(str == "j")
        {
            logout<< "6" ;

            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< "00" << hex << constant  << " ";

        }
        else if(str == "subi")
        {
            logout<< "7" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< rs << rt << hex << constant  << " ";

        }
        else if(str == "beq")
        {
            logout<< "8" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< rs << rt << hex << constant  << " ";

        }
        else if(str == "add")
        {
            logout<< "9" ;
            string regName;
            fin>>regName;
            char rd = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rt = regNameToReg(regName);

            logout << rs << rt << rd  << " ";

        }
        else if(str == "andi")
        {
            logout<< "a" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< rs << rt << hex << constant  << " ";

        }
        else if(str == "sub")
        {
            logout<< "b" ;
            string regName;
            fin>>regName;
            char rd = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rt = regNameToReg(regName);

            logout << rs << rt << rd  << " ";

        }
        else if(str == "addi")
        {
            logout<< "c" ;
            string regName;
            fin>>regName;
            char rt = regNameToReg(regName);
            fin>>regName; // comma read korbe
            fin>>regName; // reg name read korbe
            char rs = regNameToReg(regName);
            fin>>regName; // comma read korbe
            int constant;
            fin>>constant; // reg name read korbe
            if(constant > 15)
                cout << "Error in input\n";
            else
                logout<< rs << rt << hex << constant  << " ";
        }
        else
        {
            cout << "Error In Input\n" << endl;

        }


    }



    fin.close();
    logout.close();

    return 0;

    /*
    ofstream logout;

    logout.open("inst.txt");
    string s;
    int n = 780;

    logout << hex << n;

    cout << s;
        logout.close();
    */
}
