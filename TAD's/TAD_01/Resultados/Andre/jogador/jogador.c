#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador)
{

    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{

    tJogada jogada;
    int x, y;

    while (1)
    {

        jogada = LeJogada();
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if (!FoiJogadaBemSucedida)
        {

            exit(EXIT_FAILURE);
        }

        if (!EhPosicaoValidaTabuleiro(x, y))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",
                   x, y);
        }
        else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        }
        else
        {
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
            printf("Jogada [%d,%d]!\n", x, y);
            break;
        }
    }
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{

    int count = 0;

    if (jogador.id == 1)
    {
        for (int i = 0; i < TAM_TABULEIRO; i++)
        {

            for (int j = 0; j < TAM_TABULEIRO; j++)
            {

                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1)
                {

                    count++;
                }

                if (count == 3)
                {

                    return 1;
                }
            }
        }

        count = 0;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            for (int i = 0; i < TAM_TABULEIRO; i++)
            {

                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1)
                {

                    count++;
                }

                if (count == 3)
                {

                    return 1;
                }
            }
        }

        count = 0;

        for (int i = 0; i < TAM_TABULEIRO; i++)
        {

            if (tabuleiro.posicoes[i][i] == tabuleiro.peca1)
            {

                count++;
            }

            if (count == 3)
            {

                return 1;
            }
        }

        count = 0;

        for (int i = TAM_TABULEIRO; i > 0; i--)
        {

            if (tabuleiro.posicoes[i][i] == tabuleiro.peca1)
            {

                count++;
            }

            if (count == 3)
            {

                return 1;
            }
        }
    }

    if (jogador.id == 2)
    {

        for (int i = 0; i < TAM_TABULEIRO; i++)
        {

            for (int j = 0; j < TAM_TABULEIRO; j++)
            {

                if (tabuleiro.posicoes[i][j] == tabuleiro.peca2)
                {

                    count++;
                }

                if (count == 3)
                {

                    return 1;
                }
            }
        }

        count = 0;
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            for (int i = 0; i < TAM_TABULEIRO; i++)
            {

                if (tabuleiro.posicoes[i][j] == tabuleiro.peca2)
                {

                    count++;
                }

                if (count == 3)
                {

                    return 1;
                }
            }
        }

        count = 0;

        for (int i = 0; i < TAM_TABULEIRO; i++)
        {

            if (tabuleiro.posicoes[i][i] == tabuleiro.peca2)
            {

                count++;
            }

            if (count == 3)
            {

                return 1;
            }
        }

        count = 0;

        for (int i = TAM_TABULEIRO; i > 0; i--)
        {

            if (tabuleiro.posicoes[i][i] == tabuleiro.peca2)
            {

                count++;
            }

            if (count == 3)
            {

                return 1;
            }
        }
    }
    return 0;
}
