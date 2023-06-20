#include "monty.h"

/**
 * add_node_stack - ...
 * @head: Arg 1.
 * @n: arg 2.
 * Return: ...
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
 * add_node_inst - ...
 * @head: Arg 1.
 * @inst: arg 2.
 * Return: ...
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

/**
 * add_new_inst - ...
 * @o: Arg 1.
 * @f: arg 2.
 */
void add_new_inst(char *o, void (*f)(stack_t **s, unsigned int l))
{
	instruction_t *tmp;

	tmp = malloc(sizeof(instruction_t));
	tmp->f = f;
	tmp->opcode = strdup(o);
	add_node_inst(&Global.opcodes, tmp);
}
