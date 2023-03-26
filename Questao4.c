#include <stdio.h>

int main() {
    float valores[] = {67836.43, 36678.66, 29229.88, 27165.48, 19849.53}; // valores mensais para cada estado
    int num_estados = sizeof(valores) / sizeof(valores[0]); // número total de estados
    float total = 0.0; // valor total mensal da distribuidora

    // calcular o valor total mensal da distribuidora
    for (int i = 0; i < num_estados; i++) {
        total += valores[i];
    }

    // calcular o percentual de representação de cada estado
  printf("SP: %.2f%%\n", (valores[0] / total) * 100);
  printf("RJ: %.2f%%\n", (valores[1] / total) * 100);
  printf("MG: %.2f%%\n", (valores[2] / total) * 100);
  printf("ES: %.2f%%\n", (valores[3] / total) * 100);
  printf("Outros: %.2f%%\n", (valores[4] / total) * 100);

    return 0;
}
