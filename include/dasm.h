/*
** dasm.h for corware in /home/brout_m/RENDU/CPE/CPE_2015_corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 10:51:24 2016 marc brout
** Last update Mon Mar 14 19:08:28 2016 marc brout
*/

#ifndef DASM_H_
# define DASM_H_

# define USAGE "USAGE : ./dasm file.cor\n"
# define UNUSED __attribute__((__unused__))

typedef struct		s_dasm
{
  int			(*func[16])(int);
}			t_dasm;

#endif /* !DASH_H_ */
