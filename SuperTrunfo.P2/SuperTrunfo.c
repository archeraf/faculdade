#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Declaração de variáveis globais
char pais[20], pais2[20],atributoSelecionado1[30], atributoSelecionado2[30];
int qtdPontosTur, qtdPontosTur2,opcaoSelec, opcaoSelec2, vencedor1,vencedor2;
float area, area2, pib, pib2,densidadePop,densidadePop2, pibCapita, pibCapita2, superPod, superPod2, soma1, soma2,atributoA1,atributoA2, atributoB1,atributoB2;
unsigned long int populacao, populacao2;



//Método responsável por calcular e retornar o PIB per capita
float calcularPibPerCapita(int populacao, float pib){
    return pib/populacao;
}

//Método responsável por calcular e retornar a densidade populacional
float calcularDensidadePop(int populacao, float area){
    return (float)populacao/area;
}

//Método responsável por calcular e retornar o super poder
float calcularSuperPod(int populacao, int qtdPontosTur, float area, float pib, float densidadePop, float pibCapita){
    return (float)populacao + (float)qtdPontosTur + area + pib + densidadePop + pibCapita;
}

//Métodos responsáveis pela coleta de dados das cartas
void ColetarDados(){
    printf("Dados da carta 1:\n");
    printf("Digite o pais:\n");
    scanf(" %19s", &pais);
    
    printf("Digite a populacao do pais:\n");
    scanf("%i", &populacao);

    printf("Digite quantos pontos turisticos existem no pais:\n");
    scanf("%i", &qtdPontosTur);
    
    printf("Digite pib:\n");
    scanf("%f", &pib);
    
    printf("Digite a area do pais:\n");
    scanf("%f", &area);

    pibCapita = (float)calcularPibPerCapita(populacao,pib);
    densidadePop = calcularDensidadePop(populacao,area);
    superPod = calcularSuperPod(populacao, qtdPontosTur, area, pib, densidadePop, pibCapita);
    
    printf("Dados da carta 2:\n");

    printf("Digite o nome do pais:\n");
    scanf("%19s", &pais2);
    
    printf("Digite a populacao do pais:\n");
    scanf("%i", &populacao2);

    printf("Digite quantos pontos turisticos existem no pais:\n");
    scanf("%i", &qtdPontosTur2);
    
    printf("Digite pib:\n");
    scanf("%f", &pib2);
    
    printf("Digite a area do pais:\n");
    scanf("%f", &area2);

    pibCapita2 = calcularPibPerCapita(populacao2,pib2);
    densidadePop2 = calcularDensidadePop(populacao2,area2);
    superPod2 = calcularSuperPod(populacao2, qtdPontosTur2, area2, pib2, densidadePop2, pibCapita2);
    
}

//Método responsável por coletar e somar os atributos
void ColetarSoma(float valor1, float  valor2)
{
    soma1 += valor1;
    soma2 += valor2;
}
//Método responsável pela exibição dos dados
void ExibirResultados(){
    printf("Comparações:\n");
    
    printf("Carta 1 - %s:\n", pais);
    printf("Soma dos atributos da carta 1: %.2f\n", soma1);

    printf("Carta 2 - %s:\n", pais2);
    printf("Soma dos atributos da carta 2: %.2f\n", soma2);
    
    printf("Comparação de %s\n", atributoSelecionado1);
    printf("Valor de %s da carta 1: %.2f\n",atributoSelecionado1,atributoA1);
    printf("Valor de %s da carta 2: %.2f\n",atributoSelecionado1,atributoA2);

    if(vencedor1 == 1){
        printf("Carta 1 ganha\n\n");
    } else if(vencedor1 == 2){
        printf("Carta 2 ganha\n\n");
    } else{
        printf("Empate\n\n");
    }

    printf("Comparação de %s\n", atributoSelecionado2);
    printf("Valor de %s da carta 1: %.2f\n",atributoSelecionado2,atributoB1);
    printf("Valor de %s da carta 2: %.2f\n",atributoSelecionado2,atributoB2);
    
    if(vencedor2 == 1){
        printf("Carta 1 ganha\n\n");
    } else if(vencedor2 == 2){
        printf("Carta 2 ganha\n\n");
    } else{
        printf("Empate\n\n");
    }
    
}

//Método responsável por comparar e decidir o vencedor nas comparações de atributos
void CompararAtributo(float atributo1, float atributo2, int opcao){

    if(opcao == 1)
    {
        if(opcaoSelec == 5)
        {
            vencedor1 = atributo1 < atributo2 ? 1 : atributo1 == atributo2 ? 0 : 2;
        } else{
            vencedor1 = atributo1 > atributo2 ? 1 : atributo1 == atributo2 ? 0 : 2;
        }
    }

    if(opcao == 2)
    {
        if(opcaoSelec2 == 5)
        {
            vencedor2 = atributo1 < atributo2 ? 1 : atributo1 == atributo2 ? 0 : 2;
        } else{
            vencedor2 = atributo1 > atributo2 ? 1 : atributo1 == atributo2 ? 0 : 2;
        }
    }
}

//Método para realizar a saída do menu.
void ExitMenu(){
    system("cls");
    printf("Obrigado por utilizar o Super Trunfo!\n");
}



