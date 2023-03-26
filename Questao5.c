#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  printf("Digite uma string: ");
  fgets(string, 100, stdin);
  int tamanho = strlen(string) - 1; // desconta o caractere '\n'
  char invertida[tamanho];
  for (int i = 0; i < tamanho; i++) {
    invertida[i] = string[tamanho - 1 - i];
  }
  invertida[tamanho] = '\0';
  printf("String invertida: %s\n", invertida);
  return 0;
}
