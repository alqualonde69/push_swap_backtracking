/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:07:43 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 01:07:44 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

# define V	(1u << 0u)
# define C	(1u << 1u)
# define MVP	seq[j - 1] != '1' && seq[j] != '0' && seq[j] != '1'
# define MVP2	seq[j + 1] && seq[j + 1] != '0' && seq[j + 1] != '1'
# define MVP3	seq[j + 2] && seq[j + 2] != '0' && seq[j + 2] != '1'
# define MVP4	!seq[j + 3] || (seq[j + 3] && seq[j + 3] != '0')
# define ISS	(seq[i - 1] == '2' && seq[i] == '2')	/*1*/
# define ISS1	(seq[i - 1] == '2' && seq[i] == '5')		/*2*/
# define ISS2	(seq[i - 1] == '2' && seq[i] == '6')	/*1*/
# define ISS3	(seq[i - 1] == '3' && seq[i] == '4')			/*?*/
# define ISS4	(seq[i - 1] == '3' && seq[i] == '7')	/*1*/
# define ISS5	(seq[i - 1] == '3' && seq[i] == ':')				/*!*/
# define ISS6	(seq[i - 1] == '4' && seq[i] == '3')	/*1*/
# define ISS7	(seq[i - 1] == '4' && seq[i] == '8')		/*2*/
# define ISS8	(seq[i - 1] == '4' && seq[i] == '9')	/*1*/
# define ISS9	(seq[i - 1] == '5' && seq[i] == '2')	/*1*/
# define ISS10	(seq[i - 1] == '5' && seq[i] == '5')		/*2*/
# define ISS11	(seq[i - 1] == '5' && seq[i] == '6')	/*1*/
# define ISS12	(seq[i - 1] == '6' && seq[i] == '2')	/*1*/
# define ISS13	(seq[i - 1] == '6' && seq[i] == '5')		/*2*/
# define ISS14	(seq[i - 1] == '6' && seq[i] == '6')	/*1*/
# define ISS15	(seq[i - 1] == '7' && seq[i] == '3')	/*1*/
# define ISS16	(seq[i - 1] == '7' && seq[i] == '9')				/*!*/
# define ISS17	(seq[i - 1] == '7' && seq[i] == ':')				/*!*/
# define ISS18	(seq[i - 1] == '8' && seq[i] == '4')	/*1*/
# define ISS19	(seq[i - 1] == '8' && seq[i] == '9')				/*!*/
# define ISS20	(seq[i - 1] == '8' && seq[i] == ':')				/*!*/
# define ISS21	(seq[i - 1] == '9' && seq[i] == '4')	/*1*/
# define ISS22	(seq[i - 1] == '9' && seq[i] == '7')		/*2*/
# define ISS23	(seq[i - 1] == '9' && seq[i] == '8')	/*1*/
# define ISS24	(seq[i - 1] == ':' && seq[i] == '3')	/*1*/
# define ISS25	(seq[i - 1] == ':' && seq[i] == '7')		/*2*/
# define ISS26	(seq[i - 1] == ':' && seq[i] == '8')	/*1*/
# define IS1	ISS || ISS1 || ISS2 || ISS3 || ISS4 || ISS5 || ISS6 || ISS7
# define IS2	ISS8 || ISS9 || ISS10 || ISS11 || ISS12 || ISS13 || ISS14
# define IS3	ISS15 || ISS16 || ISS17 || ISS18 || ISS19 || ISS20 || ISS21
# define IS4	ISS22 || ISS23 || ISS24 || ISS25 || ISS26
# define IS		IS1 || IS2 || IS3 || IS4
# define SS1	ISS || ISS2 || ISS4 || ISS6 || ISS8 || ISS9 || ISS11 || ISS12
# define SS2	ISS14 || ISS15 || ISS18 || ISS21 || ISS23 || ISS24 || ISS26
# define S1		SS1 || SS2 || (ISS3 && c > 1)
# define S2		ISS1 || ISS7 || ISS10 || ISS13 || ISS22 || ISS25
# define SS3	(ISS3 && c < 2)
# define S3		ISS5 || ISS16 || ISS17 || ISS19 || ISS20 || SS3

typedef struct	s_ps
{
	int 		n;
	char 		c;
	struct s_ps	*nxt;
	struct s_ps	*prv;
}				t_ps;

void			applyrule(t_ps **a, t_ps **b, char **rule);
t_ps			*atoi_stack(char **av, unsigned short i);
t_ps			*b_stack(int i);
char			*charjoin(char **rule, char buf);
int 			chcknewp(char *seq, int i);
int				cleannewp(char *seq, int i);
int				error(void);
int 			freetps(t_ps *a);
void			free_t_ps(t_ps **a, t_ps **b);
int				*intcpy(int *src, int sz);
int 			isdup(t_ps *a);
int				issort(t_ps *a);
int				issortseq(char *seq, int j, int c);
t_ps			*listcpy(t_ps *src);
void			listcpy2(t_ps *src, t_ps **dst);
int 			movep(char *seq, int i);
int 			mvp(char *seq, int i, int c);
int				newp(char *seq, int i, int c);
void			print(t_ps *a, t_ps *b, int f);
void			print_rules(char **rules, char *seq, int i);
void			push(t_ps **dst, t_ps **src);
char			*push_swap(t_ps *a, t_ps *b, char **rules);
void			rotate(t_ps **stack, int dir);
char			**rules_m(void);
int				seqchr(char *s, char c);
int				sequence(int i, char *seq);
void			sortseq(char *seq, int i, int c);
void			swap(t_ps **stack);
int 			test(t_ps *a, t_ps *b, char ***rs, int i);
int				testp(char *seq, int i, int c, int k);

#endif
