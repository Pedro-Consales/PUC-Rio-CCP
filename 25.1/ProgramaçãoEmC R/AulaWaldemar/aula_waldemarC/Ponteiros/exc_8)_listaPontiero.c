#include <stdio.h>

void printAlreadyCounted(int arr[], int size) {
  printf("alreadyCounted = [");
  for (int k = 0; k < size; k++) {
    printf("%d", arr[k]);
    if (k < size - 1)
      printf(", ");
  }
  printf("]\n");
}

int main() {
  int size = 8;
  float numbers[] = {-1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7};
  int alreadyCounted[8] = {0};

  printf("Estado inicial:\n");
  printAlreadyCounted(alreadyCounted, size);

  for (int i = 0; i < size; i++) {
    printf("\n--- i = %d (valor = %.1f) ---\n", i, numbers[i]);

    if (alreadyCounted[i]) {
      printf("[PULANDO] O número %.1f (posição %d) já foi contado.\n",
             numbers[i], i);
      printAlreadyCounted(alreadyCounted, size);
      continue;
    }

    int count = 1;
    for (int j = i + 1; j < size; j++) {
      printf("Comparando com j = %d (valor = %.1f): ", j, numbers[j]);
      if (numbers[j] == numbers[i]) {
        count++;
        alreadyCounted[j] = 1;
        printf("IGUAL! → Marcando j = %d como contado.\n", j);
        printAlreadyCounted(alreadyCounted, size);
      } else {
        printf("diferente.\n");
      }
    }

    printf("→ %.1f aparece %d vezes\n", numbers[i], count);
    printAlreadyCounted(alreadyCounted, size);
  }

  return 0;
}