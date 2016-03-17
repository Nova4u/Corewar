/*
** check_if_label_exist.c for check_if_label_exist in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 15 19:47:32 2016
** Last update Tue Mar 15 19:59:25 2016 
*/

#include "asm.h"

char	*copy_lab(char *str)
{
  int	i;
  int	j;
  char	*new;

  i = 2;
  j = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) - 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[j] = str[i];
      j++;
      i++;
    }
  new[j] = '\0';
  return (new);
}

int		check_in_list(t_instruc *instruc, char *lab)
{
  t_list_instruc	*tmp;
  int			i;

  i = 0;
  tmp = instruc->root->next;
  while (i < instruc->lenght - 1)
    {
      if (tmp->info->label != NULL)
	{
	  if ((lab = copy_lab(lab)) == NULL)
	    return (-1);
	  if (my_strncmp(tmp->info->label, lab, my_strlen(lab)) == 0)
	    return (0);
	}
      tmp = tmp->next;
      i++;
    }
  return (-1);
}

int		check_if_label_exist(t_instruc *instruc)
{
  t_list_label	*tmp;
  int		i;

  i = 0;
  tmp = instruc->lab->next;
  while (i < instruc->lenght_label - 1)
    {
      if (check_in_list(instruc, tmp->name) == -1)
	return (-1);
      tmp = tmp->next;
      i++;
    }
  return (0);
}