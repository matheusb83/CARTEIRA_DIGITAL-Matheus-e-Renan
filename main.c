
#include <stdio.h>
#include "meu_banco.h"

int main(void) {
    Cliente banco[MAX_CLIENTES];

    int t = 0;
    int aberto = 0;
    int op;

    do {
        limparTela();

        if (aberto) {
            alertaNegativo(banco, t);
        }

        printf("===== MENU PRINCIPAL =====\n");
        printf("1 - abrir o banco\n");
        printf("2 - consultar historico\n");
        printf("3 - efetuar sorteio\n");
        printf("4 - depositar\n");
        printf("5 - pedir emprestimo\n");
        printf("6 - comprar titulo\n");
        printf("7 - fechar o banco\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &op);
        limparTela();

        if (op == 1) {
            if (aberto) {
                printf("O banco ja esta aberto.\n");
            } else {
                abrirBanco(banco, &t);
                if (t > 0) {
                    aberto = 1;
                }
            }

        } else if (op >= 2 && op <= 7) {

            if (!aberto) {
                printf("abra o banco primeiro (opcao 1).\n");

            } else if (op == 2) {
                consultarHistorico(banco, t);

            } else if (op == 3) {
                efetuarSorteio(banco, t);

            } else if (op == 4) {
                movimentar(banco, t);

            } else if (op == 5) {
                realizarEmprestimo(banco, t);

            } else if (op == 6) {
                comprarTitulo(banco, t);

            } else if (op == 7) {
                fecharBanco(banco, &t);
                aberto = 0;
            }

        } else if (op != 0) {
            printf("Opcao invalida.\n");
        }

        if (op != 0) {
            pausar();
        }

    } while (op != 0);

    printf("Encerrando\n");

    pausar();

    return 0;
}
