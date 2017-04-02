/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 16:21:18 2017 Antonin Rapini
*/

#include "operation.h"

void	op_ld(t_vm *vm, t_process *process, t_param params[4])
{
  int	value;
  int	reg;

  value = parse_value(params[0], vm, process, MOD | REG);
  reg = parse_value(params[1], vm, process, NO_MOD);
  if (reg > 16 || reg <= 0)
    {
      process->carry = 0;
      return ;
    }
  process->registers[reg - 1] = value;
  process->carry = 1;
}
