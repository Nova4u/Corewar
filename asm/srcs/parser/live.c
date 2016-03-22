/*
** live.c for LIVE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:25:05 2016 bougon_p
** Last update Tue Mar 22 21:53:44 2016 bougon_p
*/

#include "asm.h"

int	w_live(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;
  int	arg;

  istr = 0x01;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  arg = my_getnbr(&info->arg_1[1]);
  arg = convert_littleend_to_bigend_int(arg);
  if (write(fd, &arg, sizeof(arg)) == -1)
    return (1);
  instruc->addr_wrt += 5;
  return (0);
}
