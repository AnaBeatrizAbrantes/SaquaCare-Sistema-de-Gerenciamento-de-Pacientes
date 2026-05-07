<center>
<img width="367" height="137" alt="image" src="https://github.com/user-attachments/assets/39610908-26bc-4e08-b73a-60126a27859a" />
</center>

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
