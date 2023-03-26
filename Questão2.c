#include <stdio.h>
int fib() {
  int fib1 = 0, fib2 = 1, soma, n = 1000, num;
  scanf("%d", &num);
  for (int i = 3; i <= n; i++) {
    if (num == soma) {
      printf("O numero pertence a sequencia de Fibonacci");
      break;

    } else {

      soma = fib1 + fib2;
      fib1 = fib2;
      fib2 = soma;
    }
  }
  printf("O numero nao pertence a sequencia de Fibonacci");
  return fib2;
}

int main(void) { fib(); }