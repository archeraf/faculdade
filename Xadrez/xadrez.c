#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//I = vertical
//J = horizontal

int casasMovidas = 5;


//Método responsável pela movimentação da torre: Irá ser chamado de forma recursiva até que o número seja 0 e aí ele irá parar
void MovimentosTorre(int numero){

    if(numero > 0){
        printf("Direita\n");
        MovimentosTorre(numero-1);
    }
        
}

//Método responsável pela movimentação do bispo: Irá ser chamado de forma recursiva até que o número seja 0 e aí ele irá parar. Entretanto, este método possui 2 for aninhados, para escrever a direção que está indo.	
void MovimentosBispo(int numero){

    if(numero > 0){     
    for(int i = 0; i < 1; i++){
        printf("(");
        printf("Cima,");
        for(int j = 0; j < 1; j++){
            printf("Direita");
        }
        printf(")\n");
    }   
    MovimentosBispo(numero - 1);
    }
        

}

//Método responsável pela movimentação da rainha: Irá ser chamado de forma recursiva até que o número seja 0 e aí ele irá parar
void MovimentosRainha(int numero){

    if(numero > 0){

        printf("Esquerda\n");
        MovimentosRainha(numero-1);
    }
    
}

//Método responsável pela movimentação do cavalo. Enquanto o I representa as primeiras 2 casas, o J representa a casa posterior
void MovimentacaoCavalo(){

    printf("(");
    for(int i = 0, j = 0; i < 3; i++, j++){
        if(j < 2){
            printf("Cima,");
        }
        if(j == 2){            
            printf("Direita)\n");
        }
    }
}

//Método main
int main() {
    int numero = 5;
    printf("Bispo:\n");
    MovimentosBispo(numero);

    printf("Torre:\n");
    MovimentosTorre(numero);
    
    printf("Rainha:\n");
    numero = 8;
    MovimentosRainha(numero);

    printf("Cavalo:\n");
    MovimentacaoCavalo();
    return 0;
}