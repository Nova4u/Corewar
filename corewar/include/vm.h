/*
** vm.h for vm
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 10:36:14 2016 marc brout
** Last update Tue Mar 22 18:48:23 2016 marc brout
*/

#ifndef VM_H_
# define VM_H_

# include "asm.h"
# include "op.h"

/*
** ERROR OUTPUTS
*/

# define OVERLAP "Overlap detected.\n"
# define MALLOC_ERROR "Can't perform malloc\n"
# define NOCOREWAR " is not a corewar executable\n"
# define CORRUPT " is corrupted\n"
# define MISS_COR "Missing corewar executable\n"

char		g_endian;

typedef	struct		s_pc
{
  int			carry;
  int			reg[16];
  int			cycle;
  struct s_pc		*next;
}			t_pc;

typedef struct		s_champion
{
  const char		*path;
  char			valid;
  int			alive;
  int			order;
  int			fd;
  unsigned int		size;
  char			name[PROG_NAME_LENGTH + 1];
  t_pc			*pc;
}			t_champion;

typedef struct		s_data
{
  int			nblive;
  int			dump;
  int			i;
  t_champion		*champ[4];
  char			*ram;
  char			*ramv;
}			t_data;

typedef struct		s_pars
{
  char			*arg;
  int			(*chk_arg)(char **, int *, t_data *);
  struct s_pars		*next;
}			t_pars;

/*
** dump.c
*/

void			dump(char *ram);
void			octect_to_base(char octect,
				       char hexa[2],
				       char *base);

/*
** load_file.c
*/

void			my_bzero(void *ptr, int size, char val);
char			endianness();
int			swap_integer(int nb);
int			check_header(int fd, t_header *head);
void			copy(char *src, char *dst);
int			init_champs(t_data *data);
int			load_champion(t_champion *champion,
				      const char *champion_file);

/*
** vm.c
*/

int			my_put_file_str(const char *file,
					const char *str,
					int err);
int			my_put_file_noaccess(const char *file,
					     int err);
int			my_put_error(const char *str,
				     int err);
int			my_put_usage(char **av,
				     int err);

/*
** misc.c
*/

void			my_putnbr_tofd(int nb, int fd);
int			my_strlencst(const char *str);
int			my_mystrcmpcst(const char *str1,
				       const char *str2);
int			my_revstrncmpcst(const char *str1,
					 const char *str2,
					 int n);
char			*my_strcatcst(const char *str1,
				      const char *str2);
char			*get_name(const char *str1,
				  const char *str2);
/*
** set_vm_memory.c
*/

int			init_ram(t_data *data);
int			copy_champion_to_ram(t_champion *champion,
					     char *ram);
int			size_champs(t_champion *champ[4],
				    int first,
				    int *nb);
int			place_all_champions(t_data *data);

/*
** check arguments function: func_arg.c
*/

int			check_arg(char **, int *, t_pars *, t_data *);
int			chk_adress(char **, int *, t_data *);
int			chk_dump(char **, int *, t_data *);
int			chk_prog_nbr(char **, int *, t_data *);

/*
** list arguments : list_arg.c
*/

int			add_adress_in_list(t_pars *);
int			add_dump_in_list(t_pars *);
int			add_prog_nbr_in_list(t_pars *);
t_pars			*init_list();

/*
** annex_function.
*/

int			my_getnbr_prog(char *);
int			my_strcmp(char *, char *);

/*
** list champion: order_champ.c
*/

void			order_champ(t_data *);
void			swap_champ(t_data *, int);


/*
** begin parsing arguments: pars.c
*/

int			my_put_int_error(int, int);
int			pars_arg(char **, t_pars  *, t_data *);

/*
** order my champ: prog_number.c
*/

int			check_prog_number_value(t_data *);
void			put_order_in_champ(t_data *, int);
void			recheck_prog_number(t_data *);

/*
** run_one_cycle.c
*/

void			copy_registres(t_pc *src,
				       t_pc *dst);
int			add_pc(t_pc *pc, int pos,
			       int cycle);
int			run_one_cycle(t_data *data);

/*
** launch_match.c
*/

int			count_players_alive(t_champion *champ[4]);
void			set_players(t_champion *champ[4]);
void			check_winner(t_champion *champ[4]);
int			launch_match(t_data *data);

#endif /* !VM_H_ */