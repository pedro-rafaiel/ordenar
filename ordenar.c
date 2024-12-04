#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Declarações globais
int parent[MAX];  // Vetor para os representantes dos conjuntos
int size[MAX];    // Vetor para armazenar o tamanho de cada conjunto
int partitions[MAX][MAX]; // Vetor para armazenar os subconjuntos

// Função de leitura do arquivo de entrada
void readFile(const char *filename, int arr[MAX], int *n, int partitions[MAX][MAX], int *k) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fscanf(file, "%d", n); // Lê o valor de n
    fscanf(file, "%d", k); // Lê o valor de k
    
    // Lê os subconjuntos do arquivo
    for (int i = 0; i < *k; i++) {
        int subset_size;
        fscanf(file, "%d", &subset_size);
        for (int j = 0; j < subset_size; j++) {
            fscanf(file, "%d", &partitions[i][j]);
        }
        partitions[i][subset_size] = -1; // Marca o final do subconjunto
    }

    fclose(file);
}

// Função para inicializar os conjuntos disjuntos
void initDisjointSets(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Função para buscar o representante de um conjunto
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Compressão de caminho
    }
    return parent[x];
}

// Função para unir dois subconjuntos
void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // União por tamanho
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
}

// Função para imprimir os subconjuntos
void printSubsets(int partitions[MAX][MAX], int k) {
    printf("Subconjuntos atuais:\n");
    for (int i = 0; i < k; i++) {
        printf("Subconjunto %d: ", i);
        for (int j = 0; partitions[i][j] != -1; j++) {
            printf("%d ", partitions[i][j]);
        }
        printf("\n");
    }
}

// Função para ordenar com Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Função para ordenar com Merge Sort
void mergeSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        int i = inicio, j = meio + 1, k = 0;
        int temp[fim - inicio + 1];
        while (i <= meio && j <= fim) {
            if (vetor[i] < vetor[j]) {
                temp[k++] = vetor[i++];
            } else {
                temp[k++] = vetor[j++];
            }
        }
        while (i <= meio) temp[k++] = vetor[i++];
        while (j <= fim) temp[k++] = vetor[j++];
        for (i = 0; i < k; i++) vetor[inicio + i] = temp[i];
    }
}

// Função para ordenar com Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para particionar o vetor no Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Função para ordenar com Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função do menu interativo
void menu(int arr[MAX], int n, int partitions[MAX][MAX], int k) {
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Mostrar subconjuntos\n");
        printf("2. Unir dois subconjuntos\n");
        printf("3. Buscar representante de um elemento\n");
        printf("4. Ordenar um subconjunto (Bubble Sort)\n");
        printf("5. Ordenar um subconjunto (Merge Sort)\n");
        printf("6. Ordenar um subconjunto (Insertion Sort)\n");
        printf("7. Ordenar um subconjunto (Quick Sort)\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printSubsets(partitions, k);
                break;
            case 2: {
                int x, y;
                printf("Digite dois elementos para unir seus subconjuntos: ");
                scanf("%d %d", &x, &y);
                union_sets(x - 1, y - 1);  // União de dois subconjuntos
                break;
            }
            case 3: {
                int x;
                printf("Digite o elemento para encontrar seu representante: ");
                scanf("%d", &x);
                printf("Representante de %d: %d\n", x, find(x - 1));
                break;
            }
            case 4: {
                int subsetIndex;
                printf("Digite o índice do subconjunto para ordenar (Bubble Sort): ");
                scanf("%d", &subsetIndex);
                int subsetSize = 0;
                // Conta o tamanho do subconjunto
                while (partitions[subsetIndex][subsetSize] != -1) {
                    subsetSize++;
                }
                // Ordena o subconjunto usando Bubble Sort
                bubbleSort(partitions[subsetIndex], subsetSize);
                printf("Subconjunto %d ordenado com Bubble Sort.\n", subsetIndex);
                printSubsets(partitions, k);  // Imprime os subconjuntos ordenados
                break;
            }
            case 5: {
                int subsetIndex;
                printf("Digite o índice do subconjunto para ordenar (Merge Sort): ");
                scanf("%d", &subsetIndex);
                int subsetSize = 0;
                // Conta o tamanho do subconjunto
                while (partitions[subsetIndex][subsetSize] != -1) {
                    subsetSize++;
                }
                // Ordena o subconjunto usando Merge Sort
                mergeSort(partitions[subsetIndex], 0, subsetSize - 1);
                printf("Subconjunto %d ordenado com Merge Sort.\n", subsetIndex);
                printSubsets(partitions, k);  // Imprime os subconjuntos ordenados
                break;
            }
            case 6: {
                int subsetIndex;
                printf("Digite o índice do subconjunto para ordenar (Insertion Sort): ");
                scanf("%d", &subsetIndex);
                int subsetSize = 0;
                // Conta o tamanho do subconjunto
                while (partitions[subsetIndex][subsetSize] != -1) {
                    subsetSize++;
                }
                // Ordena o subconjunto usando Insertion Sort
                insertionSort(partitions[subsetIndex], subsetSize);
                printf("Subconjunto %d ordenado com Insertion Sort.\n", subsetIndex);
                printSubsets(partitions, k);  // Imprime os subconjuntos ordenados
                break;
            }
            case 7: {
                int subsetIndex;
                printf("Digite o índice do subconjunto para ordenar (Quick Sort): ");
                scanf("%d", &subsetIndex);
                int subsetSize = 0;
                // Conta o tamanho do subconjunto
                while (partitions[subsetIndex][subsetSize] != -1) {
                    subsetSize++;
                }
                // Ordena o subconjunto usando Quick Sort
                quickSort(partitions[subsetIndex], 0, subsetSize - 1);
                printf("Subconjunto %d ordenado com Quick Sort.\n", subsetIndex);
                printSubsets(partitions, k);  // Imprime os subconjuntos ordenados
                break;
            }
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 8);
}

int main() {
    int n, k;
    int arr[MAX];
    int partitions[MAX][MAX];
    
    // Leitura do arquivo
    readFile("entrada.txt", arr, &n, partitions, &k);
    
    // Inicializando os conjuntos disjuntos
    initDisjointSets(n);
    
    // Menu de operações
    menu(arr, n, partitions, k);
    
    return 0;
}
