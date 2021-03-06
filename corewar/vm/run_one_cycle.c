/*
** run_one_cycle.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 17:00:44 2016 marc brout
** Last update Sun Mar 27 12:44:06 2016 marc brout
*/

#include <stdlib.h>
#include "vm.h"
#include "op.h"

int		test_instruction(t_data *data, t_pc *pc)
{
  char		instruction;

  instruction = data->ram[pc->reg[0]];
  if (instruction <= 0 || instruction > VM_AFF)
    {
      if (data->inst[0](data, pc))
	return (1);
      return (0);
    }
  if (data->inst[(int)instruction](data, pc))
    return (1);
  return (0);
}

void		reset_cur(t_data *data)
{
  if (data->champ[0]->valid >= 0)
    data->champ[0]->cur = data->champ[0]->pc->next;
  if (data->champ[1]->valid >= 0)
    data->champ[1]->cur = data->champ[1]->pc->next;
  if (data->champ[2]->valid >= 0)
    data->champ[2]->cur = data->champ[2]->pc->next;
  if (data->champ[3]->valid >= 0)
    data->champ[3]->cur = data->champ[3]->pc->next;
}

int		launch_one_champ_pc(t_data *data, t_pc **cur,
				    UNUSED int pc, char *go)
{
  t_pc		*tmp;

  tmp = *cur;
  if (tmp)
    {
      if (test_instruction(data, tmp))
	return (1);
      if (tmp->next)
	{
	  *cur = tmp->next;
	  *go = 1;
	}
      else
	*go = 0;
    }
  return (0);
}

int		run_one_cycle(t_data *data)
{
  char		go;
  int		test;

  test = -1;
  go = 1;
  while (go)
    {
      test++;
      if (data->champ[0]->valid >= 0)
	if (launch_one_champ_pc(data, &data->champ[0]->cur, test, &go))
	  return (1);
      if (data->champ[1]->valid >= 0)
	if (launch_one_champ_pc(data, &data->champ[1]->cur, test, &go))
	  return (1);
      if (data->champ[2]->valid >= 0)
	if (launch_one_champ_pc(data, &data->champ[2]->cur, test, &go))
	  return (1);
      if (data->champ[3]->valid >= 0)
	if (launch_one_champ_pc(data, &data->champ[3]->cur, test, &go))
	  return (1);
    }
  reset_cur(data);
  return (0);
}

int	ready_to_cycle(t_data *data)
{
  int	i;
  int	nb_turn;
  int	go;

  i = 0;
  go = 1;
  nb_turn = CYCLE_TO_DIE;
  while (go && nb_turn >= 0)
    {
      if (run_one_cycle(data))
	return (1);
      if (data->dump > 0)
	if (!(data->dump -= 1))
	  return (dump(data->ram), 0);
      if (data->nblive >= NBR_LIVE && !(data->nblive = 0))
	if ((nb_turn -= CYCLE_DELTA) <= 0)
	  break ;
      if (i >= nb_turn && !(i = 0))
	{
	  go = count_players_alive(data->champ);
	  set_players(data->champ);
	}
      i += 1;
    }
  return (0);
}
