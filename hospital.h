// criei o .h

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