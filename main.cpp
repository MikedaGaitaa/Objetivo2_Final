#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "lexer.h"

#define MAX_CMD_SIZE 100
#define MAX_TOKENS 4


int main()
{
    char cmd[MAX_CMD_SIZE];       // memoria para a string
    char* tokens[MAX_TOKENS];     // memoria para os tokens (apontadores)
    int n_tokens = 0;             // inicializar a 1ª posicao livre
    const char* delim = " \r\n";  // Delimitador

    char* token_atual;            // Apontador que guarda o endereço do token que o strtok encontrou no buffer

    char continuar = 'S';
    char buffer_resposta[10];

    printf("--- Analise Lexica  ---\n\n");

    // CICLO INFINITO: O programa corre para sempre até o 'break' ser ativado
    while (continuar == 'S' || continuar == 's')
    {
        // Reinicia o contador a cada nova volta
        // Se isto não for feito isto, ele vai somar os tokens novos aos velhos e rebentar o array.
        n_tokens = 0;
        printf("Escreva o comando: ");
        // Ler a String
        if (fgets(cmd, MAX_CMD_SIZE, stdin) == NULL) {
            break; // Se houver erro de leitura, sai do ciclo
        }
        
        // Chama a função 
        n_tokens = AnaliseLexica(cmd, tokens, MAX_TOKENS, delim);
        // Apresenta  os Resultados
        printf("Numero de tokens encontrados: %d\n", n_tokens);
        for (int i = 0; i < n_tokens; ++i) {
            printf("Token[%d]: %s\n", i, tokens[i]);
        }

        printf("\nDeseja continuar? (S/N): ");
        if (fgets(buffer_resposta, sizeof(buffer_resposta), stdin) != NULL)
        {
            // O fgets lê a resposta.
            // Se o utilizador escrever, "S", "s", continua o programa
            continuar = buffer_resposta[0];
        }

        printf("--------------------------------------------------\n");
    }

    return 0;
}
