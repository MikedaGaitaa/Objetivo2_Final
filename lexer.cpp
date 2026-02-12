#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "lexer.h"

int AnaliseLexica(char* cmd, char** tokens, int max_tokens, const char* delim)
{
	int n_tokens = 0;
	char* token_atual;

    token_atual = strtok(cmd, delim); // tenta extrair o 1º token
    // usa-se cmd que é para  função strtok começar a procurar nessa string cmd


    while (token_atual != NULL) // verifica se existe tokens no cmd -> SIM
    {
        if (n_tokens < max_tokens) // so guardas o token enquanto houver espaço livre
        {
            tokens[n_tokens] = token_atual; //Guardá-lo em tokens, na proxima posiçao livre
            n_tokens++; // incrementa a proxima posicao livre em tokens
        }
        else
        {
            printf("Numero maximo de tokens alcancados\n");
            break;
        }

        token_atual = strtok(NULL, delim); //extrai o proximo token do cmd
        // usa-se o NULL que é para a função strtok usar a posição que tem

    }

    //retorna o total para quem chamou a função saber quantos tokens são
    return n_tokens;
}
