#include <iostream>
#include <cstring>
#include <wchar.h>
#include <cstdlib>
#include <ctime>
#include <math.h>


using namespace std;

int main(){
    int N = 100000000;
    int result = 0;

    clock_t beginning1 = clock();

    for( int i = 0; i < N ; i++){
        i % 2 ;
    }

    clock_t ending1 = clock();

    double first_time = double( ending1 - beginning1) / CLOCKS_PER_SEC;

    cout << 1000.0 * first_time  << "\n";

    clock_t beginning2 = clock();

    for (int i = 0; i < N; i++){
        i & 0b1;
    }

    clock_t ending2 = clock();

    double second_time = double( ending2 - beginning2) / CLOCKS_PER_SEC;

    cout << 1000.0 * second_time << "\n";

    return 0;

}

/*
using namespace std;

bool first_method(int num){
    if (num % 2 == 0){
        return true;
    }
    else {
        return false;
    }
}

bool second_method(int num){
    if( ( num & 1) == 0){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int N = 1000000;

    clock_t beginning1 = clock();

    for( int i = 0; i < N; i++){
        first_method(N);
    }

    clock_t ending1 = clock();

    double first_time = double( ending1 - beginning1);

    cout << first_time / N << "\n";

    clock_t beginning2 = clock();

    for (int i = 0; i < N; i++){
        second_method(N);
    }

    clock_t ending2 = clock();

    double second_time = double( ending2 - beginning2);

    cout << second_time / N << "\n";

    return 0;
}*/


