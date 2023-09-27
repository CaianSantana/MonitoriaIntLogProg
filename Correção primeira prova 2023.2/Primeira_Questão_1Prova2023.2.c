/******************************************************************************

Questão 1:
Entrar com o numero maior que vai definir o limite e entrar com a expressão codificada.
Na expressão codificada, o 4° numero menos significativo representa a operação. 
1 é adição 
2 é subtração 
3 é multiplicação 
4 é divisão 
Os tres mais significativos vão realizar a operação com os três menos significativos.

Se o numero expresso ultrapassar o valor limite, deverar ser escrito "Overflow".
 
O valor 2501008 é 258 e deve escrever Overflow. Ja o valor 5020008 deve sair 42.

Os três menos significativos fazem subtração
Os três mais significativos fazem adição

*******************************************************************************/
#include <stdio.h>

int main()
{
    //Declaracao de variaveis
    int numero, primeiro, segundo, terceiro, digitoOperacao, quinto, sexto, setimo, tresprimeiros, tresultimos, resultado, limite;
    //Recebendo valor do limite e do numero
    printf("Digite o limite: ");
    scanf("%d",&limite);
    printf("Digite um numero de 7 dígitos: ");
    scanf("%d",&numero);
    //desestruturando o numero
    primeiro = (numero/1000000)*100;
    segundo = ((numero/100000)%10)*10;
    terceiro = (numero/10000)%10;
    digitoOperacao = (numero/1000)%10;
    quinto = ((numero/100)%10)*100;
    sexto = ((numero/10)%10)*10;
    setimo = numero%10;
    //medidas caso o quarto numero seja 0
    if(digitoOperacao <1 || digitoOperacao>4){
        digitoOperacao = terceiro;
        terceiro = 0;
        primeiro/=10;
        segundo/=10;
        if(digitoOperacao <1 || digitoOperacao>4){
            digitoOperacao = segundo;
            segundo = 0;
            primeiro/=10;
            if(digitoOperacao <1 || digitoOperacao>4){
                digitoOperacao = primeiro;
            }
        }
    }
    //transformando os numeros separados em unidades de tres casas
    tresprimeiros = primeiro+segundo+terceiro;
    tresultimos = quinto+sexto+setimo;
    
    //verificando qual a operacao a ser realizada
    switch(digitoOperacao){
        case 1:
            resultado=tresprimeiros+tresultimos;
            break;
        case 2:
            resultado=tresprimeiros-tresultimos;
            break;
        case 3:
            resultado=tresprimeiros*tresultimos;
            break;
        case 4:
            resultado=tresprimeiros/tresultimos;
            break;
    }
    //verificando se é overflow ou nao.
    if(resultado>limite){
        printf("Overflow");
    }else{
        printf("resultado: %d", resultado);
    }
    return 0;
}
