/*
#include <iostream>
//#include "stdafx.h"
#include <cstring>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <wchar.h>

//#include <windows.h>

using namespace std;

// должно работать на windows, если подключить #include <windows.h>
int main(){
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    string str ;
    string a ;
    string b;
    cout << "Введите слово:" << " " ; 
    cin  >> str;
    
    for ( int i = 0; i < str.size(); i++ ){
        b += ".";
    }
    
    cout << b << endl;
    
    char letter;

    while( strcmp( str, a) != 0){
        cout << "\nВведите букву:" << " " ;
        cin >> letter;

        bool found = 0;

        for( int j = 0; j < strlen(str); j++ ){
            if( str[j] == letter ){
                a[j] = str[j];
                found = 1;
            }
        }

        if (found){
            cout << "Угадали!:\n";
        }
        else {
            cout << "Нет такой буквы:\n";
        }

        cout << a;
    }    
    cout << "\n" << "Вы угадали слово!" << endl; } */

// вид программы, которая будет работать только на английском!!!
/*
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str[100] = "";
    char a[100] = "";
    cout << "Введите слово:" << " " ; 
    cin  >> str;
    
    for ( int i = 0; i < strlen(str); i++ ){
        a[i]='.';
    }
    
    cout << a << endl;
    
    char letter;

    //bool have = 0;

    while(strcmp(str, a) != 0)
    {
        cout << "\nВведите букву:" << " " ;
        cin >> letter;

        bool found = false;
        for(int j = 0; j < strlen(str); j++)
        {
            if(str[j] == letter)
            {
                a[j] = str[j];
                found = true;
            }
        }
        if (found)
        {
            cout << "Угадали!\n";
            found = false;
        }
        else
        {
            cout << "Нет такой буквы\n";
        }
        cout << a;
    }    
    cout << "\n" << "Вы угадали слово!" << endl;
} */

// работает только на русском!!!
#include <iostream>
#include <cstring>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main(){

    char str[100] = "";
    char a[100] = "";
    cout << "Введите слово:" << " " ; 
    size_t n = 0;
    cin  >> str;
    //(str, &n, stdin);
    for ( int i = 0; i < strlen(str) ; i++ ){
        a[i] = '.';
        //cout << a[i] ;
    }

    for ( int i = 0; i < strlen(str) / 2; i++ ){
        a[i] = '.';
        cout << a[i] ;
    }   

    //cout << a;

    char letter1;
    char letter2;
    int i = 0;

    while( strcmp( str, a) != 0){
        cout << "\nВведите букву:" << " " ;
        cin >> letter1;
        cin >> letter2;

        bool found = 0;

        for( int j = 0; j < strlen(str) / 2; j++ ){
            if( str[2 * j] == letter1 && str[2 * j + 1] == letter2 ){
                a[2*j] = str[2*j];
                a[2*j + 1] = str[2*j + 1];
                found = 1;
            }
        }
        
        if (found){
            cout << "Угадали букву:\n";
        }
        else {
            cout << "Не угадали:\n";
        }

        for( int j = 0; j < strlen(a); j++ )
        {
            if(a[j] == '.' && a[j] == a[j + 1])
            {
                j++;
            }
            cout << a[j];
        } 
        cout << '\n';
    }    
    cout << "\n" << "Вы угадали слово!" << endl;
}