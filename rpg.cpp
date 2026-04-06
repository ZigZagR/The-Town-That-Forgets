#include <iostream>
#include <string>
#include <locale> // poder usar acento
#include <limits> // numeric_limits::max() 
#include <windows.h>
#include <cstdlib> // adicionado para exit(0)

using namespace std;

// nome
std::string nome = "V\u016B\u0119rg.";

// items
bool temRelogioVerdadeiro = false;
bool temRelogioFalso = false;

// condições mentais
bool memoriaInstavel = false;
int sanidade = 100;
bool insanidade = false;
bool lembraNome = false;
bool matouReflexo = false;
bool caiuBuraco = false;
bool comido = false;
bool homemExiste = true;

// história
int viuReflexo = 0;
int interagiuHomem = 0;
int fugiuCidade = 0;
int esperou = 0;

void intro(); // Ok
void ruas(); // Falta o espere
void homem(); // Ok
void reflexo(); // Acabar entrar no espelho
void saidaDaCidade(); // Quase pronto falta add uma rota alternativa perfeita
void espere(); // N comecei
void beco(); // N comecei
void espelho(); // N comecei

//fins
void fim_perfeito();
void fim_saida();
void fim_esquecido();
void fim_npc();

// funções para ajudar 
void printCreepy(); // printa com intervalos aleatórios
void printSuspense(); // printa até ponto final de string
int verificaInput(int max); // valor default no min pq n usa 0 ou negativo

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    setlocale(LC_ALL, ".65001"); // português com acentos

    intro();
    return 0;
}

int verificaInput(int max){
    int escolha;
    int min = 1; // n uso valor diferente de 1 pra começar
    while(true){
        if(cin >> escolha){
            if(escolha >= min && escolha <= max){
                return escolha;
            }
        }
        cout << "Escolha inválida. Tente novamente.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printSuspense(string texto){
    for(size_t i = 0; i < texto.length(); i++){ // size_t é o tipo para tamanhos(texto.lenght()) 
        char c = texto[i];
        cout << c << flush;
        if(c == '.'){
            Sleep(1000);
        }else{
            Sleep(100);
        }
    }
    Sleep(3000);
    cout << "\n";
}

void intro() { 
    cout << "O ônibus partiu sem você perceber. Ou talvez nem tenha parado para começar.\n";
    cout << "O ponto de ônibus permanece silencioso. Muito silencioso\n"; 
    cout << "A placa da parada está vazia, exceto pelo símbolo de um ônibus.\n";

    ruas(); // HUB de tudo
}

void ruas(){
    cout << "\n";
    cout << "Você começa a andar e se percebe no meio de uma rua. Há estabelecimentos comerciais com janelas de vidro ao redor.\n";

    if(homemExiste){
        cout << "Há um homem passando.";
    }

    if(memoriaInstavel){ // condição especial
        cout << "Você já passou tempo demais neste lugar.\n";
    }
    int escolha;

    if(homemExiste){
        cout << "\n";
        cout << "1 - Tentar se aproximar do homem\n";
        cout << "2 - Olhar seu reflexo na janela\n";
        cout << "3 - Sair da cidade\n";
        cout << "4 - Esperar\n";
        if(esperou != 0){
            cout << "5 - Ir para o beco\n";
            escolha = verificaInput(5);
        }else{
            escolha = verificaInput(4);
        }
            
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

    }else if(!homemExiste){
        cout << "\n";
        cout << "1 - Olhar seu reflexo na janela\n";
        cout << "2 - Sair da cidade\n";
        cout << "3 - Esperar\n";
        if(esperou != 0){
            cout << "4 - Ir para o beco\n";
            escolha = verificaInput(4);
        }else{
            escolha = verificaInput(3);
        }
            
        if (escolha == 1){
            reflexo(); // rota do mundo dos espelhos
        }else if(escolha == 2){
            saidaDaCidade(); // rota da fuga infinita
        }else if(escolha == 3){
            espere(); // rota de virar npc
        }else if(escolha == 4 && esperou != 0) {
            beco();
        }
    }

    
    
    
}

void homem(){ // perdão pedro. me passei.
    if(interagiuHomem == 0){
        cout << "\n";
        cout << "O homem lhe atravessa.\n";
        cout << "Seu corpo sente um calafrio inexplicável.\n";
        cout << "Seu coração começa a acelerar.\n";
        cout << "Talvez sua mente já não esteja mais no lugar.\n";
        cout << "\n";
        interagiuHomem++;
        
        // Muito trabalho fazer uma função disso
        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            homem();
        }else {
            ruas();
        }
    
    } else if(interagiuHomem == 1){
        cout << "\n";
        cout << "Ele reage. Mas, não a você, e diz: Você não deveria estar ainda aqui.\n";
        cout << "\n";
        interagiuHomem++;

        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        cout << "\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            homem();
        }else if(escolha == 2){
            ruas();
        }

    } else if(interagiuHomem == 2){ // vez 3
        cout << "Ele olha diretamente a você.\n";
        cout << "\n";
        cout << "1. Pergunte quem ele é \n"; // 
        cout << "2. Toque-o \n";
        cout << "3. Permaneça em silêncio \n";
        cout << "\n";

        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            cout << "Ele sorri e diz: \n";
            cout << "Eu sou você, mas você não ainda não é Eu. \n";
            cout << "1. Perguntar quem é você. \n";
            cout << "2. Perguntar onde você está. \n";
            cout << "3. Perguntar como sair da cidade. \n";

            int escolha2;
            escolha2 = verificaInput(3);
            
            if(escolha2 == 1){
                cout << "\n";
                cout << "O sorriso dele fecha e ele diz: \n";
                string teste = "Olá Hai Hai";
                printSuspense(teste);
                //cout << "V\u016B\u0119rg. \n";
                cout << "Você lembra o seu nome. O homem desaparece. Você está sozinho novamente.\n";
                cout << "Mas há um relógio de bolso em sua mão. Ele está funcionando\n";
                cout << "\n";
                
                lembraNome = true;
                temRelogioVerdadeiro = true;
                homemExiste = false;
                ruas();
                
            }else if(escolha2 == 2){
                cout << "\n";
                cout << "Ele sorri novamente, sua boca abrindo ainda mais e diz: \n";
                cout << "Você está onde sempre esteve. \n";
                cout << "O homem nunca esteve ali.\n";
                cout << "Você está sozinho novamente. Há um relógio de bolso funcionando em suas mãos com uma inscrição apagada\n";
                temRelogioFalso = false;
                homemExiste = false;

                ruas();
                
            }else if(escolha2 == 3){
                cout << "\n";
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
                lembraNome = true;
                homemExiste = false;
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
            escolha2 = verificaInput(2);
            
            if(escolha2 == 1){
                beco();
            }else if(escolha2 == 2){
                ruas();
            }
        }else if(escolha == 3){
            cout << "Você espera. O homem checa seu relógio de bolso, mas você percebe que ele está quebrado.\n";
            cout << "O homem começa a andar novamente.\n";
            cout << "1. Seguí-lo.\n";
            cout << "2. Voltar.\n";

            int escolha2;
            escolha2 = verificaInput(2);

            if(escolha2 == 1){
                homemExiste = false;
                fim_npc();
            }else if(escolha2 == 2){
                ruas();
            }

        }
    }
}

