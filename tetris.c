#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5

// struct que está representando cada peça
typedef struct {
    char tipo; // 'I', 'O', 'T', 'L'
    int id;  
} Peca;

// fila circular de peças
Peca fila[TAM_FILA];
int inicio = 0, fim = 0, cont = 0;
int contadorId = 0;

// gerar uma peça aleatória dentre as que estão aí
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.tipo = tipos[rand() % 4];
    p.id = contadorId++;
    return p;
}

// Adiciona peça ao final da fila (enqueue)
void enqueue(Peca p) {
    if (cont == TAM_FILA) return; // fila cheia
    fila[fim] = p;
    fim = (fim + 1) % TAM_FILA;
    cont++;
}

// Remove peça da frente da fila (dequeue)
Peca dequeue() {
    Peca p = fila[inicio];
    inicio = (inicio + 1) % TAM_FILA;
    cont--;
    return p;
}

// Mostra a fila atual
void mostrarFila() {
    printf("\nFila de peças:\n");
    for (int i = 0; i < cont; i++) {
        int idx = (inicio + i) % TAM_FILA;
        printf("[%c %d] ", fila[idx].tipo, fila[idx].id);
    }
    printf("\n");
}

// Inicializa fila com 5 peças
void inicializarFila() {
    for (int i = 0; i < TAM_FILA; i++) {
        enqueue(gerarPeca());
    }
}

int main() {
    srand(time(NULL));
    inicializarFila();

    int opcao;
    do {
        mostrarFila();
        printf("\nOpcoes:\n1 - Jogar peça\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Peca p = dequeue();
            printf("Peca jogada: [%c %d]\n", p.tipo, p.id);
            enqueue(gerarPeca()); // insere nova peça automaticamente
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    printf("Saindo...\n");
    return 0;
}
