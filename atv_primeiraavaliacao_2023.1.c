/******************************************************************************

É sua tarefa fazer a validação e definição dos limites sugeridos para uma reserva de
grandes felinos. Para tanto, seu programa deve ler oito valores sendo, que os quatro
primeiros dizem respeito a uma das duas áreas (de floresta densa ou de caça) e os quatro
últimos, à área restante.
1. o primeiro e segundo, são as coordenadas (x, y) do canto superior esquerdo (em um
mapa bidimensional) do primeiro terreno;
2. o terceiro, a dimensão vertical do primeiro terreno;
3. o quarto, diz respeito à dimensão horizontal do primeiro terreno;
4. o quinto e sexto, são as coordenadas (x, y) do canto superior esquerdo (em um
mapa bidimensional) do segundo terreno;
5. o sétimo, a dimensão vertical do segundo terreno; e
6. o oitavo, diz respeito à dimensão horizontal do segundo terreno.
Considere que os terrenos são quadriláteros regulares, define-se como área sugerida de
reserva, a área de sobreposição dos dois terrenos, caso ela exista.
Seu programa deve indicar as coordenadas do canto superior da área sugerida, bem como
a dimensão horizontal e vertical desta área, ou informar que não existe área sugerida de
reserva, se não houver a superposição

*******************************************************************************/
#include <stdio.h>

int main()
{
    int coordenada1, coordenada2, largura1, comprimento1, subcoordenada1, subcoordenada2, sublargura1, subcomprimento2;
    int xEfetivo, yEfetivo, subXEfetivo, subYEfetivo;
    //Bloco de leitura de variável
    printf("Digite as coordenadas (x,y) da área de Floresta densa: ");
    scanf("%i%i",&coordenada1, &coordenada2);
    printf("Digite a largura e comprimento da área: ");
    scanf("%i%i",&largura1, &comprimento1);
    printf("Digite as coordenadas (x,y) da área de reserva: ");
    scanf("%i%i",&subcoordenada1, &subcoordenada2);
    printf("Digite a largura e comprimento da área de reserva: ");
    scanf("%i%i",&sublargura1, &subcomprimento2);
    
    //Bloco de efetivação de área
    xEfetivo = coordenada1+comprimento1;
    yEfetivo = coordenada2+largura1;
    subXEfetivo = subcoordenada1+subcomprimento2;
    subYEfetivo = subcoordenada2+sublargura1;
    
    //Bloco de decisões
    if(xEfetivo < subcoordenada1 || xEfetivo < subXEfetivo){
        printf("NÃO EXISTE ÁREA SUGERIDA");
        return 1;
    }
    if(yEfetivo < subcoordenada2 || yEfetivo < subYEfetivo){
        printf("NÃO EXISTE ÁREA SUGERIDA");
        return 1;
    }
    
    //Bloco de impressão
    printf("Área alocada.\nMedidas da Área de Floresta densa: \n");
    printf("Coordenadas(x,y): %i%i\n", coordenada1, coordenada2);
    printf("Comprimento: %i\n Largura: %i\n",comprimento1, largura1);
    printf("Medidas da Área de reserva: \n");
    printf("Coordenadas(x,y): %i%i\n", subcoordenada1, subcoordenada2);
    printf("Comprimento: %i\n Largura: %i\n,",subcomprimento2, sublargura1);
    return 0;
    
}
