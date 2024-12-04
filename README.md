# Trabalho feito para a disciplina de Análise e Estruturas de Dados 2

## Gerenciador de Subconjuntos e Ordenações

Este projeto é uma implementação de operações sobre conjuntos disjuntos e ordenação de subconjuntos utilizando diferentes algoritmos de ordenação. O programa lê dados de um arquivo de entrada e oferece um menu interativo para o usuário realizar diversas operações, como união de conjuntos, busca de representantes e ordenação de subconjuntos.

---

## Funcionalidades

1. **Ler subconjuntos a partir de um arquivo de entrada**:
   - O programa aceita um arquivo de entrada com o número de elementos, o número de subconjuntos e os elementos de cada subconjunto.

2. **Operações sobre conjuntos disjuntos**:
   - União de subconjuntos (`union_sets`).
   - Busca do representante de um elemento (`find`).

3. **Ordenação de subconjuntos**:
   - Algoritmos disponíveis:
     - Bubble Sort
     - Merge Sort
     - Insertion Sort
     - Quick Sort

4. **Menu interativo**:
   - Exibe os subconjuntos atuais.
   - Permite realizar operações como união, busca e ordenação.

---

## Estrutura do Arquivo de Entrada

O arquivo de entrada deve seguir o seguinte formato:
1. Número total de elementos (`n`).
2. Número de subconjuntos (`k`).
3. Cada subconjunto começa com o número de elementos no subconjunto, seguido pelos elementos.

### Exemplo de arquivo (`entrada.txt`):

```
6
3
3 1 2 3
2 4 5
1 6
```

Este exemplo descreve:
- Total de 6 elementos.
- 3 subconjuntos:
  - Subconjunto 1: {1, 2, 3}
  - Subconjunto 2: {4, 5}
  - Subconjunto 3: {6}

---

## Como Executar

### Pré-requisitos
- Compilador C (por exemplo, `gcc`).

### Passos
1. Clone o repositório:
   ```bash
   git clone https://github.com/seuusuario/seurepositorio.git
   cd seurepositorio
   ```
2. Compile o código:
   ```bash
   gcc -o programa main.c
   ```
3. Execute o programa:
   ```bash
   ./programa
   ```
4. Insira as opções do menu para realizar as operações.

---

## Menu de Operações

O programa apresenta as seguintes opções no menu:

1. **Mostrar subconjuntos**: Exibe todos os subconjuntos atuais.
2. **Unir dois subconjuntos**: Permite unir os subconjuntos contendo dois elementos escolhidos.
3. **Buscar representante de um elemento**: Mostra o representante de um elemento no conjunto disjunto.
4. **Ordenar um subconjunto (Bubble Sort)**: Ordena os elementos de um subconjunto usando Bubble Sort.
5. **Ordenar um subconjunto (Merge Sort)**: Ordena os elementos de um subconjunto usando Merge Sort.
6. **Ordenar um subconjunto (Insertion Sort)**: Ordena os elementos de um subconjunto usando Insertion Sort.
7. **Ordenar um subconjunto (Quick Sort)**: Ordena os elementos de um subconjunto usando Quick Sort.
8. **Sair**: Encerra o programa.

---

## Estrutura do Código

### Principais Funções

- `readFile`: Lê os dados do arquivo de entrada.
- `initDisjointSets`: Inicializa os conjuntos disjuntos.
- `find`: Retorna o representante de um conjunto.
- `union_sets`: Une dois subconjuntos.
- `printSubsets`: Exibe os subconjuntos.
- Algoritmos de ordenação:
  - `bubbleSort`
  - `mergeSort`
  - `insertionSort`
  - `quickSort`

---

## Contribuindo

1. Faça um fork do projeto.
2. Crie uma branch para a sua feature/bugfix:
   ```bash
   git checkout -b minha-feature
   ```
3. Commit suas alterações:
   ```bash
   git commit -m "Descrição da minha feature"
   ```
4. Faça um push para a branch:
   ```bash
   git push origin minha-feature
   ```
5. Abra um Pull Request.

---

## Contato

Para dúvidas ou sugestões, entre em contato através do (pedrorafaelpereiradeoliveira@gmail.com).
