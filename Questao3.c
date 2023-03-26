#include <libxml/parser.h> // necessário instalar a biblioteca libxml2
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // abrir o arquivo XML contendo os dados do faturamento
  xmlDocPtr doc;
  doc = xmlReadFile("faturamento.xml", NULL, 0);

  if (doc == NULL) {
    printf("Erro ao abrir o arquivo XML.\n");
    return 1;
  }

  // extrair do XML os valores contendo o faturamento diário
  xmlNodePtr root = xmlDocGetRootElement(doc);
  xmlNodePtr faturamento = xmlFirstElementChild(root);
  int n = xmlChildElementCount(faturamento);

  // armazenar os valores do faturamento diário em um vetor em C
  float *faturamento_c = (float *)malloc(n * sizeof(float));

  xmlNodePtr dia = xmlFirstElementChild(faturamento);
  int i = 0;

  while (dia != NULL) {
    faturamento_c[i] = atoi(xmlNodeGetContent(dia));
    dia = xmlNextElementSibling(dia);
    i++;
  }

  // encontrar o menor valor de faturamento
  float menor_faturamento = faturamento_c[0];

  for (int i = 1; i < n; i++) {
    if (faturamento_c[i] < menor_faturamento) {
      menor_faturamento = faturamento_c[i];
    }
  }
  // encontrar o maior valor de faturamento
  float maior_faturamento = faturamento_c[0];
  for (int i = 0; i <= n; i++) {
    if (faturamento_c[i] > maior_faturamento) {
      maior_faturamento = faturamento_c[i];
    }
  }

  // Calculando a média do faturamento mensal
  float soma_faturamento = 0;
  for (int i = 1; i <= n; i++) {
    soma_faturamento = soma_faturamento + faturamento_c[i];
  }


  //calculando os dias que o faturamento foi maior que a média
  float media_mensal = soma_faturamento / n;

  int dias_acima_da_media = 0;
  for (int i = 0; i < n; i++) {
    if (faturamento_c[i] > media_mensal) {
      dias_acima_da_media++;
    }
  }

  printf("\nO menor valor de faturamento diário foi de R$ %.2f\n",
         menor_faturamento);
  printf("\nO maior valor de faturamento diário foi de R$ %.2f\n",
         maior_faturamento);
  printf("\nO número de dias em que o faturamento diário foi superior à média "
         "mensal foi de %d\n",
         dias_acima_da_media);

  // liberar a memória alocada
  free(faturamento_c);
  xmlFreeDoc(doc);

  return 0;
}