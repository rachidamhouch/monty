#include "monty.h"

void init(char *name)
{
	Global.fd = open(name, O_RDONLY);
	if (Global.fd < 0)
	{
		dprintf(2, "Error: can't open file %s\n", name);
        exit(EXIT_FAILURE);
	}
	Global.stack = NULL;
	Global.opcodes = NULL;
	Global.inst = NULL;
	Global.ln = 1;
	add_new_inst("pall", pall);
	add_new_inst("push", push);
	add_new_inst("pint", pint);
	add_new_inst("nop", nop);
	add_new_inst("pop", pop);
	add_new_inst("swap", swap);
	add_new_inst("add", add);
	add_new_inst("sub", sub);
	add_new_inst("div", divv);
	add_new_inst("mul", mul);
	add_new_inst("mod", mod);
	add_new_inst("pchar", pchar);
	add_new_inst("pstr", pstr);
}
