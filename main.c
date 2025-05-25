#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lexerf.h"
#include "parserf.h"
#include "codegeneratorf.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Error: correct syntax: %s <filename.unn> <output_filename>\n", argv[0]);
    exit(1);
  }
  char *output_filename = malloc(sizeof(char) * 16);
  sprintf(output_filename, "%s.asm", argv[2]);

  FILE *file;
  file = fopen(argv[1], "r");

  if (!file)
  {
    printf("ERROR: File not found\n");
    exit(1);
  }
  Token *tokens = lexer(file);

  Node *test = parser(tokens);

  // Save the parse tree to a file
  char *parse_tree_filename = malloc(sizeof(char) * 32);
  sprintf(parse_tree_filename, "%s_parse_tree.txt", argv[2]);
  save_parse_tree(test, parse_tree_filename);
  free(parse_tree_filename);

  generate_code(test, "generated.asm");
  FILE *assembly_file = fopen("generated.asm", "r");
  if (!assembly_file)
  {
    printf("ERRROR");
    exit(1);
  }
  char *nasm = malloc(sizeof(char) * 64);
  char *gcc = malloc(sizeof(char) * 64);
  sprintf(nasm, "nasm -f elf64 generated.asm -o generated.o", argv[2], argv[2]);
  sprintf(gcc, "gcc generated.o -o %s -lc -no-pie", argv[2], argv[2]);
  system(nasm);
  system(gcc);
  printf("FINISHED\n");
}