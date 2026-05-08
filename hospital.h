// criei o .h
#include <stdio.h>
#ifndef HOSPITAL_H // se não definido
#define HOSPITAL_H //agora define >> evita ficar repedindo o arquivo

#define MAX 10
#define MAX_CIRCULAR 8 // aqui seria constantes

typedef struct {
    char nome[50];
    int idade;
    int gravidade;
    int tipo; // 1-Emergência, 2-Consulta, 3-Exame
} Paciente;


//ideias das possiveis funcões sumário
// falando que essas funções existem em algum lugar

void cadastrar_paciente();
void atender_emergencia();
void atender_consulta();
void atender_exame();
void mostrar_setor();
void transferir_paciente();
void relatorios();
void sair();

#endif
