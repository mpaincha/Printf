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

# include "libftprintf/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define FLAGS "#0-+ "
# define LENGTH "hljz"
# define PREC "0n*" //il doit y avoir un point devant + rien est egalement possible
# define SPEC "sSpdDioOuUxXcC"

# define ARG ((t_arg *)(tmpa->content))
# define SFLAGS ((t_flags)(ARG->flags))

typedef struct		s_flags
{
	int				diez;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				numb;
}					t_flags;

typedef struct		s_arg
{
	void			*arg;
	t_flags			flags;
	char			*length;
	char			*prec;
	char			*spec;
	char			*type;

}					t_arg;

int		ft_printf(const char *format, ...);
void	display_percent(int n, t_dbllist *lst_str);
void	recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, t_elem *tmp);
int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i, t_elem *tmp);
int		split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i, t_elem *tmp);
int		error(const char *msg);
void	ft_putlst(t_dbllist	*list); //fonction de debug
int		clean_lst(t_dbllist *lst_arg);
void	recover_param(va_list ap, t_dbllist *lst_arg);
void	ini_sarg(t_arg *sarg);
int		check_spec(char find, t_elem *tmp);
int		check_prec(char point, char find, int *i, t_elem *tmp);
int		check_length(char find, t_elem *tmp);
int		check_number(char *str, t_arg *sarg, int *i);
int		check_flags(char find, t_elem *tmp);
void	ft_putlststr(t_dbllist	*list);
int		stock_str(const char *format, int	i, t_dbllist *lst_str);
void	cleanarg(t_dbllist *lst_arg);

#endif


/*
Voila la liste des différents formats utilisables pour la fonction printf :

* %c : S'il n'y a pas de modificateur l, l'argument entier, de type int, est
converti en un unsigned char, et le caractère correspondant est affiché. Si un
modificateur l est présent, l'argument de type wint_t (caractère large) est
converti en séquence multi-octet par un appel à wcrtomb(3), avec un état de
conversion débutant dans l'état initial. La chaîne multi-octet résultante est
écrite.

* %C : Treated as c with the l (ell) modifier.

* %u : L'argument unsigned int est converti en chiffre décimal non signé (u)\

* %U :  The long int argument is converted to unsigned decimal, as if the format
had been lu.  These conversion characters are deprecated, and will eventually
disappear.

* %o : L'argument unsigned int est converti en un chiffre octal non signé (o)

* %O : The long int argument is converted to unsigned octal, as if the format
had been ld, lo,

* %d : L'argument int est converti en un chiffre décimal signé. La précision,
si elle est mentionnée, correspond au nombre minimal de chiffres qui doivent
apparaître. Si la conversion fournit moins de chiffres, le résultat est rempli
à gauche avec des zéros. Par défaut la précision vaut 1. Lorsque 0 est converti
avec une précision valant 0, la sortie est vide.

* %D : The long int argument is converted to signed decimal, as if the format
had been ld, lo,

* %i : L'argument int est converti en un chiffre décimal signé. La précision,
si elle est mentionnée, correspond au nombre minimal de chiffres qui doivent
apparaître. Si la conversion fournit moins de chiffres, le résultat est rempli
à gauche avec des zéros. Par défaut la précision vaut 1. Lorsque 0 est converti
avec une précision valant 0, la sortie est vide.

* %x : converti en un chiffre hexadécimal non signé. Les lettres abcdef sont
utilisées pour les conversions avec x - unsigned int

* %X : converti en un chiffre hexadécimal non signé. les lettres ABCDEF sont
utilisées pour les conversions avec X. - unsigned i nt

* %s : S'il n'y a pas de modificateur l, l'argument de type const char * est
supposé être un pointeur sur un tableau de caractères (pointeur sur une chaîne).
Les caractères du tableau sont écrits jusqu'à l'octet nul « \0 » final, non
compris. Si une précision est indiquée, seul ce nombre de caractères sont
écrits. Si une précision est fournie, il n'y a pas besoin d'octet nul. Si la
précision n'est pas donnée, ou si elle est supérieure à la longueur de la
chaîne, l'octet nul final est nécessaire

* %S : Treated as s with the l (ell) modifier.

* %p : The void * pointer argument is printed in hexadecimal
(as if by `%#x' or `%#lx').


Voici la liste de ces formats "complémentaires" donc pour initier :

* - : résultat cadré à gauche
* + : résultat préfixé avec le signe + si le nombre est positif
* # :
résultat préfixé par 0 si placé dans %o
résultat préfixé par Ox si placé dans %x, %X
présence systématique du point décimale si placé dans %f, %e, %g, %E, %F
* 0 : résultat complété à gauche par des zéros
* n : taille de la chaine affichée, où n est le nombre minimum de caractère à
afficher.
* .n : précision décimal où n est le nombre de chiffres après la virgule.
* h : précise que le paramètre est de type short
* l : précise que le paramètre est de type long
* L : précise que le paramètre est type long double
*/
