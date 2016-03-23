/*
** add.c for add in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:51:39 2016 benjamin duhieu
** Last update Tue Mar 22 19:00:07 2016 benjamin duhieu
*/

#include "vm.h"

int		add(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;
  unsigned	third;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  third = (data->ram[i->reg[0]] << 2) & (char)3;
  if (first != 1 || second != 1 || third != 1)
    return (1);
  else if ((data->ram[i->reg[0] + 1] < 1 || data->ram[i->reg[0] + 1] > 16) ||
	   (data->ram[i->reg[0] + 2] < 1 || data->ram[i->reg[0] + 2] > 16) ||
	   (data->ram[i->reg[0] + 3] < 1 || data->ram[i->reg[0] + 3] > 16))
    return (1);
  i->reg[0] += 4;
}
