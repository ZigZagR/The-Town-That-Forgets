#include <iostream>
#include <string>
#include <locale> // poder usar acento
#include <limits> // numeric_limits::max() 
#include <windows.h>
#include <cstdlib> // adicionado para exit(0)

using namespace std;

// nome
std::string nome = "Gustavo";

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
bool reflexoAutonomo = false;
bool seguindoHomem = false;

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
void creditos();

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
    system("cls"); // Limpa a tela do terminal
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
        cout << "Ele reage. Mas, não a você, e diz: Você não deveria estar aqui ainda.\n";
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
        escolha = verificaInput(3);

        if(escolha == 1){
            cout << "Ele sorri e diz: \n";
            cout << "Eu sou você, mas você ainda não é Eu. \n";
            cout << "1. Perguntar quem é você. \n";
            cout << "2. Perguntar onde você está. \n";
            cout << "3. Perguntar como sair da cidade. \n";

            int escolha2;
            escolha2 = verificaInput(3);
            
            if(escolha2 == 1){
                cout << "\n";
                cout << "O sorriso dele fecha e ele diz: \n";

                printSuspense(nome);
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
                seguindoHomem = true;
                homemExiste = false;
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
        if(matouReflexo == false){
            cout << "Você se sente compelido a olhar o seu reflexo. Ele parece diferente. Você perecebe que aquilo não pode ser você\n";
            cout << "1. Observar.\n";
            cout << "2. Tocar o vidro.\n";
            cout << "3. Voltar.\n";

            int escolha;
            escolha = verificaInput(3);

            if(escolha == 1){
                matouReflexo = true;
                cout << "Como a chama de uma vela, você percebe subitamente. Você não está lá. Nunca esteve. Em seu lugar... Nada sempre houve.\n";
                cout << "O reflexo já não mais ali mostra apenas o que deveria estar ali. Você não está no reflexo.\n";
                reflexo();

            }else if(escolha == 2){
                espelho();
            }else if(escolha == 3){
                ruas();
            }
        }else{
            cout << "Você novamente está a só na frente do vidro da loja. Ele reflete o céu, as lojas e as ruas. Mas não você.\n";
            cout << "1. Tocar o vidro.\n";
            cout << "2. Voltar.\n";

            int escolha;
            escolha = verificaInput(2);

            if(escolha == 1){
                espelho();
            }else if(escolha == 2){
                ruas();
            }
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
        cout << "Você observa seu reflexo no espelho. Você move suas mãos, mas o reflexo, sorri. \n";
        reflexoAutonomo = true;
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

    }else if(memoriaInstavel == true && fugiuCidade == 2){
        fim_saida();

    }else if(memoriaInstavel == false && fugiuCidade == 2){

        cout << "Você continua a andar. E andar. E andar. E andar.\n";
        cout << "Sua memória já não estava boa no centro da cidade. Algumas coisas já pareciam fora de lugar.\n";
        cout << "Havia uma loja somente de roupas e acessórios amarelas na cidade.\n";
        cout << "Você juraria que ela nunca estava lá, mas já não tem mais tanta certeza.\n";
        cout << "Há um homem no fim da rua. Um homem em amarelo. Terno amarelo. Chapéu amarelo. Sapatos amarelos. Bengala amarela.\n";
        cout << "Você não sabe se ele estava ali ou não. As vezes ao olhar ele está lá. As vezes ao piscar ele está lá.\n";
        cout << "As vezes ao abrir os olhos depois de fechar ele não está mais.\n";
        cout << "A última vez que você vê o homem, ele sorri. Ele já desapareceu por um tempo.\n";
        cout << "Você já não sabe mais quanto tempo andou para ter uma referência.\n";
        cout << "Você continua a andar em frente, a cidade já não estava mais atrás de você.\n";
        caiuBuraco = true;
        fim_esquecido();
    }
}

void espere(){
    if(esperou == 0){
        cout << "Você espera por um tempo. Nada muda. O tempo passa. E passa. E passa. Você percebe um beco com uma iluminação precária\n"; 
        esperou++;
        
        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            espere();
        }else if(escolha == 2){
            ruas();
        }

    }else if(esperou == 1){
        cout << "Você continua a esperar. O homem continua a andar desaparecendo no horizonte e reaparecendo eventualmente.\n";
        cout << "O reflexo nas lojas continua o mesmo. O beco permanece parece mais atrativo com o passar do tempo.\n";
        memoriaInstavel = true;
        esperou++;

        cout << "1. Tentar novamente.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            espere();
        }else if(escolha == 2){
            ruas();
        }

    }else if(memoriaInstavel == true && esperou == 2){
        cout << "Você se pega andando até o beco. Você não se lembra de ter decidido andar até o beco. Mas você está lá.\n";
        beco();
    }
}

