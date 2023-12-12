/******************************************************************************

m jogo de caças palavras é realizado através da apresentação de um conjunto de letras arranjadas de forma
aparentemente aleatórias em uma grade quadrada ou retangular. Nesta grade, os jogadores devem identificar,
de forma alternada, palavras, que devem ser procuradas no sentido horizontal e/ou vertical da grade.
Nesta variação do jogo, a pontuação por palavra é dependente do tamanho da palavra encontrada: i) caso a
palavra indicada pelo jogador não exista, ele recebe -5 pontos; caso exista, ii) a pontuação é o tamanho da
palavra encontrada.
Por exemplo, para a grade abaixo:
ABLNHEHLLTBQJFRGQH
KJULOCALIZARARVMNT
FEOGEQHTLOIDFMBAOE
RWBNUSGEVIXOIOXGUS
BRDARGTENTATIVAYJT
EARHSOWESLFVCDPZJE
WECSWATLXBMTLCDPNI
As palavras a seguir terão, respectivamente, a pontuação indicada:
• LOCALIZAR - 9 pontos
• TENTATIVA - 9 pontos
• BAIXA - 5 pontos
• TESTE - 5 pontos
• LOGICA - -5 pontos.
Escreva um programa que leia uma grade de MxN (para fins de teste, considere o valor de M como 7 e N 
como 17) caracteres e uma string (tamanho máximo igual ao maior(M,N) + 1, para fins de teste), 
procure a string na grade e indique a pontuação marcada, segundo as regras apresentadas. 

*******************************************************************************/
#define lin 7 
#define col 18

#include <stdio.h>

int main()
{
    char grade[lin][col] = {
                {'A','B','L','N','H','E','H','L','L','T','B','Q','J','F','R','G','Q','H'},
                {'K','J','U','L','O','C','A','L','I','Z','A','R','A','R','V','M','N','T'},
                {'F','E','O','G','E','Q','H','T','L','O','I','D','F','M','B','A','O','E'},
                {'R','W','B','N','U','S','G','E','V','I','X','O','I','O','X','G','U','S'}, 
                {'B','R','D','A','R','G','T','E','N','T','A','T','I','V','A','Y','J','T'},
                {'E','A','R','H','S','O','W','E','S','L','F','V','C','D','P','Z','J','E'},
                {'W','E','C','S','W','A','T','L','X','B','M','T','L','C','D','P','N','I'}
    };
    char palavra[col+1];
    int tamPalavra=0;
    printf("Digite uma palavra:");
    scanf("%s", &palavra);
    for(int i = 0; palavra[i]!='\0'; i++){
        tamPalavra+=1;
    }
    for(int linha = 0; linha<7; linha++){
        for(int coluna = 0; coluna<col; coluna++){
            int contI = 0, contJ = 0;
            if(palavra[0] == grade[linha][coluna]){
                for(int i = 1; i<=col; i++){
                    if(palavra[i] == grade[linha][coluna+i] || palavra[i] == grade[linha][coluna-i]){
                        contI++;
                    }else if(palavra[i] == grade[linha+i][coluna] || palavra[i] == grade[linha-i][coluna]){
                        contJ++;
                    }else{
                        if(contI >= tamPalavra-1 || contJ >= tamPalavra-1){
                            printf("%d pontos", tamPalavra);
                            return 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("-5 pontos");
    return 0;
}


