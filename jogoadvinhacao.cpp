#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int gerar;
// função cria numero aleatório
int gerar() {
    unsigned seed = time(0);
    srand(seed);
    return 1+rand()%100;
}

int main(){
    cout <<"--------------------------------------" << endl;
    cout <<"            Imitation game  "            << endl;
    cout <<"--------------------------------------" << endl;

    const int NUM_SECRETO = gerar();
    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    while(nao_acertou){
        tentativas++;
        cout << "Tentativa " << tentativas << endl;
        int chute;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUM_SECRETO) / 2.0;
        cout  << " o valor do seu chute é: "<< chute << endl;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUM_SECRETO;
        bool maior = chute > NUM_SECRETO;


        if(acertou){
            cout << "Parabens voce acertou o numero secreto" << endl;
            nao_acertou = false;
        }else if(maior){
            cout << "Seu chute foi maior que o numero secreto" << endl;

        }else{
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }
    }
    cout << "Fim de jogo" << endl;
    cout << "Voce acertou em " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << "Sua pontuação foi de "<< pontos << " Pontos. " << endl;
}