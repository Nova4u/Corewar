/*
** check_verif_args.c for check_verif_args in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 13 11:45:19 2016
** Last update Mon Mar 21 12:03:57 2016 Marel la plus belle <3
*/

#include "asm.h"

int	verif_one_arg(t_instruc *instruc, t_list_instruc *elem,
		      char *file, int i)
{
  if (i == 0 || i == 14 || i == 11 || i == 8)
    {
      if (check_direct_arg(instruc, elem, file, 1) == -1)
	return (-1);
    }
  else if (i == 15)
    if (check_registre_arg(elem, file, 1) == -1)
      return (-1);
  if (check_end_instruc(file, my_strlen(elem->info->arg_1)) == -1)
    return (-1);
  return (0);
}

int	verif_two_args(t_instruc *instruc, t_list_instruc *elem,
		       char *file, int i)
{
  char	*new;

  if (i == 1 || i == 12)
    {
      if ((check_direct_arg(instruc, elem, file, 1) == -1
	   && check_indirect_arg(instruc, elem, file, 1) == -1)
	  || ((new = epure_file_instruc(file,
					my_strlen(elem->info->arg_1))) == NULL)
	  || check_registre_arg(elem, new, 2) == -1)
	return (-1);
    }
  else if (i == 2)
    if (check_registre_arg(elem, file, 1) == -1
	|| (new = epure_file_instruc(file,
				     my_strlen(elem->info->arg_1))) == NULL
	|| (check_indirect_arg(instruc, elem, new, 2) == -1
	    && check_registre_arg(elem, new, 2) == -1))
      return (-1);
  if (check_end_instruc(new, my_strlen(elem->info->arg_2)) == -1)
    return (-1);
  return (0);
}

int	verif_three_args(t_instruc *instruc, t_list_instruc *elem,
			 char *file, int i)
{
  t_three_args  *fptrtab;
  int           j;

  j = -1;
  if ((fptrtab = init_tab_three_args()) == NULL)
    return (-1);
  while (++j < MAX_THREE_ARGS)
    if (i == fptrtab[j].ins)
      {
	if (fptrtab[j].ft_three(instruc, elem, file) == -1)
	  return (-1);
	return (0);
      }
  return (0);
}

int	how_many_args(t_instruc *instruc, t_list_instruc *elem,
		      char *new, int i)
{
  if (op_tab[i].nbr_args == 3)
    {
      if (verif_three_args(instruc, elem, new, i) == -1)
	return (-1);
    }
  else if (op_tab[i].nbr_args == 2)
    {
      if (verif_two_args(instruc, elem, new, i) == -1)
	return (-1);
    }
  else
    if (verif_one_arg(instruc, elem, new, i) == -1)
      return (-1);
  return (0);
}

int	check_stock_good_args(t_instruc *instruc, t_list_instruc *elem,
			      char *file, int i)
{
  char	*new;
  int	j;
  int	l;

  j = my_strlen(elem->info->name);
  if ((new = malloc(sizeof(char) * (my_strlen(file) - j + 1))) == NULL)
    return (malloc_fail(), -1);
  l = 0;
  while (file[j] != '\0')
    new[l++] = file[j++];
  new[l] = '\0';
  if ((new = epure_file_instruc(new, 0)) == NULL)
    return (-1);
  if (how_many_args(instruc, elem, new, i)== -1)
    return (-1);
  return (0);
}
