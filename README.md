<img width="800" height="563" alt="image" src="https://github.com/user-attachments/assets/e5eabdf2-0219-4684-abf7-b5f0af460014" />


# Hospital Simulado - Gerenciamento de Pacientes

Implemetação desenvolvida em C para simular o fluxo hospitalar utilizando estruturas de dados lineares.

## Regras
- **Emergência (Pilha):** Atendimento prioritário para gravidade 4 e 5.
- **Consultas (Fila):** Ordem de chegada para atendimentos agendados.
- **Exames (Fila Circular):** Capacidade máxima de 8 pacientes (remove o antigo se encher).

## Como Compilar e Rodar
1. Tenha um compilador C (como GCC) instalado.
2. No terminal, use:
   ```bash
   gcc main.c -o hospital
   ./hospital
