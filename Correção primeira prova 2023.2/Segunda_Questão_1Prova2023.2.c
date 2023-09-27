/******************************************************************************

O codigo tem duas entradas, um número de 0 até 31. E um valor de bit de 0 a 4.
O codigo se baseia na alteração genética, onde existe um swap q o valor de bits será trocado pelo seu complementar.

Então a questão mostra que o binario 28
11100
Se torna 11000 quando o valor de bit escolhido for 3.

A saída que eu me lembre era para mostrar o binario e o número que fosse sair.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, numbinario=0, aux, bit;
    printf("Digite um número de 0 a 31 e um bit de 0 a 4: ");
    scanf("%d%d",&num, &bit);
    aux = num;
    if(aux%2!=0){
        numbinario+=1;
    }
    aux/=2;
    if(aux%2!=0){
        numbinario+=10;
    }
    aux/=2;
    if(aux%2!=0){
        numbinario+=100;
    }
    aux/=2;
    if(aux%2!=0){
        numbinario+=1000;
    }
    aux/=2;
    if(aux%2!=0){
        numbinario+=10000;
    }
    aux=numbinario;
    switch(bit){
        case 0:
            if(aux%10==1){
                aux-=1;
            }else{
                aux+=1;
            }
            break;
        case 1:
            if((aux/10)%10==1){
                aux-=10;
            }else{
                aux+=10;
            }
            break;
        case 2:
            if((aux/100)%10==1){
                aux-=100;
            }else{
                aux+=100;
            }
            break;
        case 3:
            if((aux/1000)%10==1){
                aux-=1000;
            }else{
                aux+=1000;
            }
            break;
        case 4:
            if((aux/10000)%10==1){
                aux-=10000;
            }else{
                aux+=10000;
            }
            break;
    }
    printf("Numero binario original: %d\nNumero binario apos o swap: %d",numbinario, aux);
    return 0;
}

