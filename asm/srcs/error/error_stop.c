/*
** error_stop.c for error_stop in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/error
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 14:10:16 2016
** Last update Fri Mar 11 14:14:53 2016 
*/

#include "asm.h"

void	malloc_fail()
{
  write(2, "Can't perform malloc\n", 21);
}