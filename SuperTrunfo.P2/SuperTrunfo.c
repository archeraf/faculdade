#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//Declaração de variáveis globais
char pais[20], pais2[20];
int qtdPontosTur, qtdPontosTur2, resultadoPopulacao;
float area, area2, pib, pib2,densidadePop,densidadePop2, pibCapita, pibCapita2, superPod, superPod2;
unsigned long int populacao, populacao2,opcao;



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
    printf("Digite o país:\n");
    scanf(" %19s", &pais);
    
    printf("Digite a população do país:\n");
    scanf("%i", &populacao);

    printf("Digite quantos pontos turísticos exisatem no país:\n");
    scanf("%i", &qtdPontosTur);
    
    printf("Digite pib:\n");
    scanf("%f", &pib);
    
    printf("Digite a area do país:\n");
    scanf("%f", &area);

    pibCapita = (float)calcularPibPerCapita(populacao,pib);
    densidadePop = calcularDensidadePop(populacao,area);
    superPod = calcularSuperPod(populacao, qtdPontosTur, area, pib, densidadePop, pibCapita);
    
    printf("Dados da carta 2:\n");

    printf("Digite o nome do país:\n");
    scanf("%19s", &pais2);
    
    printf("Digite a população do país:\n");
    scanf("%i", &populacao2);

    printf("Digite quantos pontos turísticos existem na cidade:\n");
    scanf("%i", &qtdPontosTur2);
    
    printf("Digite pib:\n");
    scanf("%f", &pib2);
    
    printf("Digite a area do país:\n");
    scanf("%f", &area2);

    pibCapita2 = calcularPibPerCapita(populacao2,pib2);
    densidadePop2 = calcularDensidadePop(populacao2,area2);
    superPod2 = calcularSuperPod(populacao2, qtdPontosTur2, area2, pib2, densidadePop2, pibCapita2);
    
}

//Método responsável pela exibição dos dados
void ExibirDados(){
    printf("Carta 1:\n");
    printf("País: %s\n",pais);
    printf("População do país: %i\n", populacao);
    printf("Qtd pontos turísticos do país: %i\n", qtdPontosTur);
    printf("Pib do país: %.2f\n", pib);
    printf("Area do país: %.2f\n", area);
    printf("Densidade populacional: %.2f\n", densidadePop);
    printf("PIB per Capita: %.2f\n", pibCapita);
    printf("Super poder: %.2f\n", superPod);


    //Exibindo dados da segunda carta
    printf("\nCarta 2:\n");
    printf("País: %20s \n", pais2);
    printf("População do país: %i \n", populacao2);
    printf("Qtd pontos turísticos do país: %i \n", qtdPontosTur2);
    printf("Pib do país: %.2f \n", pib2);
    printf("Area do país: %.2f \n", area2);
    printf("Densidade populacional: %.2f\n", densidadePop2);
    printf("PIB per Capita: %.2f\n", pibCapita2);
    printf("Super poder: %.2f\n", superPod2);

}

void CompararEExibirPopulacao(){
    printf("Comparação de populações:\n");
    printf("Carta 1: %lu\n", populacao);
    printf("Carta 2: %lu\n", populacao2);

    if(populacao > populacao2){
        printf("População da carta 1 é maior que da carta 2.\n");
    } else{
        printf("População da carta 2 é maior que a população da carta 1\n");
    }
}

void CompararPib(){
    printf("Comparação de PIB:\n");
    printf("Carta 1 - %s: %.2f\n",pais, pib);
    printf("Carta 2 - %s: %.2f\n",pais2, pib2);

    if(pib > pib2){
        printf("PIB da carta 1 é maior que da carta 2.\n");
    } else{
        printf("PIB da carta 2 é maior que a PIB da carta 1\n");
    }
}

void CompararPibPerCapita(){
    printf("Comparação de PIB per Capita:\n");
    printf("Carta 1 - %s: %.2f\n", pais, pibCapita);
    printf("Carta 2 - %s: %.2f\n", pais2, pibCapita2);

    if(pibCapita > pibCapita2){
        printf("PIB per Capita da carta 1 é maior que da carta 2.\n");
    } else{
        printf("PIB per Capita da carta 2 é maior que a PIB per Capita da carta 1\n");
    }   
}

void CompararArea(){
    printf("Comparação de Area:\n");
    printf("Carta 1 - %s: %.2f\n", pais, area);
    printf("Carta 2 - %s: %.2f\n", pais2, area2);

    if(area > area2){
        printf("Area da carta 1 é maior que da carta 2.\n");
    } else{
        printf("Area da carta 2 é maior que a Area da carta 1\n");
    }   
}

void CompararDensidadeDemografica(){
    printf("Comparação de Densidade Demografica:\n");
    printf("Carta 1 - %s: %.2f\n", pais, densidadePop);
    printf("Carta 2 - %s: %.2f\n", pais2, densidadePop2);

    if(densidadePop < densidadePop2){
        printf("Densidade Demografica da carta 1 é maior que da carta 2.\n");
    } else{
        printf("Densidade Demografica da carta 2 é maior que a Densidade Demografica da carta 1\n");
    }  
}

void CompararQtdPontosTuristicos(){
    printf("Comparação de Qtd Pontos Turísticos:\n");
    printf("Carta 1 - %s: %i\n", pais, qtdPontosTur);
    printf("Carta 2 - %s: %i\n", pais2, qtdPontosTur2);

    if(qtdPontosTur > qtdPontosTur2){
        printf("Qtd Pontos Turísticos da carta 1 é maior que da carta 2.\n");
    } else{
        printf("Qtd Pontos Turísticos da carta 2 é maior que a Qtd Pontos Turísticos da carta 1\n");
    }   
}

void CompararSuperPoder(){
    printf("Comparação de Super Poder:\n");
    printf("Carta 1 - %s: %.2f\n", pais, superPod);
    printf("Carta 2 - %s: %.2f\n", pais2, superPod2);    

    if(superPod > superPod2){
        printf("Super Poder da carta 1 é maior que da carta 2.\n");
    } else{
        printf("Super Poder da carta 2 é maior que a Super Poder da carta 1\n");
    }
}

void ExitMenu(){
    system("cls");
    printf("Obrigado por utilizar o Super Trunfo!\n");
}

void ExibirMenu(){
    system("cls");
    printf("Bem vindo ao Super Trunfo!\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comparar População\n");
    printf("2 - Comparar PIB\n");
    printf("3 - Comparar PIB per Capita\n");
    printf("4 - Comparar Area\n");
    printf("5 - Comparar Densidade Populacional\n");
    printf("6 - Comparar Pontos Turísticos\n");
    printf("7 - Comparar Super Poder\n");    
    printf("8 - Sair\n");

    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            CompararEExibirPopulacao();
            break;
        case 2:
            CompararPib();
        break;
        case 3:
            CompararPibPerCapita();
        break;
        case 4:
            CompararArea();
        break;
        case 5:
            CompararDensidadeDemografica();
            break;
        case 6:
            CompararQtdPontosTuristicos();
        break;
        case 7:
            CompararSuperPoder();
            break;
        case 8:
            ExitMenu();
            break;
    }
}

//Método main com a chamada para os demais métodos
int main() {

   ColetarDados();
   ExibirMenu();

    return 0;
}