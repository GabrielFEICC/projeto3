#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>


//a main funciona para fazer rodar o programa no terminal e mostrar os resultados
//fizemos todas as funcoes no proj.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal no arquivo
int main() {
    int cod;
    char arquivo[100] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarTarefas(&lt, arquivo);
    lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d", &opcao);

        if (opcao==0){

        }else if(opcao==1){
            cadastrarTarefa(&lt);
        }else if(opcao==2){
            deletarTarefas(&lt);
        }else if(opcao==3){
            listarTarefas(lt);
        }else{
            printf("opcao invalida\n");
        }
        printf("%d\n", opcao);
    } while (opcao != 0);

    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0){
        printf("problema ao salvar arquivo\n");
    }

    printf("fim\n");
    return 0;
}
