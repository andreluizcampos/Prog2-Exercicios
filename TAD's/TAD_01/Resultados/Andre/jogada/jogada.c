#include <stdio.h>
#include "jogada.h"

tJogada LeJogada()
{

    tJogada jogada;

    if (scanf("%d %d", &jogada.x, &jogada.y) == 2)
    {

        jogada.sucesso = 1;
    }

    return jogada;
}

int ObtemJogadaX(tJogada jogada)
{

    return jogada.x;
}
int ObtemJogadaY(tJogada jogada)
{

    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{

    return jogada.sucesso;
}
