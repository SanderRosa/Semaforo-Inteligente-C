#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   // Para sleep() e simulação de tempo
// Enumeração dos estados do semáforo
typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} EstadoSemaforo;

// Estrutura da via
typedef struct {
    char nome[50];
    int carros;
    EstadoSemaforo estado;
    int tempo_verde;
} Via;
// Converte enum em string
const char* estadoToString(EstadoSemaforo estado) {
    switch (estado) {
        case VERDE: return "VERDE";
        case AMARELO: return "AMARELO";
        case VERMELHO: return "VERMELHO";
        default: return "DESCONHECIDO";
    }
}
// Define o tempo verde baseado na quantidade de carros
void atualizarTempoVerde(Via *via) {
    if (via->carros > 20)
        via->tempo_verde = 30;
    else if (via->carros > 10)
        via->tempo_verde = 20;
    else
        via->tempo_verde = 10;
}
// Simula o ciclo de semáforo de uma via, com tempo global
void simularCicloSemaforo(Via *vias, int num_vias, FILE *arquivo) {
    int tempo_global = 0;
    for (int i = 0; i < num_vias; i++) {
        // Todas as vias menos a atual ficam no VERMELHO
        for (int j = 0; j < num_vias; j++) {
            vias[j].estado = (j == i) ? VERDE : VERMELHO;
            if (j != i) {
                fprintf(arquivo, "[%ds] Via: %s | Estado: %s\n",
                        tempo_global, vias[j].nome, estadoToString(vias[j].estado));
                printf("[%ds] Via: %s | Estado: %s\n",
                        tempo_global, vias[j].nome, estadoToString(vias[j].estado));
            }
        }
        // Atualiza tempo verde para a via atual
        atualizarTempoVerde(&vias[i]);
        // Via atual em VERDE
        fprintf(arquivo, "[%ds] Via: %s | Estado: VERDE | Tempo Verde: %ds\n",
                tempo_global, vias[i].nome, vias[i].tempo_verde);
        printf("[%ds] Via: %s | Estado: VERDE | Tempo Verde: %ds\n",
                tempo_global, vias[i].nome, vias[i].tempo_verde);
        tempo_global += vias[i].tempo_verde;
        sleep(1); // Simulação (substituir por sleep(vias[i].tempo_verde) em tempo real)
        // Estado AMARELO
        vias[i].estado = AMARELO;
        fprintf(arquivo, "[%ds] Via: %s | Estado: AMARELO (3s)\n",
                tempo_global, vias[i].nome);
        printf("[%ds] Via: %s | Estado: AMARELO (3s)\n",
                tempo_global, vias[i].nome);

        tempo_global += 3;
        sleep(1); // Simulação (use sleep(3) em tempo real)
    }
}
// Função principal
int main() {
    int num_vias;
    printf("Quantas vias deseja simular? ");
    scanf("%d", &num_vias);
    getchar();  // Limpa o buffer

    // Alocação dinâmica
    Via *vias = (Via *)malloc(num_vias * sizeof(Via));
    if (vias == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    // Entrada de dados
    for (int i = 0; i < num_vias; i++) {
        printf("\nNome da via %d: ", i + 1);
        fgets(vias[i].nome, sizeof(vias[i].nome), stdin);
        vias[i].nome[strcspn(vias[i].nome, "\n")] = '\0';
        printf("Quantidade de carros detectados: ");
        scanf("%d", &vias[i].carros);
        getchar();  // Limpa o buffer
    }
    // Abre arquivo
    FILE *arquivo = fopen("historico_semaforo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(vias);
        return 1;
    }
    printf("\nIniciando simulacao do ciclo dos semaforos...\n\n");
    fprintf(arquivo, "=== Historico de Simulacao dos Semaforos ===\n\n");
    // Simula os semáforos com tempo global e sem coincidência de verde
    simularCicloSemaforo(vias, num_vias, arquivo);
    fclose(arquivo);
    free(vias);
    printf("\nSimulacao finalizada. Resultados salvos em 'historico_semaforo.txt'.\n");
    return 0;
}
