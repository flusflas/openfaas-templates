#include <stdio.h>
#include <stdlib.h>

size_t input(char **buffer) {
  size_t bufsize = 32;
  size_t characters;

  *buffer = (char *)malloc(bufsize * sizeof(char));
  if (*buffer == NULL) return -1;

  characters = getline(buffer, &bufsize, stdin);
  return (int)characters < 0 ? 0 : characters;
}

int main() {
  char *buffer;
  size_t characters = input(&buffer);
  
  if ((int)characters == -1) {
    perror("Unable to allocate buffer");
    return 1;
  }

  printf("%zd characters received: '%s'", characters, buffer);
  return 0;
}
