#include <stdio.h>
#include <string.h>

int main() {
    int i;

    // ---------- REQUISITO 3: VETORES para armazenar os dados dos 3 jogadores ----------
    char nomes[3][50];
    int abates[3];
    int assistencias[3];
    int mortes[3];

    int totalAbates = 0;
    float mediaAbates;

    int maiorAssistencias;
    int indiceMVP;

    char nomeBusca[50];
    int indiceEncontrado = -1;

    printf("===== CADASTRO DO TIME - TORNEIO DE VALORANT =====\n\n");

    // ---------- REQUISITO 2: ESTRUTURA DE REPETICAO (for) - cadastro dos 3 jogadores ----------
    for (i = 0; i < 3; i++) {
        printf("--- Jogador %d ---\n", i + 1);

        printf("Nome de usuario: ");
        scanf(" %[^\n]", nomes[i]);

        printf("Abates: ");
        scanf("%d", &abates[i]);

        printf("Assistencias: ");
        scanf("%d", &assistencias[i]);

        printf("Mortes: ");
        scanf("%d", &mortes[i]);

        printf("\n");
    }

    // ---------- REQUISITO 5: PROCESSAMENTO - soma e media de abates ----------
    for (i = 0; i < 3; i++) {
        totalAbates = totalAbates + abates[i];
    }
    mediaAbates = (float) totalAbates / 3;

    // ---------- REQUISITO 5: PROCESSAMENTO - encontrar o MVP (maior valor de assistencias) ----------
    maiorAssistencias = assistencias[0];
    indiceMVP = 0;
    for (i = 1; i < 3; i++) {
        if (assistencias[i] > maiorAssistencias) {
            maiorAssistencias = assistencias[i];
            indiceMVP = i;
        }
    }

    // ---------- REQUISITO 6: RESULTADOS ORGANIZADOS para o usuario ----------
    printf("\n========== RESULTADOS DA PARTIDA ==========\n\n");

    for (i = 0; i < 3; i++) {
        printf("Jogador: %s\n", nomes[i]);
        printf("Abates: %d | Assistencias: %d | Mortes: %d\n",
               abates[i], assistencias[i], mortes[i]);

        // ---------- REQUISITO 1: ESTRUTURA DE DECISAO (if / else if / else) ----------
        // Classifica o desempenho do jogador pelo KD (abates / mortes)
        if (mortes[i] == 0) {
            printf("Desempenho: Excelente\n\n");
        } else if ((float) abates[i] / mortes[i] >= 1.5) {
            printf("Desempenho: Excelente\n\n");
        } else if ((float) abates[i] / mortes[i] >= 1.0) {
            printf("Desempenho: Bom\n\n");
        } else {
            printf("Desempenho: Precisa melhorar\n\n");
        }
    }

    printf("Total de abates da equipe: %d\n", totalAbates);
    printf("Media de abates da equipe: %.2f\n", mediaAbates);
    printf("MVP da partida: %s (%d assistencias)\n", nomes[indiceMVP], maiorAssistencias);

    // ---------- REQUISITO 4: BUSCA EM VETOR - procurar jogador pelo nome ----------
    printf("\nDigite o nome de um jogador para ver as estatisticas dele: ");
    scanf(" %[^\n]", nomeBusca);

    for (i = 0; i < 3; i++) {
        if (strcmp(nomes[i], nomeBusca) == 0) {
            indiceEncontrado = i;
        }
    }

    // ---------- REQUISITO 6: RESULTADOS ORGANIZADOS - exibicao da busca ----------
    if (indiceEncontrado != -1) {
        printf("\n--- Jogador encontrado ---\n");
        printf("Nome: %s\n", nomes[indiceEncontrado]);
        printf("Abates: %d\n", abates[indiceEncontrado]);
        printf("Assistencias: %d\n", assistencias[indiceEncontrado]);
        printf("Mortes: %d\n", mortes[indiceEncontrado]);
    } else {
        printf("\nJogador nao encontrado.\n");
    }

    printf("\n===== FIM DO PROGRAMA =====\n");
    return 0;
    
}
