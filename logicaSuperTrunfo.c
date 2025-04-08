#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função criada para calcular a densidade populacional
float calcular_densidade_p(unsigned long int populacao, float area){
    return populacao / area;
    
}

// Função para calcular o Pib per capita
float calcular_pib_per_capita(float pib, unsigned long int populacao){
    return (pib *1000000000) / populacao; // realizo a multiplicação do PIB que está em bilhões, para convertê-lo em reais
}

//Função para calcular o Super Poder das cartas
float calcular_superpoder(unsigned long int populacao,  float area, float pib, float pontos_t, float pibpercapita, float densidadep){
    return populacao + area + (pib * 1000000000) + pontos_t + pibpercapita + (1 / densidadep);
}

int main() {
    // Aqui eu declaro as variaveis da primeira carta
    char estado; 
    char codigo[5]; 
    char cidade[25];
    unsigned long int populacao = 0;
    float area = 0;
    float pib = 0;
    int pontos_t = 0;
    float densidadep, densidadep2, pibpercapita, pibpercapita2;

    // Aqui eu declaro as variaveis da segunda carta
    char estado2; 
    char codigo2[5]; 
    char cidade2[25];
    unsigned long int populacao2 = 0;
    float area2 = 0;
    float pib2 = 0;
    int pontos_t2 = 0;

    printf("Digite um numero de 1 a 4 para escolher o modo de jogo:\n");
    printf("1 - JOGAR\n");
    printf("2 - COMPARAR\n");
    printf("3 - SAIR\n");
    int modo_jogo;
    scanf("%d", &modo_jogo);

    switch (modo_jogo) {
        case 1:
            // Aqui eu declaro as variaveis da primeira carta
            printf("Digite um estado com uma letra de A-H:\n");
            scanf(" %c", &estado);

            printf("Digite um codigo para a sua cidade com a letra do estado seguida de um número de 01-04:\n");
            scanf("%4s", codigo);
            getchar(); // Estava com alguns erros, o programa pulava algumas linhas no terminal, então dei uma pesquisada e colocar alguns getchar(), ajudaram a não ocorrer mais
                       // para limpar o buffer de entrada do ENTER
            printf("Digite uma cidade:\n");
            fgets(cidade, sizeof(cidade), stdin);  // Precisei colocar este fgets para ler cidades com espaços entre o nome
            cidade[strcspn(cidade, "\n")] = 0;     

            printf("Digite a população da sua cidade:\n");
            scanf("%lu", &populacao);

            printf("Digite a area em km² da sua cidade:\n");
            scanf("%f", &area);

            printf("Digite o pib da sua cidade:\n");
            scanf("%f", &pib);

            printf("Digite o numero de pontos turísticos da sua cidade:\n");
            scanf("%d", &pontos_t);

            // Aqui eu declaro as variaveis da segunda carta
            printf("Digite outro estado com uma letra de A-H(Não repita a letra do primeiro Estado):\n");
            scanf(" %c", &estado2);

            getchar(); // Estava com alguns erros, o programa pulava algumas linhas no terminal, então dei uma pesquisada e colocar alguns getchar(), ajudaram a não ocorrer mais
                       // para limpar o buffer de entrada do ENTER
            printf("Digite um codigo para a sua outra cidade com a letra do estado seguida de um número de 01-04:\n");  
            scanf("%s", codigo2);
            getchar(); // Estava com alguns erros, o programa pulava algumas linhas no terminal, então dei uma pesquisada e colocar alguns getchar(), ajudaram a não ocorrer mais
                       // para limpar o buffer de entrada do ENTER
            printf("Digite a sua outra cidade:\n");
            fgets(cidade2, sizeof(cidade2), stdin);
            cidade2[strcspn(cidade2, "\n")] = 0; // Precisei colocar este fgets para ler cidades com espaços entre o nome


            printf("Digite a população da sua outra cidade:\n");
            scanf("%lu", &populacao2);

            printf("Digite a area em km² da sua outra cidade:\n");
            scanf("%f", &area2);

            printf("Digite o pib da sua outra cidade:\n");
            scanf("%f", &pib2);

            printf("Digite o numero de pontos turísticos da sua outra cidade:\n");
            scanf("%d", &pontos_t2);

            getchar(); // Estava com alguns erros, o programa pulava algumas linhas no terminal, então dei uma pesquisada e colocar alguns getchar(), ajudaram a não ocorrer mais
                       // para limpar o buffer de entrada do ENTER

            //Calculos de todos atributos pedidos das cartas
            densidadep = calcular_densidade_p(populacao, area);
            densidadep2 = calcular_densidade_p(populacao2, area2);
            pibpercapita = calcular_pib_per_capita(pib, populacao);
            pibpercapita2 = calcular_pib_per_capita(pib2, populacao2);
            float superpoder = calcular_superpoder(populacao, area, pib, pontos_t, pibpercapita, densidadep);
            float superpoder2 = calcular_superpoder(populacao2, area2, pib2, pontos_t2, pibpercapita2, densidadep2);


            // Aqui eu comparo os superpoderes das cartas
            if (superpoder > superpoder2) {
                printf("A carta 1 é mais forte que a carta 2\n");
            } else if (superpoder < superpoder2) {
                printf("A carta 2 é mais forte que a carta 1\n");
            } else {
                printf("As cartas são iguais\n");
            }
            
            // Aqui eu exibo no terminal a primeira carta
            printf("Estado: %c\n", estado);
            printf("Codigo: %s\n", codigo);
            printf("Cidade: %s\n", cidade);
            printf("População: %lu\n", populacao);
            printf("Area: %.2f\n", area);
            printf("Pib: %.2f\n", pib);
            printf("Pontos Turisticos: %d\n", pontos_t);
            printf("Densidade populacional: %.2f\n", densidadep);
            printf("Pib per capita: %.2f\n", pibpercapita);
            printf("Super Poder: %.2f\n", superpoder);

            // Aqui eu exibo no terminal a segunda carta
            printf("Estado: %c\n", estado2);
            printf("Codigo: %s\n", codigo2);
            printf("Cidade: %s\n", cidade2);
            printf("População: %lu\n", populacao2);
            printf("Area: %.2f\n", area2);
            printf("Pib: %.2f\n", pib2);
            printf("Pontos Turisticos: %d\n", pontos_t2);
            printf("Densidade populacional: %.2f\n", densidadep2);
            printf("Pib per capita: %.2f\n", pibpercapita2);
            printf("Super Poder: %.2f\n", superpoder2);

            // Aqui eu comparo os valores das cartas, e exibo no terminal o resultado da comparação
            printf("Comparação de Cartas:\n");
            printf("População: Carta %d venceu (%d)\n", 1 + (populacao < populacao2), (populacao > populacao2) * 1);
            printf("Área: Carta %d venceu (%d)\n", 1 + (area < area2), (area > area2) * 1);
            printf("PIB: Carta %d venceu (%d)\n", 1 + (pib < pib2), (pib > pib2) * 1);
            printf("Pontos Turísticos: Carta %d venceu (%d)\n", 1 + (pontos_t < pontos_t2), (pontos_t > pontos_t2) * 1);
            printf("Densidade Populacional: Carta %d venceu (%d)\n", 1 + (densidadep > densidadep2), (densidadep < densidadep2) * 1); 
            printf("PIB per Capita: Carta %d venceu (%d)\n", 1 + (pibpercapita < pibpercapita2), (pibpercapita > pibpercapita2) * 1);
            printf("Super Poder: Carta %d venceu (%d)\n", 1 + (superpoder < superpoder2), (superpoder > superpoder2) * 1);
            break;
        break;
    case 2: 
        printf("Escolha dois atributos para comparar");

        // Ensure densidadep, densidadep2, pibpercapita, and pibpercapita2 are calculated for comparison
        densidadep = calcular_densidade_p(populacao, area);
        densidadep2 = calcular_densidade_p(populacao2, area2);
        pibpercapita = calcular_pib_per_capita(pib, populacao);
        pibpercapita2 = calcular_pib_per_capita(pib2, populacao2);
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional\n");
        printf("6 - PIB per Capita\n");
        printf("7 - Super Poder\n");
        int atributo1, atributo2;
        scanf("%d %d", &atributo1, &atributo2);
        
        // Aqui eu comparo os atributos escolhidos pelo usuário
        switch (atributo1) {
            case 1:
                if (populacao > populacao2) {
                    printf("A carta 1 venceu na comparação de população.\n");
                } else if (populacao < populacao2) {
                    printf("A carta 2 venceu na comparação de população.\n");
                } else {
                    printf("As cartas têm a mesma população.\n");
                }
                break;
            case 2:
                if (area > area2) {
                    printf("A carta 1 venceu na comparação de área.\n");
                } else if (area < area2) {
                    printf("A carta 2 venceu na comparação de área.\n");
                } else {
                    printf("As cartas têm a mesma área.\n");
                }
                break;
            case 3:
                if (pib > pib2) {
                    printf("A carta 1 venceu na comparação de PIB.\n");
                } else if (pib < pib2) {
                    printf("A carta 2 venceu na comparação de PIB.\n");
                } else {
                    printf("As cartas têm o mesmo PIB.\n");
                }
                break;
            case 4:
                if (pontos_t > pontos_t2) {
                    printf("A carta 1 venceu na comparação de pontos turísticos.\n");
                } else if (pontos_t < pontos_t2) {
                    printf("A carta 2 venceu na comparação de pontos turísticos.\n");
                } else {
                    printf("As cartas têm o mesmo número de pontos turísticos.\n");
                }
                break;
            case 5:
                if (densidadep > densidadep2) {
                    printf("A carta 1 venceu na comparação de densidade populacional.\n");
                } else if (densidadep < densidadep2) {
                    printf("A carta 2 venceu na comparação de densidade populacional.\n");
                } else {
                    printf("As cartas têm a mesma densidade populacional.\n");
                }
                break;
            case 6:
                if (pibpercapita > pibpercapita2) {
                    printf("A carta 1 venceu na comparação de PIB per capita.\n");
                } else if (pibpercapita < pibpercapita2) {
                    printf("A carta 2 venceu na comparação de PIB per capita.\n");
                } else
                    printf("As cartas têm o mesmo PIB per capita.\n");
            }
            default:
                printf("Opção inválida.\n");
                break;
        }
    }