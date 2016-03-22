/*
** pars.c for pars in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 12:58:17 2016 benjamin duhieu
** Last update Tue Mar 22 00:05:06 2016 benjamin duhieu
*/

#include <unistd.h>
#include "vm.h"

int		my_put_int_error(int nbr, int err)
{
  write(2, "prog number ", 12);
  my_putnbr_tofd(nbr, 2);
  write(2, " already used\n", 14);
  return (err);
}

int		pars_arg(char **av, t_pars *arg, t_data *data)
{
  int	i;
  int	chk;

  i = 0;
  while (av[i])
    {
      if ((chk = check_arg(av, &i, arg, data)) == 1)
	return (my_put_usage(av, 1));
      else if (chk == 2)
	{
	  if (load_champion(&data->champ[data->i], av[i]))
	    return (my_put_file_str(data->champ[data->i]->path, 2));
	  data->champ[data->i]->valid = 1;
	  i += 1;
	  data->i += 1;
	}
      else if (chk == 3)
	return (1);
    }
  recheck_prog_number(data);
  order_champ(data);
  return (0);
}

int		main(int argc, char **argv)
{
  t_pars	*arg;
  t_data	data;

  if (argc < 2 || !argv)
    return (my_put_usage(argv, 2));
  data.i = 0;
  g_endian = endianness();
  if (!(arg = init_list()) || init_ram(&data))
    return (1);
  if (pars_arg(argv, arg, &data) || place_all_champions(&data))
    return (1);
  return (0);
}
