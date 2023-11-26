#include <stdio.h>
#include <string.h>
#include <locale.h>


void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char *arr[], int n, int *trocas, int *comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                (*trocas)++;
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void mostrarVetor(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void gerarArquivoTexto(char *arr[], int n, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        printf("Certifique-se de que o caminho e as permissões estão corretos.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (fprintf(arquivo, "%s\n", arr[i]) < 0) {
            perror("Erro ao escrever no arquivo");
            fclose(arquivo);
            return;
        }
    }

    fclose(arquivo);
}

float calcularMediana(char *arr[], int n) {
    if (n % 2 == 0) {
        // Se o número de elementos é par, calcular a média dos dois elementos do meio.
        return (strlen(arr[n / 2 - 1]) + strlen(arr[n / 2])) / 2.0;
    } else {
        // Se o número de elementos é ímpar, retornar o elemento do meio.
        return strlen(arr[n / 2]);
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int n = sizeof(arr) / sizeof(arr[0]);
    int trocas = 0, comparacoes = 0;

    bubbleSort(arr, n, &trocas, &comparacoes);

    printf("Vetor Ordenado: ");
    mostrarVetor(arr, n);
    printf("Numero de Trocas: %d\n", trocas);
    printf("Numero de Comparacoes: %d\n", comparacoes);

    gerarArquivoTexto(arr, n, "saida.txt");

    float mediana = calcularMediana(arr, n);
    printf("Mediana: %.2f\n", mediana);

    return 0;
}