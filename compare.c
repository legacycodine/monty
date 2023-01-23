#include "monty.h"

/**
  * compare - a function that holds the function pointer struct and
  * compares the string from getline to the appropriate opcode
  * then runs the appropriate function
  * @token: the tokenized string from textfile
  * @stack: a pointer to the head of the stack_t
  * @line_number: the line number of the opcode
  * Return: void
  */

void compare(char *token, stack_t **stack, unsigned int line_number)
{
	int i, foundMatch = 0;

	instruction_t func_list[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"mul", mul},
		{"sub", sub},
		{"mod", mod},
		{"div", divide},
		{NULL, NULL}
	};
	for (i = 0; func_list[i].opcode != NULL; i++)

		if (strcmp(token, func_list[i].opcode) == 0)
		{
			func_list[i].f(stack, line_number);
			foundMatch = 1;
		}
	if (!foundMatch)
		errorHandler(8, line_number);
}
