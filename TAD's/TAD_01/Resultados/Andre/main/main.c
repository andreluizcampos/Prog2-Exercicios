#include<stdio.h>
#include"tabuleiro.h"
#include"jogador.h"
#include"jogada.h"
#include"jogo.h"


int main(){

tJogo jogo;
tJogada jogada;

    jogo = CriaJogo();
    ComecaJogo(jogo);

        while(1){

            jogada = LeJogada();
                
            

        }
}
