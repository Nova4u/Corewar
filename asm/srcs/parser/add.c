/*
** add.c for add in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:27:31 2016 bougon_p
** Last update Tue Mar 22 20:16:23 2016 bougon_p
*/

#include "asm.h"

int	w_add(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;

  istr = 0x04;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_coding_byte(fd, info) == -1)
    return (1);
  if ((w_reg(fd, info->arg_1)) == 1)
    return (1);
  if ((w_reg(fd, info->arg_2)) == 1)
    return (1);
  if ((w_reg(fd, info->arg_3)) == 1)
    return (1);
  instruc->addr_wrt += 5;
  return (0);
}
