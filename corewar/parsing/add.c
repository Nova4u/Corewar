/*
** add.c for add in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:51:39 2016 benjamin duhieu
** Last update Sat Mar 26 13:25:12 2016 marc brout
*/

#include "my.h"
#include "vm.h"

int		add_registres(t_data *data, t_pc *i)
{
  int		val;

  val = i->reg[(int)data->ram[MM(i->reg[0] + 2)]] +
    i->reg[(int)data->ram[MM(i->reg[0] + 3)]];
  i->reg[(int)data->ram[MM(i->reg[0] + 4)]] = val;
  /* my_printf("i->reg[%d] = %d\n", (int)data->ram[MM(i->reg[0] + 4)], */
  /* 	    i->reg[(int)data->ram[MM(i->reg[0] + 4)]]); */
  return (val);
}

int		add(t_data *data, t_pc *i)
{
  t_inst	inst;

  if (can_i_run(i, 10))
    return (0);
  inst.fi = data->ram[MM(i->reg[0] + 1)] >> 6 & (char)3;
  inst.sd = data->ram[MM(i->reg[0] + 1)] >> 4 & (char)3;
  inst.th = data->ram[MM(i->reg[0] + 1)] >> 2 & (char)3;
  if (inst.fi != 1 || inst.sd != 1 || inst.th != 1)
    return (0);
  if ((data->ram[MM(i->reg[0] + 2)] < 1 ||
       data->ram[MM(i->reg[0] + 2)] > 16) ||
      (data->ram[MM(i->reg[0] + 3)] < 1 ||
       data->ram[MM(i->reg[0] + 3)] > 16) ||
      (data->ram[MM(i->reg[0] + 4)] < 1 ||
       data->ram[MM(i->reg[0] + 4)] > 16))
    return (0);
  if (add_registres(data, i))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + 5);
  return (0);
}
