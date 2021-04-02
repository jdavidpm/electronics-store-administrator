#include <windows.h>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "date_function.h"

using namespace std;

void TOP()
{
     printf("\n");
     for(int i = 1; i <= 80; i++)
         printf("%2c", '*');
     for(int i = 1; i <= 5; i++)
         printf("%2c%2c%74c%2c", '*', '*', '*', '*');
}

void BELOW()
{
     printf("\n");
     for(int i = 1; i <= 5; i++)
         printf("%2c%2c%74c%2c", '*', '*', '*', '*');
     for(int i = 1; i <= 80; i++)
         printf("%2c", '*');
     printf("\n");
}

