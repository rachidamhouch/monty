#include "monty.h"

/**
 * find - ...
 */
void find(void)
{
	listOfinst_t *tmp = Global.opcodes;
	char *n;

	if (!Global.inst[0])
	{
		free_inst(Global.inst);
		return;
	}
	while (tmp)
	{
		if (Global.inst[0][0] == '#')
		{
			free_inst(Global.inst);
			return;
		}
		if (!strncmp(tmp->inst->opcode, Global.inst[0], strlen(Global.inst[0]) + 1))
		{
			tmp->inst->f(&Global.stack, Global.ln);
			free_inst(Global.inst);
			return;
		}
		tmp = tmp->next;
	}
	n = _itoa(Global.ln);
	print("L", 2, 0);
	print(n, 2, 0);
	print(": unknown instruction ", 2, 0);
	print(Global.inst[0], 2, 1);
	free(n);
	free(Global.line);
	free_inst(Global.inst);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * rm_new_line - ...
 * @ptr: Arg 1.
 * Return: ...
 */
char *rm_new_line(char *ptr)
{
	int len = 0, i = 0;
	char *new;

	if (!ptr)
		return (NULL);
	while (ptr[len] && ptr[len] != '\n')
		len++;
	new  = malloc(len + 1);
	while (ptr[i] && ptr[i] != '\n')
	{
		new[i] = ptr[i];
		i++;
	}
	new[i] = '\0';
	free(ptr);
	return (new);
}

/**
 * exic - ...
 */
void exic(void)
{
	char *line;

	line = rm_new_line(get_next_line(Global.fd));
	while (line)
	{
		Global.inst = split(line, " \t");
		Global.line = line;
		find();
		free(line);
		line = rm_new_line(get_next_line(Global.fd));
		Global.ln++;
	}
	free_all();
}
