#include <iostream>
#include <string>
#include <locale> // poder usar acento
#include <windows.h>

using namespace std;

// items
bool temChave = false;

// condições mentais
bool memoriaInstavel = false;
int sanidade = 100;
bool insanidade = false;

// história
int viuReflexo = 0;
int interagiuHomem = 0;
int fugiuCidade = 0;
int esperou = 0;

void intro();
void ruas();
void homem();
void reflexo();
void saidaDaCidade();
void espere();
void beco();
void espelho();

//fins
void fim_perfeito();
void fim_saida();
void fim_esquecido();
void fim_npc();

// funções de ajuda
void printCreepy(); // printa com intervalos aleatórios
void printSuspense(); // printa até ponto final de string

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    setlocale(LC_ALL, ".65001"); // magia stackoverflow pra portugues sem frescura

    intro();
    return 0;
}

void intro() { 
    cout << "O ônibus partiu sem você perceber.\n";
    cout << "Ou talvez nem tenha parado para começar.\n"; 
    cout << "O ponto de ônibus permanece silencioso.\n"; 
    cout << "Muito silencioso.\n";
    cout << "A placa da parada está vazia, exceto pelo símbolo de um ônibus.\n";

    ruas();
}

void ruas(){
    cout << "Você começa a andar e se percebe no meio da rua.\n";
    cout << "Há estabelecimentos comerciais com janelas de vidro.\n";
    cout << "Há um homem passando.\n";

    if(memoriaInstavel){
        cout << "Você já passou tempo demais neste lugar.\n";
    }
    int escolha;

    cin >> escolha;

    if(escolha == 1){
        homem();
    }else if (escolha == 2){
        reflexo();
    }else if(escolha == 3){
        saidaDaCidade();
    }else if(escolha == 4){
        espere();
    }else if(escolha == 5 && esperou != 0) {
        beco();
    }
    
    
}

void homem(){
    if(interagiuHomem == 0){
        cout << "O homem lhe atravessa.\n";
        cout << "Seu corpo sente um calafrio inexplicável.\n";
        cout << "Seu coração começa a acelerar.\n";
        cout << "Talvez sua mente já não esteja mais no lugar.\n";
        interagiuHomem++;
        ruas();
    }
    
}

void reflexo(){

}

void saidaDaCidade(){

}

void espere(){

}

void beco(){

}

void fim_npc(){

}

void fim_esquecido(){

}

void fim_saida(){

}

void fim_perfeito(){

}