void beco(){  
    if(seguindoHomem){
        cout << "Você segue o homem para dentro do beco. Apenas a luz de uma lâmpada pendurada em um fio de metal ilumina o caminho.\n";
        cout << "Você não consegue ver nada a sua frente exceto a vaga imagem das costas do homem a sua frente.\n";
        cout << "Você não consegue ver o fim do beco. A escuridão é densa.\n";
        cout << "Você não consegue ver o começo do beco. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está atrás de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está na frente de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está acima de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está abaixo de você. A escuridão é densa.\n";
        cout << "Você não consegue ver nada. A escuridão é densa.\n";
        cout << "Você não consegue ver nada. A escuridão é densa.\n";
        cout << "De repente. Uma luz se ascende na escuridão.\n";
        cout << "Há uma luz pendurada, balançando levemente no que parece ser o fim do beco.\n";
        cout << "O homem continua andando, alheio a luz.\n";
        cout << "Você continua andando atrás dele, o homem então atravessa poucos passos após a luz e desaparece.\n";
        cout << "Você está sozinho no beco.\n";
        
        cout << "1. Ir até a luz.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            fim_esquecido();
        }else if(escolha == 2){
            ruas();
        }
    }
    if(memoriaInstavel == true && esperou == 2){
        cout << "Você está no beco de fato. As paredes são de tijolos de pedra assim como todo o resto da cidade.\n";
        cout << "A iluminação vem de uma lâmpada pendurada por um fio de metal. O fio balança de um lado para o outro.\n";
        cout << "Você não consegue ver o fim do beco. A escuridão é densa.\n";
        cout << "Você não consegue ver o começo do beco. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está atrás de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está na frente de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está acima de você. A escuridão é densa.\n";
        cout << "Você não consegue ver o que está abaixo de você. A escuridão é densa.\n";
        cout << "Você não consegue ver nada. A escuridão é densa.\n";
        cout << "Você não consegue ver nada. A escuridão é densa.\n";
        cout << "De repente. Uma luz se ascende na escuridão.\n";
        cout << "Há uma luz pendurada, balançando levemente no que parece ser o fim do beco.\n";
        
        cout << "1. Ir até a luz.\n";
        cout << "2. Voltar.\n";
        int escolha;
        escolha = verificaInput(2);

        if(escolha == 1){
            comido = true;
            fim_esquecido();
        }else if(escolha == 2){
            ruas();
        }
    }    
    cout << "Em dev.\n"; // ACABAR
    ruas();
}

void espelho(){
    // Plano  Espelho)    
    // - Corredor de Reflexos 
    // 1. Imitar o reflexo - Perde controle de si por uns segundos, se repetir pode trocar de lugar com o reflexo
    // 2. Ignorar e seguir - Segue em frente, seu reflexo fica para trás chegando em uma sala central
    // 3. Tocar o espelho - O reflexo sai do espelho e começa a andar para alguma direção desconhecida parecendo incompleto ou sem senso de direção
    // 4. Observar por mais tempo - O reflexo começa a agir sozinho com o tempo que passa. Eventualmente ele some. // rota secreta TRIGGER insanidade < 10

    // - Sala das Versões - Versão cega, surda e muda
    // 1. Gesticular para o cego. - Ilusão de escolha vai os 3 pro mesmo canto, inferno. 
    // 2. Falar com o surdo.
    // 3. Tocar o mudo.
    // 4. Ignorar todos e seguir em frente. - Não interagir com o mal te faz seguir em frente recuperando o estado mental talvez?.

    // - Espaço Sem Reflexo
    // 1. Esperar.
    // 2. Seguir em frente.
    // 3. Gritar.
    // 4. Voltar.

    // - Espelho Quebrado (rota secreta good ending) - Fragmentos de realidades diferentes
    // 1. Fragmento de realidade A - Você vê a vida real. Rota de desvaneio romântico editada.
    // 2. Fragmento de realidade B - Você vê a cidade da forma que ela realmente é. Um pequeno mundo no estômago de Azazoth 
    // 3. Voltar.

    // - Saída (não confiável)
    // Você saí mas algo pode vir junto ou não e tomar o seu lugar 50/50

    cout << "Em dev.\n"; // ACABAR
    ruas();
}

