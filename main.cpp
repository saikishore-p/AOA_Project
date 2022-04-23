#include <iostream>
#include <vector>
#include "header.h"
#include <climits>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    char input[] = "argv[1]";
    if (strcmp(argv[1], "1") == 0)
    {
        Task1 t1;
        t1.runTask1();
    }
    else if (strcmp(argv[1], "2") == 0)
    {
        Task2 t2;
        t2.runTask2();
    }
    else if (strcmp(argv[1], "3A") == 0 || strcmp(argv[1], "3a") == 0)
    {
        Task3A t3a;
        t3a.runTask3A();
    }
    else if (strcmp(argv[1], "3B") == 0 || strcmp(argv[1], "3b") == 0)
    {
        Task3B t3b;
        t3b.runTask3B();
    }
    else if (strcmp(argv[1], "4") == 0)
    {
        Task4 t4;
        t4.runTask4();
    }
    else if (strcmp(argv[1], "5") == 0)
    {
        Task5 t5;
        t5.runTask5();
    }
    else if (strcmp(argv[1], "6") == 0)
    {
        Task6 t6;
        t6.runTask6();
    }
    else
    {
        cout << "Please execute with ./MarsBase <1/2/3a/3b/4/5/6> " << endl;
    }
    return 0;
}