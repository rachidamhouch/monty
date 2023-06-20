#include "monty.h"

/**
 * add_dnodeint - function that adds a new node
 * at the beginning of a dlistint_t list.
 * @head: Arg 1.
 * @n: arg 2.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_node_stack(stack_t **head, const int n)
{
	stack_t	*node, *hd = *head;

	node = malloc(sizeof(stack_t));
	if (!node || !head)
	{
		free(node);
		return (NULL);
	}
	node->n = n;
	node->next = hd;
	node->prev = NULL;
	if (hd)
		hd->prev = node;
	*head = node;
	return (node);
}

/**
 * add_node - function that adds a new node
 * at the beginning of a list_t list.
 * @head: Arg 1.
 * @str: arg 2.
 * Return: the address of the new element, or NULL if it failed.
 */
listOfinst_t	*add_node_inst(listOfinst_t **head, instruction_t *inst)
{
	listOfinst_t	*node;

	node = malloc(sizeof(listOfinst_t));
	if (!node || !head)
		return (NULL);
	node->inst = inst;
	node->next = *head;
	*head = node;
	return (node);
}

void add_new_inst(char *opcode, void (*f)(stack_t **stack, unsigned int line_number))
{
	instruction_t *tmp;

	tmp = malloc(sizeof(instruction_t));
	tmp->f = f;
	tmp->opcode = strdup(opcode);
	add_node_inst(&Global.opcodes, tmp);
}