void fim_npc(){
    cout << "Você segue o homem até que ele anda para fora dos limites da cidade. Você tenta continuar a seguí-lo, mas você se pega no caminho contrário.\n";
    cout << "Apenas podendo ver as costas do homem andando livre pelos campos verdejantes dos arredores daquela cidade.\n";
    cout << "Você está sozinho novamente. Andando. E andando. E andando. E andando.\n";
    cout << "Depois de um tempo, você se esquece que já fez outra coisa além de andar por aquela rua.\n";
    cout << "Um dia uma pessoa que não estava ali não se aproxima e não te segue.\n";
    cout << "Você chega ao fim da sua rota, onde o homem que não estava lá antes de você nunca cruzou a barreira final e nunca saiu da cidade.\n";
    cout << "Desta vez você não se pega retornando pelo mesmo caminho e segue em frente.\n";
    cout << "Vendo a expressão horrorizada daquilo que não estava ali não conseguindo sair ao tentar segui-lo.\n";
    cout << "Você continua a andar e chega em uma colina coberta de flores. Cessando sua existência e tornando-se uma delas.\n";
    cout << "Fim\n";
    creditos();
}

void fim_esquecido(){

    if(caiuBuraco){
        cout << "Distraído você cai em um buraco. Há apenas escuridão por um bom tempo. Não há corrente de ar. Não há nada além de uma força de sucção para baixo.\n";
        cout << "Você não consegue se lembrar de nada. Nem do seu nome. Nem do seu rosto. Nem do que você estava fazendo.\n";
        cout << "Você apenas cai. E cai. E cai. Você aterrisa em algo sólido. Não houve nenhum dano a você com a queda.\n";
    }
    if(comido){
        cout << "Você anda em direção a luz. Mas quando percebe o cheiro de peixe e sangue já é tarde demais.\n";
        cout << "Você é devorado por uma criatura similar a um peixe lanterna. Usando da luz para atrair suas presas.\n";
        cout << "Há apenas escuridão por um bom tempo. Não há corrente de ar. Não há nada além de uma força de sucção para baixo.\n";
        cout << "Você não consegue se lembrar de nada. Nem do seu nome. Nem do seu rosto. Nem do que você estava fazendo.\n";
        cout << "Você apenas cai. E cai. E cai. Você aterrisa em algo sólido. Não houve nenhum dano a você com a queda.\n";
    }

    cout << "O local parece uma pequena ilha. No entanto o horizonte é somente uma massa completamente escura que nenhuma luz parece conseguir refletir.\n";
    cout << "Você fica ali naquela ilha de nada. Suas memórias não voltam. Para você, sempre só existiu aquela ilha de nada.\n";
    cout << "Você apenas existe. E existe. E existe. E existe. Esquecido pela cidade.\n";
    cout << "Fim\n";
    creditos();
}

void fim_perfeito(){
    cout << "Em dev.\n"; // ACABAR
    creditos();
}

void fim_saida(){
    cout << "Você anda por bastante tempo. A cidade fica para trás de você. As coisas começam a ficar estranhas, pequenas inconsistências. \n";
    cout << "Você já não sabe por quanto tempo andou. 1 minuto? 10 horas? 100 dias? 1000 anos? \n";
    cout << "Após um certo tempo, rachaduras começam a aparecer de canto de olho. \n";
    cout << "Quando observadas novamente, elas não estão mais lá. \n";
    cout << "Mas você sente algo ali. Observando-o. À espreita. NADA, você viu. As rachaduras aumentam. \n"; 
    cout << "Dessa vez elas não desaparecem. A barreira que impedia o olhar daquilo se rompeu. \n";
    cout << "De forma explosiva as rachaduras se montam e remontam, pulsando. Os olhares através do véu já não afetam mais sua mente. \n";
    cout << "Sua mente já longe demais para ser humana. \n";
    cout << "Uma pequena fechadura se abre à sua frente. Você saiu da cidade. Mas você nunca esteve nela. \n";
    cout << "Fim.\n";
    creditos();
}

void creditos(){
    cout << "Créditos:\n";
    cout << "Desenvolvedores: Luiz Franke e Pedro Henrique.\n";
    cout << "Roteiro: Luiz Franke e Pedro Henrique.\n";
    cout << "Menções honrosas: Alberto H.W. , Gasfer,  Gustavo de Borba Vigarani, Nicolas Gabriel Berenstein.\n";
    cout << "Fim.\n";
    exit(0); // Finaliza
}