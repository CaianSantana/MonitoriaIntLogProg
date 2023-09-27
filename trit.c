/******************************************************************************

Diferente dos computadores binários tradicionais, que fazem representações numéricas
usando dígitos binários, os computadores ternários balanceados fazem sua representação numérica
através de dígitos ternários balanceados ou trits.
No sistema de numeração ternário balanceado, de forma similar aos sistemas de representação tradiocionais, os valores numéricos são posicionais. 
Nesse caso, a base aplicada é a base três. 
Assim, o dígito mais à direita vale um, contudo, deslocá-lo uma posição à esquerda, equivale a multiplicá-lo por três.
Existem três trits possíveis: 2, 1 e 0. O trit 2 adiciona o valor posicional correspondente,
o 1 não adicioona nem subtrai e o 0, subtrai o valor em questão. 
Por exemplo: o número 222 em ternário balanceado equivale a: 9 + 3 + 1 = 13. Já o número 2010, equivale a 27-9+0-1=17.
Escreva um programa em C, que leia um número de até quatro trits e imprima o seu equivalente em
decimal.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int trit, decimal = 0, t1,t2,t3,t4;
    printf("Digite um nuhmero de ateh quatro trits(2,1,0): ");
    scanf("%d",&trit);
    // ***validação inicial***
    if(trit <0 || trit>2222) 
        return 1;
    // ***separando os números***
    t4= trit%10;
    if(trit>9)
         t3= (trit-(trit/100)*100)/10;
    else
        t3= 58;
    if(trit>99)
        t2= (trit-(trit/1000)*1000)/100;
    else
        t2 = 58;
    if(trit>999)
        t1= trit/1000;
    else
        t1= 58;
    //***verificando se é um trit***
    if(t4 == 0 || t4 == 1 || t4==2){
        if(t3 == 0 || t3 == 1 || t3==2){
            if(t2 == 0 || t2 == 1 || t2==2){
                if(t1 == 0 || t1 == 1 || t1==2){
                    //***atribuindo valores e já somando***
                    switch(t1){
                    case 0:
                        t1 = -27;
                        break;
                    case 1:
                        t1 = 0;
                        break;
                    case 2:
                        t1 = 27;
                        break;
                    }
                    decimal+= t1;
                }
                //***atribuindo valores e já somando***
                switch(t2){
                case 0:
                    t2 = -9;
                    break;
                case 1:
                    t2 = 0;
                    break;
                case 2:
                    t2 = 9;
                    break;
                }
                decimal+= t2;
            }
            //***atribuindo valores e já somando***
            switch(t3){
            case 0:
                t3 = -3;
                break;
            case 1:
                t3 = 0;
                break;
            case 2:
                t3 = 3;
                break;
            }
             decimal+= t3;
        }
        //***atribuindo valores e já somando***
        switch(t4){
        case 0:
            t4 = -1;
            break;
        case 1:
            t4 = 0;
            break;
        case 2:
            t4 = 1;
            break;
        }
         decimal+= t4;
    }
    //***printf final***
    printf("decimal: %d", decimal);
    return 0;
 
}
