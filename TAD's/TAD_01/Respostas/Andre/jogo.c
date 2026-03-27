#include<stdio.h>
#include"tabuleiro.h"
#include"jogador.h"
#include"jogada.h"
#include"jogo.h"

 
tJogo CriaJogo(){

    tJogo jogo;

         return jogo;

}


void ComecaJogo(tJogo jogo){
    jogo.tabuleiro=CriaTabuleiro();
    jogo.jogador1=CriaJogador(ID_JOGADOR_2);
    jogo.jogador2=CriaJogador(ID_JOGADOR_2);
}

int AcabouJogo(tJogo jogo){


    if( !TemPosicaoLivreTabuleiro(jogo.tabuleiro)){

        return 0;
    }

    return 1;

    
}


