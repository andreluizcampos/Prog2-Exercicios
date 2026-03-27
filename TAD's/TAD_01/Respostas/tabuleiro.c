#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro()
{

    tTabuleiro tabuleiro;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            tabuleiro.posicoes[i][j] = '-';
        }
    }

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
}
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (tabuleiro.posicoes[i][j] == '-')
            {

                return 1;
            }
        }
    }

    return 0;
}
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{

    if (peca == PECA_1)
    {

        if (tabuleiro.posicoes[x][y] == tabuleiro.peca1)
        {

            return 1;
        }

        return 0;
    }

    if (peca == PECA_2)
    {

        if (tabuleiro.posicoes[x][y] == tabuleiro.peca2)
        {

            return 1;
        }

        return 0;
    }
}


int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{

    if (tabuleiro.posicoes[x][y] == '-')
    {

        return 1;
    }

    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{

    if (x < 0 || x > 2)
    {

        return 0;
    }

    if (y < 0 || y > 2)
    {

        return 0;
    }

    return 1;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{

    int i = 0, j = 0;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}