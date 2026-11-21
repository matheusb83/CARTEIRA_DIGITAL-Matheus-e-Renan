
#ifndef MEU_BANCO_H
#define MEU_BANCO_H

#define MAX_CLIENTES 100
#define MAX_HIST 5
#define TAM_HIST 80

#define CORRENTE 1
#define SALARIO  2
#define POUPANCA 3

typedef struct {
    int   existe;
    float saldo;
    char  numero[12];
} Conta;

typedef struct {
    char  nome[35];
    int   numero;
    Conta contas[4];

    char  historico[MAX_HIST][TAM_HIST];
    int   qtd_hist;

    int   fez_emprestimo;
    int   titulo;
    int   premiado;
    float premio;
} Cliente;

void limparTela(void);
void pausar(void);
void addHistorico(Cliente *c, const char *msg);

void abrirBanco(Cliente banco[], int *t);
void fecharBanco(Cliente banco[], int *t);
void alertaNegativo(Cliente banco[], int t);
void movimentar(Cliente banco[], int t);
void realizarEmprestimo(Cliente banco[], int t);
void comprarTitulo(Cliente banco[], int t);
void consultarHistorico(Cliente banco[], int t);
void efetuarSorteio(Cliente banco[], int t);

#endif