void reflexo(){

    if(lembraNome || memoriaInstavel){
        cout << "Você se sente compelido a olhar o seu reflexo. Ele parece diferente. Você perecebe que aquilo não pode ser você\n";
        cout << "\n";
        cout << "1. Observar.\n";
        cout << "2. Tocar o vidro.\n";
        cout << "3. Voltar.\n";

        int escolha;
        escolha = verificaInput(3);
        
        if(escolha == 1){
            matouReflexo = true;
            cout << "Como a chama de uma vela, você percebe subitamente. Você não está lá. Nunca esteve. Em seu lugar... Nada sempre houve.\n";
            cout << "\n";
            cout << "O reflexo já não mais ali mostra apenas o que deveria estar ali. Você não está no reflexo.\n";
            cout << "Você está nas ruas novamente.";
            
        }else if(escolha == 2){
            espelho();
        }else if(escolha == 3){
            ruas();
        }
    }

    if(viuReflexo == 0){
        cout << "No reflexo você consegue ver as lojas. As casas. O céu azul. Mas você não está lá. \n";
        viuReflexo++;
        
        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            reflexo();
        }else if(escolha == 2){
            ruas();
        }

    }else if(viuReflexo == 1){
        cout << "Você novamente examina o espelho. Seu reflexo aparece, mas um pouco atrasado. \n";
        viuReflexo++;
        
        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            reflexo();
        }else if(escolha == 2){
            ruas();
        }
    }else if(viuReflexo == 2){
        cout << "Você observa seu reflexo no espelho. Você move suas mãos, mas o reflexo, sorri.";
        viuReflexo++;
        memoriaInstavel = true;
        
        reflexo();
    }
}

