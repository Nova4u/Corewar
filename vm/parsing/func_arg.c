/*
** func_arg.c for func in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 13:29:10 2016 benjamin duhieu
** Last update Mon Mar 21 22:46:11 2016 benjamin duhieu
*/

#include "pars.h"

int	chk_dump(char **av, int *i, t_data *data)
{
  int	res;

  if (!(my_strcmp(av[*i + 1], "-a")) || !(my_strcmp(av[*i + 1], "-n")))
    {
      data->dump = -1;
      *i += 1;
      return (0);
    }
  if (!(res = my_getnbr_prog(av[*i + 1])) || res > CYCLE_TO_DIE)
    return (1);
  data->dump = res;
  *i += 2;
  return (0);
}

int	chk_adress(char **av, int *i, t_data *data)
{
  int	add;

  if (!(add = my_getnbr_prog(av[*i + 1])) || add > MEM_SIZE)
    return (1);
  data->champ[data->i]->pc->pc = -1;
  *i += 2;
  return (0);
}

int	chk_prog_nbr(char **av, int *i, t_data *data)
{
  int	nbr;
  int	chk;
  char	*str_nbr;

  if (!(nbr = my_getnbr_prog(av[*i + 1])))
    return (1);
  chk = -1;
  while (chk < 4 && nbr != data->champ[++chk]->order);
  if (chk == 4)
    data->champ[data->i]->order = nbr;
  else
    return (my_put_error(str_nbr, 2));
  i += 2;
  return (0);
}

int		check_arg(char **av, int *i, t_pars *arg, t_data *dat)
{
  t_pars	*elem;
  int		chk;

  elem = arg->next;
  while (elem != NULL)
    {
      if (!(my_strcmp(av[*i], elem->arg, dat)))
	{
	  if ((chk = elem->arg(av, i)) == 1)
	    return (1);
	  else if (chk == 2)
	    return (3):
	  return (0);
	}
      elem = elem->next;
    }
  return (2);
}
