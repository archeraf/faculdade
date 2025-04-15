#include <stdio.h>
#include <stdlib.h>

int mesa[10][10], MatrizCone[5][5], MatrizCruz[5][5], MatrizOcta[5][5], barco1[3] = {3,3,3}, barco2[3] = {3,3,3};


// Inicializa a matriz mesa com 0s
// A matriz mesa representa o tabuleiro de batalha naval
void InicializarMatrizMesa(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mesa[i][j] = 0; // Inicializa a matriz com 0
        }
}}


// Inicializa a matriz Cone com 1s na forma de um cone
void InicializarMatrizCone(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            MatrizCone[i][j] = 0;
            if(i == 2){
                MatrizCone[i][j] = 1; // Preenche a linha do meio com 1
            }
            if(j == 2 && i <= 2){
                MatrizCone[i][j] = 1; // Preenche a coluna do meio com 1
            }
            if(i == 1 && (j >= 1 && j <= 3)){
                MatrizCone[i][j] = 1; // Preenche a linha do meio com 1
            }
        }
    }
}


// Inicializa a matriz Cruz com 1s na forma de uma cruz
void InicializarMatrizCruz(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            MatrizCruz[i][j] = 0;
            if(i == 2){
                MatrizCruz[i][j] = 1; // Preenche a linha do meio com 1
            }
            if(j == 2){
                MatrizCruz[i][j] = 1; // Preenche a coluna do meio com 1
            }
        }
    }
}

/// Inicializa a matriz octa com 1s na forma de um octaedro
void InicializarMatrizOcta(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            MatrizOcta[i][j] = 0;
            if(i == 2 && (j >= 1 && j <= 3)){
                MatrizOcta[i][j] = 1;
            }
            if(j == 2 && (i >= 1 && i <= 3)){
                MatrizOcta[i][j] = 1;
            }
        }
    }
}

// Desenha o barco na matriz de acordo com a direção
// 1 - Horizontal, 2 - Vertical, 3 - Diagonal
// linha e coluna são as coordenadas iniciais do barco
void DesenharBarco(int linha, int coluna, int direcao){
    
    if(linha < 0 || linha >= 9 || coluna < 0 || coluna >= 9 || linha + 2 >= 9 || coluna + 2 >= 9){
        printf("Falha ao desenhar o barco com posição inicial na linha %i e coluna %i!\n", linha, coluna);
        printf("O barco deve ficar dentro dos limites do tabuleiro!\n");
        return;
    }
    if(mesa[linha][coluna] == 3 || mesa[linha + 1][coluna] == 3 || mesa[linha + 2][coluna] == 3){
        printf("Falha ao desenhar o barco, posição ocupada!\n");
        return;
    }

    for(int i = 0; i < 3; i++){
        if(direcao == 1){
            mesa[linha][coluna + i] = 3;
        } 
        if(direcao == 2){
            mesa[linha + i][coluna] = 3;
        }
        if(direcao == 3){
            mesa[linha + i][coluna + i] = 3;
        }
    }
}

/// Desenha a habilidade na matriz
/// 1 - Cone, 2 - Cruz, 3 - Octa
/// linha e coluna são as coordenadas iniciais da habilidade
void SobreposicaoHabilidade(int linha, int coluna, int habilidade)
{
    if(linha < 0 || linha >= 9 || coluna < 0 || coluna >= 9 || linha + 2 >= 9 || coluna + 2 >= 9){
        printf("Falha ao desenhar a habilidade, com posição inicial na linha %i e coluna %i!\n", linha, coluna);
        return;
    }

    if(habilidade == 1){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(MatrizCone[i][j] == 1){
                    mesa[linha + i][coluna + j] = 5;
                }
            }
        }
    } else if(habilidade == 2){
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(MatrizCruz[i][j] == 1){
                    mesa[linha + i][coluna + j] = 5;
                }
            }
        }
    } else if(habilidade == 3){
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(MatrizOcta[i][j] == 1){
                    mesa[linha + i][coluna + j] = 5;
                }
            }
        }
    } else{
        printf("Habilidade inválida!\n");
        return;
    }
    
}

// Desenha o tabuleiro de batalha naval
void DesenharTabuleiro(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j<9){

                printf("%i ", (int)mesa[i][j]);
            } else{
                printf("%i \n",(int)mesa[i][j]);
            }
        }
    }
}

int main(){

    InicializarMatrizMesa();
    InicializarMatrizCone();
    InicializarMatrizCruz();
    InicializarMatrizOcta();
    DesenharBarco(2,1,1);
    DesenharBarco(5,5,2);
    DesenharBarco(8,7,3);
    SobreposicaoHabilidade(0,0,1);
    SobreposicaoHabilidade(2,2,2);
    SobreposicaoHabilidade(4,4,3);
    DesenharTabuleiro();
    return 0;
}