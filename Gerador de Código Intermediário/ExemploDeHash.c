#include <stdio.h>
#include <string.h>

#define SIZE 211 //n�mero primo para melhorar a distribui��o
			     // em uma tabela de hashing com at� 211
			     //registros

#define SHIFT 4

int hash(char * key)
{
  int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  {
    temp = ((temp << SHIFT) + key[i]) % SIZE;
	// O perador << faz deslocamentos de bits para a esquerda
	// no valor de temp (4 bits).
	// Este recurso est� sendo usado para evitar sobrecarga
	// em temp.
    ++i;
  }
  return temp;
}

int main()
{
  char nome[5] = "amain";
  int e = 0;

  e = hash(nome);
  printf("\nEntrada 1: %d\n", e);
  return 0;

}