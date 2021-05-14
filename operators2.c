#include "monty.h"
#include <ctype.h>

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		error_handler("empty_stack", Linenumber);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(tmp);
	var.stack_len--;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		error_handler("pchar_error", Linenumber);
	}
	if (!isascii(tmp->n))
	{
		error_handler("isnot_assci", Linenumber);
	}

	printf("%c\n", tmp->n);
}

/**
 * sub - subtracts the top element from the second top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		error_handler("error_sub", Linenumber);
	}
	tmp = *stack;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	pop(stack, Linenumber);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int Linenumber)
{

	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		error_handler("error_pint", Linenumber);
	}
	printf("%d\n", tmp->n);
}

/**
 * mod - the division of the second top element by the top element.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		error_handler("error_mod", Linenumber);
	}
	if (tmp->n == 0)
	{
		error_handler("error_div_by_0", Linenumber);
	}
	tmp = *stack;
	sub = tmp->next->n % tmp->n;
	tmp->next->n = sub;
	pop(stack, Linenumber);
}
