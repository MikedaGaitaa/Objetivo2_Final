#pragma once

#ifndef LEXER_H
#define LEXER_H

//Protótipo da função (Declaração)
//Recebe:
// 1. A String original (cmd)
// 2. O array onde guardar os ponteiros (tokens)
// 3. O número máximo de tokens permitidos (max_tokens)
// 4. Os delimitadores a usar (delim)
//Retorna: O número de tokens encontrados (int)

int AnaliseLexica(char* cmd, char** tokens, int max_token, const char* delim);

#endif
