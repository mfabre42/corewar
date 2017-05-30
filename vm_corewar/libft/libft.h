/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:13:34 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/30 18:42:56 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_process
{
	unsigned int			*reg;
	unsigned short			pc;
	int						start;
	int						carry;
	int						cycle;
	int						ft;
	int						do_funk;
	int						last_live;
	struct s_process		*next;
}				t_process;

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_process **alst, t_process *new);
void			ft_lstaddend(t_process **lst, t_process *new);
void			ft_lstdel(t_process **alst);
t_process		*ft_lstnew(int start, int cycle);
void			ft_lstdelone(t_process **alst);
void			*ft_memalloc(size_t size);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strstr(const char *haystack, const char *needle);
void			ft_putchar(char c);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);

#endif