void saidaDaCidade(){

    if(fugiuCidade == 0){
        cout << "A placa está ilegível. Você não consegue ler o nome da cidade, ou entender as direções. Você anda por algum tempo e para no mesmo lugar.\n";
        fugiuCidade++; 
        
        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            saidaDaCidade();
        }else if(escolha == 2){
            ruas();
        }

    }else if(fugiuCidade == 1){
        cout << "Você tenta ler a placa novamente. As letras derretem e caem no chão parecendo cera quente.\n";
        fugiuCidade++; 

        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            saidaDaCidade();
        }else if(escolha == 2){
            ruas();
        }

    }else if(memoriaInstavel == false && fugiuCidade == 2){
        fim_saida();

    }else if(memoriaInstavel == true && fugiuCidade == 2){

        cout << "Você continua a andar. E andar. E andar. E andar.";
        cout << "Sua memória já não estava boa no centro da cidade. Algumas coisas já pareciam fora de lugar. Havia uma loja somente de roupas e acessórios amarelas na cidade.\n";
        cout << "Você juraria que ela nunca estava lá, mas já não tem mais tanta certeza.\n";
        cout << "Há um homem no fim da rua. Um homem em amarelo. Terno amarelo. Chapéu amarelo. Sapatos amarelos. Bengala amarela.\n";
        cout << "Você não sabe se ele estava ali ou não. As vezes ao olhar ele está lá. As vezes ao piscar ele está lá. As vezes ao abrir os olhos depois de fechar ele não está mais.\n";
        cout << "A última vez que você vê o homem, ele sorri. Ele já desapareceu por um tempo. Você já não sabe mais quanto tempo andou para ter uma referência.\n";
        cout << "Você continua a andar em frente, a cidade já não estava mais atrás de você.\n";
        caiuBuraco = true;
        fim_esquecido();
    }
}

void espere(){

    cout << "Em dev.\n"; // ACABAR
    esperou++;
    ruas();
}

void beco(){
    
    cout << "Em dev.\n"; // ACABAR
    ruas();
}

void espelho(){
    cout << "Em dev.\n"; // ACABAR
    ruas();
}

void fim_npc(){
    cout << "Você segue o homem até que ele anda para fora dos limites da cidade. Você tenta continuar a seguí-lo, mas você se pega no caminho contrário.\n";
    cout << "Apenas podendo ver as costas do homem andando livre pelos campos verdejantes dos arredores daquela cidade.\n";
    cout << "Você está sozinho novamente. Andando. E andando. E andando. E andando.\n";
    cout << "Depois de um tempo, você se esquece que já fez outra coisa além de andar por aquela rua. Um dia uma pessoa que não estava esteja ali não se aproxima e não te segue.\n";
    cout << "Você chega ao fim da sua rota, onde o homem que não estava ali antes de você cruzou a barreira final e saiu da cidade. Desta vez você não se pega retornando pelo mesmo caminho e segue em frente.\n";
    cout << "Vendo a expressão horrorizada daquilo que não estava ali não conseguindo sair. Você continua a andar e chega em uma colina coberta de flores. Cessando sua existência e tornando-se uma delas.\n";
    cout << "Fim\n";
    exit(0); // Finaliza
}

void fim_esquecido(){

    if(caiuBuraco){
        cout << "Distraído você cai em um buraco. Há apenas escuridão por um bom tempo. Não há corrente de ar. Não há nada além de uma força de sucção para baixo.\n";
        cout << "Você não consegue se lembrar de nada. Nem do seu nome. Nem do seu rosto. Nem do que você estava fazendo.\n";
        cout << "Você apenas cai. E cai. E cai. Você aterrisa em algo sólido. Não houve nenhum dano a você com a queda.\n";
    }
    if(comido){
        cout << "Em dev.\n"; // ACABAR
    }

    cout << "O local parece uma pequena ilha. No entanto o horizonte é somente uma massa completamente escura que nenhuma luz parece conseguir refletir.\n";
    cout << "Você fica ali naquela ilha de nada. Suas memórias não voltam. Para você, sempre só existiu aquela ilha de nada.\n";
    cout << "Você apenas existe. E existe. E existe. E existe. Esquecido pela cidade.\n";
    cout << "Fim\n";
    exit(0); // Finaliza
}

void fim_perfeito(){
    cout << "Em dev.\n"; // ACABAR
    exit(0); // Finaliza
}

void fim_saida(){
    cout << "Você anda por bastante tempo. A cidade fica para trás de você. As coisas começam a ficar estranhas, pequenas inconsistências. Você já não sabe por quanto tempo andou.\n";
    cout << "1 minuto? 10 horas? 100 dias? 1000 anos? Após um certo tempo, rachaduras começam a aparecer de canto de olho. Quando observadas novamente, elas não estão mais lá. \n";
    cout << "Mas você sente algo ali. Observando-o. À espreita. NADA, você viu. As rachaduras aumentam. Dessa vez elas não desaparecem. A barreira que impedia o olhar daquilo se rompeu. \n";
    cout << "De forma explosiva as rachaduras se montam e remontam, pulsando. Os olhares através do véu já não afetam mais sua mente. Sua mente já longe demais para ser humana. \n";
    cout << "Uma pequena fechadura se abre à sua frente. Você saiu da cidade. Mas você nunca esteve nela. \n";
    cout << "Fim.\n";
    exit(0); // Finaliza
}