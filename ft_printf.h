/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:14:43 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:14:57 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
/*
	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define FLAGS "#0-+ "
# define MOD "hljz"
# define SPEC "spdouxXc%"

# define ARG ((t_arg *)(tmpa->content))
# define SFLAGS ((t_flags)(ARG->flags))
# define SMOD ((t_mod)(ARG->mod))
# define SPREC ((t_prec)(ARG->prec))
# define SSTR ((t_str *)(tmps->content))

typedef struct		s_str
{
	char			*str;
	int				n;
}					t_str;

typedef struct		s_mod
{
	int				h;
	int				l;
	int				j;
	int				z;
}					t_mod;

typedef struct		s_flags
{
	int				diez;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	size_t			width;
}					t_flags;

typedef struct		s_prec
{
	int				pt;
	size_t			n;
}					t_prec;

typedef struct		s_arg
{
	void			*arg;
	t_flags			flags;
	t_mod			mod;
	t_prec			prec;
	char			*spec;
	int				action;

}					t_arg;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_elem
{
	void			*content;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_dbllist
{
	size_t			length;
	struct s_elem	*head;
	struct s_elem	*tail;
}					t_dbllist;

typedef char *(* t_action)(t_elem *, char **, int *);

//
void			ft_putlstt(t_dbllist *list);

//

int					ft_printf(const char *format, ...);
void				display_percent(int n, t_dbllist *lst_str);
int					recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i);
int					percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i);
int					split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i);
int					error(const char *msg);
int					clean_lst(t_dbllist *lst_arg);
void				recover_param(va_list ap, t_dbllist *lst_arg);
void				ini_sarg(t_arg *sarg);
void				ini_sstr(t_str *sstr);
void				reini_mod(t_arg *sarg);
int					checks(const char *format, int *i, t_arg *sarg);
int					check_spec(const char *format, int *i, t_arg *sarg);
int					check_prec(const char *format, int *i, t_arg *sarg);
int					check_mod(const char *format, int *i, t_arg *sarg);
int					check_width(char *str, t_arg *sarg, int *i);
int					check_flags(const char *format, int *i, t_arg *sarg);
void				ft_putlststr(t_dbllist *lst_str, int *oct);
int					stock_str(const char *format, int	i, t_dbllist *lst_str);
void				cleanarg(t_dbllist *lst_arg);
void				transformation(t_dbllist *lst_arg, t_dbllist *lst_str, int *cpt_null);
char				*ft_string(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_ptr(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_dec(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_octal(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_unsig(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_hexalower(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_hexaupper(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_char(t_elem *tmpa, char **str, int *cpt_null);
char				*ft_percent(t_elem *tmpa, char **str, int *cpt_null);

int					errormod(t_arg *sarg);
char				*mod_string(t_elem *tmpa);
char				*mod_dec(t_elem *tmpa);
char				*mod_octal(t_elem *tmpa);
char				*mod_unsig(t_elem *tmpa);
char				*mod_hexa(t_elem *tmpa);
char				*mod_char(t_elem *tmpa);

void				diez_o(char **str);
void				diez_hexaupper_zero(char **str, size_t len, t_elem *tmpa);
void				diez_hexaupper(char **str, size_t len, t_elem *tmpa);

void				width(t_elem *tmpa, char **str);

void				space(char **str);

void				plus_space(t_elem *tmpa, char **str, size_t	len);
void				plus_zero(t_elem *tmpa, char **str, size_t	len);
void				minus_space(t_elem *tmpa, char **str, size_t len);
void				minus_zero(t_elem *tmpa, char **str, size_t len);

void				prec_doux(t_elem *tmpa, char **str);
void				prec_s(t_elem *tmpa, char **str);

char				*ft_wchar_str(t_elem *tmpa);
char				*mask_prec(wchar_t c,  t_elem *tmpa, size_t *i);
char				*mask(wchar_t c);
char				*fill_maska(wchar_t nb);
char				*fill_maskb(wchar_t nb);
char				*fill_maskc(wchar_t nb);


int					ft_atoi(const char *str);
void				*ft_bzero(void *s, size_t n);
int					ft_count_words(char const *s, char c);
size_t				ft_intlen(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
size_t				ft_intlenbase_imax(intmax_t n, size_t base);
size_t				ft_intlenbase(int n, size_t base);
size_t				ft_intlenbase_uimax_x(uintmax_t n, size_t base);
size_t				ft_intlenbase_uimax(uintmax_t n, size_t base);
char				*ft_itoabase_imax(intmax_t n, size_t base);
char				*ft_itoabase_imax_x(intmax_t n, size_t base);
char				*ft_itoabase_uimax_x(uintmax_t n, size_t base);
char				*ft_itoabase_uimax(uintmax_t n, size_t base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdbladd(t_dbllist *list, void *content, size_t cont_size);
void				ft_lstdbldel(t_dbllist *list);
t_dbllist			*ft_lstdblnew(void);
void				ft_putlsthead(t_dbllist *list);
void				ft_putlsttail(t_dbllist *list);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const*s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
void				ft_strlower(char **str);
int					ft_toupper(int c);

#endif

