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
bool lembraNome = false;

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

// funções para ajudar
int leEscolha(int max){ 
    int escolha;
    int min = 1; // não vou fazer escolha que comece com 0 em teoria se for muda aqui pra argumento da função
    while (true){
        cin >> escolha;
        if(escolha >= min && escolha <= max){ // Se for add opção de 666 ou 99 pra finais secretos add aq 
            return escolha;
        } else {
            cout << "Escolha inválida.\n";
            cin.clear(); // limpa o buffer do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta o resto do buffer VI NO STACKOVERFLOW
        }
    }
}
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

    ruas(); // base de tudo, vai retornar pra cá
}

void ruas(){
    cout << "Você começa a andar e se percebe no meio da rua.\n";
    cout << "Há estabelecimentos comerciais com janelas de vidro.\n";
    cout << "Há um homem passando.\n";

    if(memoriaInstavel){ // condição especial
        cout << "Você já passou tempo demais neste lugar.\n";
    }
    int escolha;

    cout << "1 - Tentar se aproximar do homem\n";
    cout << "2 - Olhar seu reflexo na janela\n";
    cout << "3 - Sair da cidade\n";
    cout << "4 - Esperar\n";
    if(esperou != 0){
        cout << "5 - Ir para o beco\n";
    }
    cin >> escolha;
    
    if(escolha == 1){
        homem(); // rota de lembrar a si mesmo ou se perder
    }else if (escolha == 2){
        reflexo(); // rota do mundo dos espelhos
    }else if(escolha == 3){
        saidaDaCidade(); // rota da fuga infinita
    }else if(escolha == 4){
        espere(); // rota de virar npc
    }else if(escolha == 5 && esperou != 0) {
        beco();
    }
    
    
}

void homem(){ // perdão pedro. me passei.
    if(interagiuHomem == 0){
        cout << "O homem lhe atravessa.\n";
        cout << "Seu corpo sente um calafrio inexplicável.\n";
        cout << "Seu coração começa a acelerar.\n";
        cout << "Talvez sua mente já não esteja mais no lugar.\n";
        interagiuHomem++;
        ruas();
    } else if(interagiuHomem == 1){
        cout << "Ele reage. Mas não a você e diz: \n";
        cout << "Você não deveria estar ainda aqui\n";
        interagiuHomem++;
        ruas();

    } else if(interagiuHomem == 2){ // vez 3
        cout << "Ele olha diretamente a você \n";

        cout << "Pergunte quem ele é \n"; // 
        cout << "Toque-o \n";
        cout << "Permaneça em silêncio \n";
        int escolha;
        cin >> escolha; 
        if(escolha == 1){
            cout << "Ele sorri e diz: \n";
            cout << "Eu sou você, mas você não é eu. \n";
            cout << "1. Perguntar quem é você. \n";
            cout << "2. Perguntar onde você está. \n";
            cout << "3. Perguntar como sair da cidade. \n";

            int escolha2;
            cin >> escolha2;
            if(escolha2 == 1){
                cout << "O sorriso dele fecha e ele diz: \n";
                cout << "V\u016B\u0119rg. \n";
                cout << "Você lembra o seu nome.\n";
                cout << "O homem desaparece.\n";
                cout << "Você está sozinho novamente.\n";
                cout << "Mas há um relógio de bolso em sua mão.\n";
                cout << "Ele está funcionando.\n";
                
                lembraNome = True;
                ruas();
                
            }else if(escolha2 == 2){
                cout << "Ele sorri novamente, sua boca abrindo ainda mais e diz: \n";
                cout << "Você está onde sempre esteve. \n";
                cout << "O homem nunca esteve ali.\n";
                cout << "Você está sozinho novamente.\n";
                ruas();
                
            }else if(escolha2 == 3){
                cout << "Sua boca abre, as bordas do lábio racham, se abrindo com um som de carne rasgando e ele diz: \n";
                cout << "Pela saída. Ou pela morte. \n";
                cout << "A criatura que se diz ser você continua a abrir a boca, revelando uma escuridão sem fim. \n";
                cout << "Sua carne começa a se tornar do avesso, assim como uma camisa.\n";
                cout << "E então um relógio de bolso aparece no centro daquela massa de carne.\n";
                cout << "Aquele relógio sempre foi seu. Como você pode esquecer?\n";
                cout << "Você pega a si mesmo com o relógio em mãos, pristino, mesmo que estivesse banhado em sangue segundos a trás.\n";
                cout << "Ao retirar a âncora que prendia a existência da criatura, ela se desfaz em nada.\n";
                cout << "Você está sozinho novamente, mas com um relógio de bolsos em mão e um senso de si.\n";

                sanidade -= 10; // Fim SECRETO
                lembraNome = True;
                ruas();
            }

        }else if(escolha == 2){
            cout << "A pele dele tem a mesma textura que plástico.\n";
            cout << "Você sente um arrepio percorrer seu corpo.\n";
            cout << "Como a energia estática de um balão no cabelo.\n";
            cout << "Ele segue andando.\n";
            sanidade -= 10; // FIM SECRETO

            cout << "Deseja seguí-lo?\n";

            cout << "1 - Sim\n"; // rota esquecimento
            cout << "2 - Não\n"; // retorna rua
            int escolha2;
            cin >> escolha2;
            if(escolha2 == 1){
                beco();
            }else if(escolha2 == 2){
                ruas();

            }
        }else if(escolha == 3){
            cout << "Ele sorri e diz: \n";
            cout << "Eu sou você. \n";
            interagiuHomem++;
            ruas();
        }
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
