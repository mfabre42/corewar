/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:13:34 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 15:54:09 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_label
{
	char			*l_name;
	int				l_value;
	struct s_label	*next;
}					t_label;

void				ft_memdel(void **ap);
void				ft_lstdelone(t_label **alst);
void				ft_lstdel(t_label **alst);
int					ft_atoi(const char *nptr);
int					ft_count_word(const char *s, char c);
char				*ft_itoa(int n);
void				ft_lstadd(t_label **alst, t_label *new);
t_label				*ft_lstnew(char *name, int value);
void				*ft_memalloc(size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);

#endif
