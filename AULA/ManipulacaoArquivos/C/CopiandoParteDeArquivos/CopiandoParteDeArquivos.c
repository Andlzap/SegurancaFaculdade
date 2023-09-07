#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivoOriginal;
    FILE *arquivoCopia;

    char nomeArquivo[255];
    char nomeArquivoCopia[255];
    char extensao[255];

    unsigned char c;
    int byteInicial;
    int byteFinal;
    int contador = 0;

    printf("\nDigite o caminho do arquivo (Sem extensao): ");
    scanf("%s", nomeArquivo);
    strcpy(nomeArquivoCopia, nomeArquivo);

    printf("\nDigite a extensao do arquivo (.pdf Example): ");
    scanf("%s", extensao);
    strcat(nomeArquivo, extensao);
    arquivoOriginal = fopen(nomeArquivo, "rb");

    printf("\nDigite o byte inicial: ");
    scanf("%d", &byteInicial);

    printf("\nDigite o byte final: ");
    scanf("%d", &byteFinal);


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
            contador++;
            c = fgetc(arquivoOriginal);
            if(!feof(arquivoOriginal) && contador >= byteInicial && contador <= byteFinal)
            {
                fwrite(&c, 1, 1, arquivoCopia);
            }
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoCopia);
    return 1;
}
