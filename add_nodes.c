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
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
 * add_dnodeint_end - function that adds a new node at
 * the end of a dlistint_t list.
 * @head: Arg 1.
 * @n: arg 2.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t	*node, *hd = *head;

	node = malloc(sizeof(stack_t));
	if (!node || !head)
	{
		free(node);
		return (NULL);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	if (!*head)
		*head = node;
	else
	{
		while (hd->next)
			hd = hd->next;
		node->prev = hd;
		hd->next = node;
	}
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
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp->f = f;
	tmp->opcode = _strdup(o);
	add_node_inst(&Global.opcodes, tmp);
}
