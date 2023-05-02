#include <stdio.h>
#include <time.h>

void fillArrayRandom(int arr[], int n) {
  srand(time(NULL)); // inicializa o gerador de números aleatórios

  for (int i = 0; i < n; i++) {
    arr[i] =
        rand() % 100; // preenche o vetor com números aleatórios entre 0 e 99
  }
}

void insertionSort(int arr[], int n) {
  if (n <= 1) {
    return; // caso base: vetor com 0 ou 1 elementos já está ordenado
  }

  insertionSort(arr, n - 1); // ordena os primeiros n-1 elementos recursivamente

  int last = arr[n - 1]; // armazena o último elemento do vetor
  int j = n - 2;

  while (j >= 0 && arr[j] > last) {
    arr[j + 1] = arr[j]; // move os elementos maiores para a direita
    j--;
  }

  arr[j + 1] = last; // insere o último elemento na posição correta
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;

    // encontra o menor elemento restante no vetor
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // troca o menor elemento com o primeiro elemento não ordenado
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r) {
    // caso base: vetor tem tamanho 0 ou 1
    return;
  }

  // encontra o meio do vetor
  int m = l + (r - l) / 2;

  // ordena a metade esquerda do vetor recursivamente
  mergeSort(arr, l, m);

  // ordena a metade direita do vetor recursivamente
  mergeSort(arr, m + 1, r);

  // mescla as duas metades em ordem crescente
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  // copia os elementos para os subarrays L e R
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // mescla os subarrays em ordem crescente
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // copia os elementos restantes do subarray L, se houver
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // copia os elementos restantes do subarray R, se houver
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void heapSort(int arr[], int n) {
  // cria um heap máximo a partir do vetor
  for (int i = 1; i < n; i++) {
    int child = i;
    int parent = (child - 1) / 2;

    while (child > 0 && arr[child] > arr[parent]) {
      int temp = arr[child];
      arr[child] = arr[parent];
      arr[parent] = temp;

      child = parent;
      parent = (child - 1) / 2;
    }
  }

  // extrai o maior elemento do heap e o coloca no final do vetor
  for (int i = n - 1; i >= 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // reconstrói o heap máximo
    int parent = 0;
    int leftChild = 1;
    int rightChild = 2;

    while (leftChild < i) {
      int maxChild = leftChild;

      if (rightChild < i && arr[rightChild] > arr[leftChild]) {
        maxChild = rightChild;
      }

      if (arr[parent] >= arr[maxChild]) {
        break;
      }

      int temp = arr[parent];
      arr[parent] = arr[maxChild];
      arr[maxChild] = temp;

      parent = maxChild;
      leftChild = 2 * parent + 1;
      rightChild = 2 * parent + 2;
    }
  }
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
      if (arr[j] < pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    int pivotIndex = i + 1;

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
  }
}

int main() {
  int size;
  scanf("%d", &size);
  int arr[size];
  fillArrayRandom(arr, size);

  
  clock_t startIns = clock();
  insertionSort(arr, size);
  clock_t endIns = clock();

  
  clock_t startSelec = clock();
  selectionSort(arr, size);
  clock_t endSelec = clock();


  clock_t startMerge = clock();
  mergeSort(arr, 0, size - 1);
  clock_t endMerge = clock();


  clock_t startHeap = clock();
  heapSort(arr, size);
  clock_t endHeap = clock();


  clock_t startQuick = clock();
  quickSort(arr, 0, size - 1);
  clock_t endQuick = clock();

  double time_insertion = (((double)(endIns - startIns)) / CLOCKS_PER_SEC) * 1000; // calcula o tempo de execução em milissegundos
  
  double time_selection = (((double)(endSelec - startSelec)) / CLOCKS_PER_SEC) * 1000;
  
  double time_merge = (((double)(endMerge - startMerge)) / CLOCKS_PER_SEC) * 1000;
  
  double time_heap = (((double)(endHeap - startHeap)) / CLOCKS_PER_SEC) * 1000;
  
  double time_quick = (((double)(endQuick - startQuick)) / CLOCKS_PER_SEC) * 1000;

  printf("Tempo de execução em milisegundos para o tamanho do vetor [%d] \n { "
         "insertion: %lf\n selection: %lf\n marge: %lf \n heap: %lf \n quick: "
         "%lf \n }",
         size, time_insertion, time_selection, time_merge, time_heap,
         time_quick);

  return 0;
}
