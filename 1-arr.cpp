#include <iostream>
#include <vector>
#include <array>

int main(){
    //1 
    int a[5] = {1 , 2 , 3 , 4 , 5};
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << " "; 
    }

    std::cout << "\n";

    //1 побочный
    int b[5] = { 5, 6 , 7 , 8 , 9};
    for (const int &k : b)
    {
        std::cout << k << " ";
    }

    std::cout << "\n";

    
    //2
    int e[] {1 , 2 , 3 , 4 , 5};
    for( int l = 0; l < 5; l++){
        int *pa (&e[l]);
        std::cout << *pa << " ";
    }

    std::cout << "\n";    

    //1 побочный
    const int n = 5;
    int c[n] {5, 6, 7, 8, 9};
    for( int *pa1{c}; pa1<=&c[n-1]; pa1++){
        std::cout << *pa1 << " ";
    }

    std::cout << "\n";  

    //3 
    std::vector<int> input({1, 4, 8, 9 , 12});
    for( int i = 0; i < input.size(); i++){
        std::cout << input[i] << " ";
    }

    std::cout << "\n";

    //4
    std::array<int,5> ar={1,2,3,4,5};
    for(int i = 0; i < ar.size(); i++){
        std::cout << ar[i] << " ";
    }

    //5
    int lenght = 5; 
    int *arr = new int[lenght]; 
    std::cout << "address arr: " << &arr << std::endl; 

    //6
    int *ptr = (int*)malloc(n * sizeof(int)); // выделяем память для 4-х чисел int
    if(ptr)
    {
        // помещаем значения в выделенную память
        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;
        ptr[3] = 5;
        ptr[4] = 7;
        // получаем значения
        for(int i = 0; i < n; i++)
        {
            std::cout << ptr[i] << " ";
        }
    }

    return 0;
}