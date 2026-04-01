#include <iostream>

using namespace std;

long int cpf;
int contador;
int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;

int main() {

    cout << "Informe seu cpf(somente numeros): "
    cin >> cpf;
    
    d0 = cpf % 10;
    cpf /= 10;
    
    d1 = cpf % 10;
    cpf /= 10;
    
    d2 = cpf % 10;
    cpf /= 10;
    
    d3 = cpf % 10;
    cpf /= 10;
    
    d4 = cpf % 10;
    cpf /= 10;
    
    d5 = cpf % 10;
    cpf /= 10;
    
    d6 = cpf % 10;
    cpf /= 10;
    
    d7 = cpf % 10;
    cpf /= 10;
    
    d8 = cpf % 10;
    cpf /= 10;
    
    d9 = cpf % 10;
    cpf /= 10;
    
    d10 = cpf % 10;
    cpf /= 10;
    
    d11 = cpf % 10;
    cpf /= 10;
    
    d12 = cpf % 10;
    cpf /= 10;
    
    
    return 0;
}