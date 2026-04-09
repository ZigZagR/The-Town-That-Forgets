#include <iostream>
#include <string>
#include <locale> // poder usar acento
#include <limits> // numeric_limits::max() 
#include <windows.h>
#include <cstdlib> // exit(0) )

using namespace std;

// nome
std::string nome = "Gustavo";

// items
bool temRelogioVerdadeiro = false;
bool temRelogioFalso = false;

// condições mentais
bool memoriaInstavel = false;
int sanidade = 10;
bool lembraNome = false;
bool matouReflexo = false;
bool caiuBuraco = false;
bool comido = false;
bool homemExiste = true;
bool reflexoAutonomo = false;
bool seguindoHomem = false;
bool ignorouCorredor = false;    
bool reflexoSeguindo = false;

// história
int viuReflexo = 0;
int interagiuHomem = 0;
int fugiuCidade = 0;
int esperou = 0;

void intro(); // Ok
void ruas(); // Ok
void homem(); // Ok
void reflexo(); // Acabar entrar no espelho
void saidaDaCidade(); // Quase pronto falta add uma rota alternativa perfeita
void espere(); // Ok
void beco(); // Metade
void espelho(); // N comecei
void corredor_reflexos();
void sala_versoes();
void espelho_sem_reflexo();
void espelho_quebrado();
void saida_falsa();

//fins
void fim_perfeito();
void fim_saida(); 
void fim_esquecido(); // Ok
void fim_npc(); // Ok
void creditos(); // Ok
void fim_espelho(); // PEPE FAZER
void fim_verdade(); // PEPE FAÇA
void fim_inferno(); // PEPE CRIE O INFERNO 

// funções para ajudar 
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
        sanidade -= 1;

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
                sanidade -= 1;
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

                sanidade -= 5; // Fim SECRETO
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
                sanidade -= 1;
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
            sanidade -= 1;

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
        sanidade -= 1;
        
        reflexo();
    }
}

