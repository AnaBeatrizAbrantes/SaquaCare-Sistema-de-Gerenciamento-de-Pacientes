#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX 10
#define MAX_CIRCULAR 8

typedef struct {
    char nome[50];
    int idade;
    int gravidade;
    int tipo; // 1-Emergência, 2-Consulta, 3-Exame
} Paciente;

// Estruturas
typedef struct {
    Paciente itens[MAX];
    int topo;
} Pilha;

typedef struct {
    Paciente itens[MAX];
    int inicio, fim;
} Fila;

typedef struct {
    Paciente itens[MAX_CIRCULAR];
    int inicio, fim, total;
} FilaCircular;

// Protótipos
void initPilha(Pilha *p);
void push(Pilha *p, Paciente pac);
Paciente pop(Pilha *p);

void initFila(Fila *f);
void enqueue(Fila *f, Paciente pac);
Paciente dequeue(Fila *f);

void initCircular(FilaCircular *f);
void enqueueCircular(FilaCircular *f, Paciente pac);
Paciente dequeueCircular(FilaCircular *f);

#endif