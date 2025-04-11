#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade; // densidade demográfica
};

// Função para exibir os atributos
void exibirAtributosDisponiveis(int escolhido) {
    printf("Escolha um atributo:\n");
    if (escolhido != 1) printf("1. População\n");
    if (escolhido != 2) printf("2. Área\n");
    if (escolhido != 3) printf("3. PIB\n");
    if (escolhido != 4) printf("4. Densidade Demográfica\n");
}

// Função para pegar o valor de um atributo
int obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

// Função para nome do atributo
char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 213000000, 8516000, 1444730000000, 25};
    struct Carta carta2 = {"Alemanha", 83100000, 357000, 4200000000000, 232};

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    do {
        exibirAtributosDisponiveis(0);
        printf("Escolha o primeiro atributo (1-4): ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 4);

    // Escolha do segundo atributo
    do {
        exibirAtributosDisponiveis(atributo1);
        printf("Escolha o segundo atributo diferente do primeiro: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Obtenção dos valores
    int valor1_attr1 = obterValor(carta1, atributo1);
    int valor2_attr1 = obterValor(carta2, atributo1);
    int valor1_attr2 = obterValor(carta1, atributo2);
    int valor2_attr2 = obterValor(carta2, atributo2);

    // Comparações por atributo
    int pontos1 = 0, pontos2 = 0;

    // Atributo 1
    if (atributo1 == 4) { // densidade: menor é melhor
        pontos1 += valor1_attr1 < valor2_attr1 ? 1 : 0;
        pontos2 += valor2_attr1 < valor1_attr1 ? 1 : 0;
    } else {
        pontos1 += valor1_attr1 > valor2_attr1 ? 1 : 0;
        pontos2 += valor2_attr1 > valor1_attr1 ? 1 : 0;
    }

    // Atributo 2
    if (atributo2 == 4) {
        pontos1 += valor1_attr2 < valor2_attr2 ? 1 : 0;
        pontos2 += valor2_attr2 < valor1_attr2 ? 1 : 0;
    } else {
        pontos1 += valor1_attr2 > valor2_attr2 ? 1 : 0;
        pontos2 += valor2_attr2 > valor1_attr2 ? 1 : 0;
    }

    // Soma total dos atributos
    int soma1 = valor1_attr1 + valor1_attr2;
    int soma2 = valor2_attr1 + valor2_attr2;

    // Exibição dos resultados
    printf("\nComparação entre %s e %s:\n", carta1.nome, carta2.nome);
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("  %s: %d\n  %s: %d\n", carta1.nome, valor1_attr1, carta2.nome, valor2_attr1);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("  %s: %d\n  %s: %d\n", carta1.nome, valor1_attr2, carta2.nome, valor2_attr2);

    printf("Soma dos atributos:\n");
    printf("  %s: %d\n  %s: %d\n", carta1.nome, soma1, carta2.nome, soma2);

    // Resultado final
    printf("Resultado da rodada: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
