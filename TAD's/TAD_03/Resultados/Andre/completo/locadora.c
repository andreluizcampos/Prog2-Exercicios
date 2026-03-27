#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "filme.h"
#include "locadora.h"
/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora()
{

    tLocadora locadora = {0};
    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo)
{

    for (int i = 0; i < locadora.numFilmes; i++)
    {

        if (locadora.filme[i].codigo == codigo)
        {

            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme)
{

    if (!verificarFilmeCadastrado(locadora, filme.codigo))
    {

        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
    }

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora)
{

    tFilme filme;
    int codigo = 0, i = 0, flag = 1;
    int codigos[50];

    for (int j = 0; j < 50; j++)
    {
        codigos[j] = -5;
    }

    while (scanf("%d, ", &codigo) == 1)
    {

        flag = 1;
        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);

        for (int j = 0; j < 50; j++)
        {
            if (codigos[j] == filme.codigo)
            {

                flag = 0;
            }
        }

        codigos[i] = codigo;
        i++;

        if (flag)
        {
            printf("Filme cadastrado %d - %s\n", codigo, filme.nome);
        }

        else
        {

            printf("Filme ja cadastrado no estoque\n");
        }
    }
    char c = '#';

    if (scanf(" %c ", &c) != 1 || c != '#')
    {

        exit(EXIT_FAILURE);
    }

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{

    int total_alugados = 0, custo_parcial = 0, alugado = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        alugado = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {

            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && locadora.filme[j].qtdEstoque > 0)
            {
                alugado = 1;
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                total_alugados++;
                custo_parcial += locadora.filme[j].valor;
            }

            else if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && locadora.filme[j].qtdEstoque <= 0)
            {

                printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                alugado = 1;
            }
        }

        if (!alugado)
        {

            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if (total_alugados > 0)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", total_alugados, custo_parcial);
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora)
{

    int codigos[MAX_FILMES];
    int i = 0, codigo = 0;

    while (scanf(" %d ", &codigo) == 1)
    {
        codigos[i] = codigo;
        i++;
    }

    char c = '#';

    if (scanf(" %c ", &c) != 1 || c != '#')
    {
        exit(EXIT_FAILURE);
    }

    return alugarFilmesLocadora(locadora, codigos, i);
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{

    int devolvido = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        devolvido = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {

            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && locadora.filme[j].qtdAlugada > 0)
            {

                locadora.lucro += locadora.filme[j].valor;

                devolvido = 1;

                locadora.filme[j] = devolverFilme(locadora.filme[j]);

                printf("Filme %d - %s Devolvido!\n", locadora.filme[j].codigo, locadora.filme[j].nome);
            }

            else if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && locadora.filme[j].qtdAlugada <= 0)
            {
                devolvido = 1;
                printf("Nao e possivel devolver o filme %d - %s.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
            }
        }
         if (!devolvido)
            {

                printf("Filme %d nao cadastrado.\n", codigos[i]);
            }
    }

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora)
{

    int codigos[MAX_FILMES], codigo = 0, j = 0;

    while (scanf("%d", &codigo) == 1)
    {

        codigos[j] = codigo;
        j++;
    }

    char c = '#';

    if (scanf(" %c ", &c) != 1 || c != '#')
    {

        exit(EXIT_FAILURE);
    }

    return devolverFilmesLocadora(locadora, codigos, j);
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora)
{

    int Flag = 1;

    tFilme temp;

    while (Flag)
    {

        Flag = 0;

        for (int i = 0; i < locadora.numFilmes - 1; i++)
        {

            if (strcmp(locadora.filme[i].nome, locadora.filme[i + 1].nome) > 0)
            {

                temp = locadora.filme[i];
                locadora.filme[i] = locadora.filme[i + 1];
                locadora.filme[i + 1] = temp;
                Flag = 1;
            }
        }
    }

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora)
{

    locadora = ordenarFilmesLocadora(locadora);

    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora.numFilmes; i++)
    {

        printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].qtdEstoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora)
{

    if (locadora.lucro > 0)
    {
        printf("Lucro total R$%d", locadora.lucro);
    }
}