//Método que executa as comparações e chama cada método necessário para o preenchimento das informações.
void ExecutarComparacao(int opcao, int opcao2){

    switch(opcao){
        case 1:
            atributoA1 = (float)populacao;
            atributoA2 = (float)populacao2;
            ColetarSoma((float)populacao, (float)populacao2);
            strcpy(atributoSelecionado1, "População");
            CompararAtributo((float)populacao, (float)populacao2, 1);
            break;
        case 2:
            atributoA1 = pib;
            atributoA2 = pib2;
            ColetarSoma(pib, pib2);
            strcpy(atributoSelecionado1, "PIB");
            CompararAtributo(pib, pib2, 1);
            break;
        case 3:
            atributoA1 = pibCapita;
            atributoA2 = pibCapita2;
            ColetarSoma(pibCapita, pibCapita2);          
            strcpy(atributoSelecionado1, "PIB per Capita");
            CompararAtributo(pibCapita, pibCapita2, 1);
            break;
        case 4:
            atributoA1 = area;
            atributoA2 = area2;
            ColetarSoma(area, area2);
            strcpy(atributoSelecionado1, "Area");
            CompararAtributo(area, area2, 1);
            break;
        case 5:
            atributoA1 = densidadePop;
            atributoA2 = densidadePop2;            
            ColetarSoma(densidadePop, densidadePop2);
            strcpy(atributoSelecionado1, "Densidade Populacional");
            CompararAtributo(densidadePop, densidadePop2, 1);
            break;
        case 6:
            atributoA1 = qtdPontosTur;
            atributoA2 = qtdPontosTur2;
            ColetarSoma(qtdPontosTur, qtdPontosTur2);
            strcpy(atributoSelecionado1, "Pontos Turisticos");
            CompararAtributo(qtdPontosTur, qtdPontosTur2, 1);
            break;
        case 7:
            atributoA1 = superPod;
            atributoA2 = superPod2;
            ColetarSoma(superPod, superPod2);
            strcpy(atributoSelecionado1, "Super Poder");
            CompararAtributo(superPod, superPod2, 1);
            break;
        default:
            printf("Opção invalida!\n");
            break;
    }

    switch(opcao2){
        case 1:
            atributoB1 = (float)populacao;
            atributoB2 = (float)populacao2;
            ColetarSoma((float)populacao, (float)populacao2);
            strcpy(atributoSelecionado2, "População");
            CompararAtributo((float)populacao, (float)populacao2, 2);
            break;
        case 2:
            atributoB1 = pib;
            atributoB2 = pib2;
            ColetarSoma(pib, pib2);
            strcpy(atributoSelecionado2, "PIB");
            CompararAtributo(pib, pib2, 2);
            break;
        case 3:
            atributoB1 = pibCapita;
            atributoB2 = pibCapita2;
            ColetarSoma(pibCapita, pibCapita2);
            strcpy(atributoSelecionado2, "PIB per Capita");
            CompararAtributo(pibCapita, pibCapita2, 2);
            break;
        case 4:
            atributoB1 = area;
            atributoB2 = area2;
            ColetarSoma(area, area2);
            strcpy(atributoSelecionado2, "Area");
            CompararAtributo(area, area2, 2);
            break;
        case 5:
            atributoB1 = densidadePop;
            atributoB2 = densidadePop2;
            ColetarSoma(densidadePop, densidadePop2);
            strcpy(atributoSelecionado2, "Densidade Populacional");
            CompararAtributo(densidadePop, densidadePop2, 2);
            break;
        case 6:
            atributoB1 = qtdPontosTur;
            atributoB2 = qtdPontosTur2;
            ColetarSoma(qtdPontosTur, qtdPontosTur2);
            strcpy(atributoSelecionado2, "Pontos Turisticos");
            CompararAtributo(qtdPontosTur, qtdPontosTur2, 2);
            break;
        case 7:
            atributoB1 = superPod;
            atributoB2 = superPod2;            
            ColetarSoma(superPod, superPod2);
            strcpy(atributoSelecionado2, "Super Poder");
            CompararAtributo(superPod, superPod2, 2);
            break;
        default:
            printf("Opção invalida!\n");
            break;
    }

}


void ExibirMenu(){

    system("cls");
    printf("Bem vindo ao Super Trunfo!\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comparar Populacao\n");
    printf("2 - Comparar PIB\n");
    printf("3 - Comparar PIB per Capita\n");
    printf("4 - Comparar Area\n");
    printf("5 - Comparar Densidade Populacional\n");
    printf("6 - Comparar Pontos Turisticos\n");
    printf("7 - Comparar Super Poder\n");    
    printf("8 - Sair\n");

    scanf("%i", &opcaoSelec);

    if(opcaoSelec != 8)
    {

        printf("Escolha a segunda opcao:\n");
        if(opcaoSelec != 1){
            printf("1 - Comparar Populacao\n");
        }
        if(opcaoSelec != 2){
            printf("2 - Comparar PIB\n");     
        }
        if(opcaoSelec != 3){
            printf("3 - Comparar PIB per Capita\n");
        }
        if(opcaoSelec != 4){
            printf("4 - Comparar Area\n");
        }
        if(opcaoSelec != 5){
            printf("5 - Comparar Densidade Populacional\n");
        }
        if(opcaoSelec != 6){
            printf("6 - Comparar Pontos Turisticos\n");
        }
        if(opcaoSelec != 7){
            printf("7 - Comparar Super Poder\n");
        }
        printf("8 - Sair\n");
    
        scanf("%i", &opcaoSelec2);
    
        if(opcaoSelec == opcaoSelec2){
            printf("Opcoes nao podem ser iguais, finalizando SuperTrunfo!\n");
            return;
        }
    
    } else{
        ExitMenu();
    }
}


//Método main com a chamada para os demais métodos
int main() {

   ColetarDados();
   ExibirMenu();
   ExecutarComparacao(opcaoSelec, opcaoSelec2);
   ExibirResultados();


    return 0;
}