void saidaDaCidade(){
    
    if(sanidade <= 0 && temRelogioVerdadeiro){
        cout << "Você sabe a saída. É algo instintivo. Aqueles pequenos truques não podem mais lhe parar. Você olha para a placa e entende para onde deve ir.\n";
        cout << "Você pega seu relógio de bolso e o abre. Os ponteiros estão quebrados como sempre. Parados no tempo, mas ainda sim certos duas vezes ao dia.\n";
        cout << "O seu nome inscrito nas margens dele ressoa. Um vibrante dourado ao mesmo tempo que uma espécie de porta circular surge a sua frente.\n";
        cout << "Há runas por toda a parte e um claro buraco no centro de seu formato circular.\n";
        cout << "Você extende o seu relógio e ele é puxado como uma força quase que magnética.\n";
        cout << "Ela se abre revelando uma luz de uma outra realidade.\n";
        fim_perfeito();
    }

    if(temRelogioFalso){
        cout << "Seu relógio de bolso parece ressoar com a cidade. Ao passar pela placa da cidade você parece conseguir entender algo e segue seu caminho\n";
        cout << "Você pensa estar livre, a sensação que você está mudando de plano retornado ao normal vem de imediato.\n";
        cout << "A última visão da cidade você percebe que o tempo nela havia parado. O seu relógio na verdade era falso.\n";
        cout << "Você então percebe que era tudo um loop. Nada era real. O chão se racha embaixo de você abrindo caminho para o inferno.\n";
        fim_inferno();        
    }

    if(fugiuCidade == 0){
        cout << "A placa está ilegível. Você não consegue ler o nome da cidade, ou entender as direções. Você anda por algum tempo e para no mesmo lugar.\n";
        fugiuCidade++; 
        sanidade -= 1;
        
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
        sanidade -= 1;

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
        sanidade -= 1;
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
        
        sanidade -= 1;
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
    if(matouReflexo == true && sanidade <= 5){ // revela o corredor com espelho rachado e o corredor sem reflexo
        cout << "Você está em uma sala opaca com 5 caminhos em cada ponta de um pentagrama. Alguns deles possuem portas de pedra o fechando.\n";
        cout << "1. Seguir pelo corredor com uma placa com 3 macacos.\n"; 
        cout << "2. Seguir pelo corredor com espelhos sem nenhum reflexo.\n"; 
        cout << "3. Seguir pelo corredor com uma placa de espelho rachado.\n"; 
        int escolha;
        escolha = verificaInput(3);
        if (escolha == 1)
        {
            sala_versoes();
        } else if (escolha == 2)
        {
            espelho_sem_reflexo();
        }
        else if (escolha == 3)
        {
            espelho_quebrado();
        }

    }else if(matouReflexo == false){
        cout << "Você está em uma sala opaca com 5 caminhos em cada ponta de um pentagrama. Alguns deles possuem portas de pedra o fechando.\n";
        cout << "1. Seguir pelo corredor com reflexos visíveis de longe.\n"; 
        cout << "2. Seguir pelo corredor com uma placa com 3 macacos.\n"; 
        cout << "3. Seguir pelo corredor com uma placa que parece ser saída, mas levemente derretida.\n";

        int escolha;
        escolha = verificaInput(4);
        if (escolha == 1)
        {
            corredor_reflexos();
        } else if (escolha == 2)
        {
            sala_versoes();
        }
        else if (escolha == 3)
        {
            saida_falsa();
        }
    }else if(matouReflexo == true){
        cout << "Você está em uma sala opaca com 5 caminhos em cada ponta de um pentagrama. Alguns deles possuem portas de pedra o fechando.\n";
        cout << "1. Seguir pelo corredor com uma placa com 3 macacos.\n"; 
        cout << "2. Seguir pelo corredor com espelhos sem nenhum reflexo.\n"; 
        int escolha;
        escolha = verificaInput(2);
        if (escolha == 1)
        {
            sala_versoes();
        } else if (escolha == 2)
        {
            espelho_sem_reflexo();
        }
    }

}

void corredor_reflexos(){
   
   
    cout << "1. Imitar o reflexo \n"; // Perde controle de si por uns segundos, se repetir pode trocar de lugar com o reflexo
    cout << "2. Ignorar e seguir \n"; // Segue em frente, seu reflexo fica para trás chegando em uma sala central
    cout << "3. Tocar o espelho \n"; // O reflexo sai do espelho e começa a andar para alguma direção desconhecida parecendo incompleto ou sem senso de direção
    cout << "4. Observar por mais tempo \n"; // rota secreta TRIGGER insanidade < 10
    cout << "5. Sair por uma saída estranha.\n";


    int escolha;
    escolha = verificaInput(5);
    if (escolha == 1)
    {
        cout << "Ao tentar imitar o reflexo, você lentamente percebe que você está se transformando nele.\n";
        cout << "Já é tarde demais para parar. Seu corpo já está do outro lado do espelho. A criatura anda livre. \n";
        cout << "Mas você agora está preso. Fadado a tentar imitar o quer que esteja do outro lado do espelho, para tomar seu lugar \n";
        fim_espelho();
        
    } else if (escolha == 2)
    {
        cout << "Você ignora os espelhos. Seguindo em frente por aquele corredor.\n";
        ignorouCorredor = true;
        fim_perfeito();
        
    } else if (escolha == 3)
    {
        cout << "A criatura sai do espelho e começa andar. Ela parece incompleta. Sem noção de como se mover propriamente ou ter uma direção.\n";
        cout << "Ela anda até um pouco adiante e então para. Ela olha para você.\n";
        cout << "A forma da criatura se distorce. Não conseguindo mais manter a imitação fora do espelho.\n";
        cout << "Ela então se dissolve em nada. Você se pega novamente na sala pentagonal\n";
        matouReflexo = true;
        espelho();
    }
     else if (escolha == 4)
    {
        if(sanidade <= 5){
            cout << "Você começa a lentamente ver a realidade daquele local. Você vê que os espelhos escondem um abismo inamignável por trás.\n";
            cout << "Os espelhos escondem fragmentos de uma realidade terrível. Mas você sabe que aquilo é verdade.\n";
            fim_verdade();
        }else{
            cout << "Você sente uma sensação estranha. Olhar para aquele espelho não parece surgir um efeito positivo.";
            sanidade -= 1;
            corredor_reflexos();
        }
    }
     else if (escolha == 5)
    {
        saida_falsa(); 
    }
}

void sala_versoes(){
    cout << "Você adentra a sala com a placa de 3 macacos.\n";
    cout << "Há um reflexo com as mãos nos olhos.\n";
    cout << "Há um segundo reflexo com as mãos nos ouvidos.\n";
    cout << "Há um terceiro reflexo com as mãos na boca.\n";
    cout << "\n";
    cout << "1. Gesticular para o cego. \n"; 
    cout << "2. Falar com o surdo.\n";
    cout << "3. Perguntar a saída para o mudo.\n"; 
    cout << "4. Ignorar todos e seguir em frente.\n";
    int escolha;
    escolha = verificaInput(4);
    if(escolha == 1){
        cout << "Você gesticula para o macaco cego. Ele não vê. Você vai pro inferno.\n";
        fim_inferno();
    }else if(escolha == 2){
        cout << "Você fala com o macaco surdo. Ele não entende.\n";
        fim_inferno();
    }else if(escolha == 3){
        cout << "Você toca o macaco mudo. Ele olha para você e então aponta para um dos caminhos.\n";
        fim_inferno();
    }else if(escolha == 4){
        cout << "Você ignora todos os macacos e segue em frente. Nada nunca acontece chud.\n";
        cout << "Você não vê o mal. Você não fala o mal. Você não ouve o mal.\n";
        cout << "Eventualmente uma sala se revela a sua frente\n";
        fim_perfeito();
    }
}

void saida_falsa(){
    cout << "Você anda através da porta da saída tranquilamente. O caminho se revela curto e sem dificuldades.\n";
    cout << "Você saí por uma porta de saída de emergência vermelha.\n";
    if(reflexoAutonomo){
        cout << "Ao sair pela porta você sente um leve distúrbio momentâneo em algum reflexo das lojas. Mas ele desaparece\n";
        cout << "Você segue caminho andando em direção a saída da cidade.\n";
        reflexoSeguindo = true;
        fim_saida();
    }else{
        cout << "Você começa a andar em direção a saída da cidade\n";
        fim_saida();
    }
}

void espelho_sem_reflexo(){
    // - Espaço Sem Reflexo -> SUGEStão PODE FAZER O QUE QUISER AQUI em geral seguir em frente vai pro fim verdade
    // 1. Esperar.
    // 2. Seguir em frente.
    // 3. Gritar.
    cout << "Em dev\n"; // PEPEPPEPEPEPPEPEPE
    creditos();
}

void espelho_quebrado(){
    cout << "Você adentra uma sala onde todos espelhos estão quebrados. Cacos estilhaçados no chão. Somente resta um espelho inteiro no centro da sala.\n";
    cout << "\n";
    cout << "1. Olhar para o espelho.\n";
    cout << "2. Olhar para os cacos no chão.\n";
    cout << "3. Voltar.\n";
    
    int escolha;
    escolha = verificaInput(3);

    if(escolha  == 1){
        cout << "Você olha para o espelho inteiro. Seu corpo e alma são sugados para fora daquele plano dimensional terrível que você estava preso.\n";
        cout << "O mundo real lhe atinge como um tsunami. Fragmentos de memória retornam a pouco a pouco.\n";
        fim_perfeito();
    }else if(escolha  == 2){
        cout << "Você olha para os cacos no chão. Você vê a cidade da forma que ela realmente é. Um pequeno mundo no estômago de Azazoth \n";
        cout << "Você vê a verdade. E você não gosta dela.\n";
        fim_verdade();
    }else if(escolha  == 3){
        cout << "Você volta. E encontra o caminho para a saída.\n";
        fim_saida();
    }
    // - Espelho Quebrado (rota secreta good ending) - Fragmentos de realidades diferentes
    // 1. Fragmento de realidade A - Você vê a vida real. Rota de desvaneio romântico editada.
    // 2. Fragmento de realidade B - Você vê a cidade da forma que ela realmente é. Um pequeno mundo no estômago de Azazoth 
    // 3. Voltar.
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

void fim_verdade(){
    cout << "Em dev."; 
    // Final de descobrir a verdade do mundo o mundo na verdade ser um pesadelo de azazoth paralelo ao mundo real. Este pesadelo é mantido por entidades cósmicas que prendem a 
    // consciência de azazoth em um pentagrama de tamanho galático. Pode fazer sla alguma forma de vc acordar a criatura e o mundo acaba 
    // pq Azazoth é uma entidade que literalmente sonha com a nossa realidade no universo de lovecraft
    creditos();
}

void fim_espelho(){
    cout << "Em dev."; //cria algo ai
    // Você entra no espelho e fica vendo a criatura sair dele e andar livremente pela sala totalmente independente tomando o seu lugar no mundo até você não existir mais
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
    cout << "Você abre os olhos. O teto de seu quarto é talvez uma das coisas mais bonitas que você já viu. \n";
    cout << "O silêncio não é mais críptico e ensurdecedor. É pacífico.\n";
    cout << "Ao seu lado há um calor suave. Segurando em sua camisa com força mesmo em seu sono.\n";
    cout << "Você se vira. E de frente para ela, você agora lembra de tudo.\n";
    cout << "Seus cabelos pretos como a noite recaem sobre o lençou como tinta de polvo.\n"; 
    cout << "A luz da manhã passa pelas frestas da cortina, e seu cabelo reluz com o crepúsculo.\n";
    cout << "A sua face tão delicada, tão serena. Lhe faz brevemente esquecer os horrores que você passou.\n";
    cout << "Ela se mexe levemente bocejando e então se ajeitando novamente olhando para você por um breve segundo antes de retornar a dormir.\n";
    cout << "Você não tem a mínima vontade de levantar também. Retornando ao conforto do sono.\n";
    cout << "Você sente que finalmente está onde deveria estar.\n";
    cout << "Fim\n";
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
    cout << "Uma pequena fechadura se abre à sua frente. Você saiu da cidade. Mas você nunca esteve nela para começar. \n";
    if(reflexoSeguindo){
        cout << "Você retorna a realidade, mas em algum lugar do mundo agora há algo que não deveria estar ali.\n";
    }
    cout << "Fim.\n";
    creditos();
}

void fim_inferno(){
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