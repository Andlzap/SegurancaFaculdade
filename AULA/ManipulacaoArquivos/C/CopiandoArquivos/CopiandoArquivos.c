#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *arquivoOriginal;
    FILE *arquivoCopia;
    char nomeArquivo[255];
    char nomeArquivoCopia[255];
    char extensao[255];
    unsigned char c;

    printf("\nDigite o caminho do arquivo (Sem extensao): ");
    scanf("%s", nomeArquivo);
    strcpy(nomeArquivoCopia, nomeArquivo);

    printf("\nDigite a extensao do arquivo (.pdf Example): ");
    scanf("%s", extensao);

    strcat(nomeArquivo, extensao);
    arquivoOriginal = fopen(nomeArquivo, "rb");


    if (arquivoOriginal == NULL)
    {
        printf("\nArquivo nao pode ser aberto ou inexistente\n");
    }
    else
    {

        strcat(nomeArquivoCopia, "Copia");
        strcat(nomeArquivoCopia, extensao);
        arquivoCopia = fopen(nomeArquivoCopia, "wb");

        while(!feof(arquivoOriginal))
        {
            c = fgetc(arquivoOriginal);
            if(!feof(arquivoOriginal))
            {
                fwrite(&c, 1, 1, arquivoCopia);
            }
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoCopia);
    return 1;
}
