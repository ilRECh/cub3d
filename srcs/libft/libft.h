/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:00:54 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BLACK_BOLD "\033[0;30;1m"
# define RED_BOLD "\033[0;31;1m"
# define GREEN_BOLD "\033[0;32;1m"
# define YELLOW_BOLD "\033[0;33;1m"
# define BLUE_BOLD "\033[0;34;1m"
# define MAGENTA_BOLD "\033[0;35;1m"
# define CYAN_BOLD "\033[0;36;1m"

///
///    SORTs
///    CONFIGURE sort_config.h FIRST!
///
typedef struct s_index
{
    size_t    First;
    size_t    Middle;
    size_t    Last;
}    t_index;

typedef struct s_function
{
    int    (*compare)(void *, void *, size_t, size_t);
    int    (*assign)(void *, void *, size_t, size_t);
}    t_function;

typedef enum e_DATA_TYPE
{
    CHAR = 1,
    UCHAR = 11,
    INT = 14,
    UINT = 24,
    LONG = 28,
    ULONG = 38,
    FLOAT = 34,
    DOUBLE = 18
}    t_DATA_TYPE;

void            ft_mergesort(void *to_sort, size_t len, t_DATA_TYPE type);

///
/// MEMs
///
void            *ft_memmove(void *dest, const void *src, size_t n);
void            *ft_memchr(const void *s, int c, size_t n);
int                ft_memcmp(const void *s1, const void *s2, size_t n);
void            *ft_memccpy(void *dst, const void *src, int c, size_t n);
void            *ft_memcpy(void *dst, const void *src, size_t n);
void            *ft_memset(void *b, int c, size_t len);
void            ft_bzero(void *s, size_t n);
void            *ft_memchr(const void *s, int c, size_t n);
int                ft_memcmp(const void *s1, const void *s2, size_t n);
void            *ft_memmove(void *dest, const void *src, size_t n);

///
///    IS
///
int                ft_isalnum(int c);
int                ft_isalpha(int c);
int                ft_isascii(int c);
int                ft_isdigit(int c);
int                ft_isprint(int c);
int                ft_isspace(int c);

///
///    TO
///
int                ft_tolower(int c);
int                ft_toupper(int c);

///
/// CONVERTIONs
///
int                ft_atoi(const char *nptr);
char            *ft_itoa(int n);

///
///    MEMORY ALLOCs
///
void            *ft_calloc(size_t nmemb, size_t size);

///
///    STRINGs
///
size_t            ft_strlen(const char *s);
size_t            ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t            ft_strlcat(char *dst, const char *src, size_t dstsize);
char            *ft_strchr(const char *s, int c);
char            *ft_strchr(const char *s, int c);
char            *ft_strdup(const char *s);
char            *ft_strjoin(char const *s1, char const *s2);
size_t            ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t            ft_strlcpy(char *dst, const char *src, size_t dst_size);
char            *ft_strndup(const char *s, size_t len);
size_t            ft_strlen(const char *s);
int                ft_strncmp(const char *s1, const char *s2, size_t n);
char            *ft_strnstr(const char *big, const char *little, size_t len);
char            *ft_strrchr(const char *s, int c);
char            *ft_strtrim(char const *s1, char const *set);
char            *ft_substr(char const *s, unsigned int start, size_t len);
char            **ft_split(char const *s, char c);
char            *ft_strmapi(char const *s, char (*f)(unsigned int, char));

///
///    PUTs
///
void            ft_putchar_fd(char c, int fd);
void            ft_putstr_fd(char *s, int fd);
void            ft_putendl_fd(char *s, int fd);
void            ft_putnbr_fd(int n, int fd);

///
///    MATHs
///
unsigned int    ft_abs(int n);

///
///    LISTS
///
typedef struct s_slist    t_slist;
typedef struct s_dlist    t_dlist;
typedef struct s_list
{
    t_slist    *Sstart;
    t_dlist    *Dstart;
    t_slist    *Scur;
    t_dlist    *Dcur;
}    t_list;

///
///    Single-linked list
///
typedef struct s_slist
{
    void            *content;
    struct s_slist    *next;
}    t_slist;

t_slist            *ft_lstnewS(void *content);
void            ft_lstadd_frontS(t_slist **lst, void *cont);
int                ft_lstsizeS(t_slist *lst);
t_slist            *ft_lstlastS(t_slist *lst);
void            ft_lstadd_backS(t_slist **lst, void *cont);
void            ft_lstdeloneS(t_slist *lst, void (*del)(void *));
void            ft_lstclearS(t_slist **lst, void (*del)(void *));
void            ft_lstiterS(t_slist *lst, void (*f)(void *));
t_slist            *ft_lstmapS(t_slist *lst, void *(*f)(void *),
                    void (*del)(void *));

///
///    Double-linked list
///
typedef struct s_dlist
{
    void            *content;
    struct s_dlist    *next;
    struct s_dlist    *prev;
}    t_dlist;

char            **ft_lst_to_char(t_dlist *lst);
t_dlist            *ft_lstnewD(void *content);
void            ft_lstadd_frontD(t_dlist **lst, void *cont);
int                ft_lstsizeD(t_dlist *lst);
t_dlist            *ft_lstlastD(t_dlist *lst);
t_dlist            *ft_lstfirstD(t_dlist *lst);
void            ft_lstadd_backD(t_dlist **lst, void *cont);
void            ft_lstdeloneD(t_dlist *lst, void (*del)(void *));
void            ft_lstclearD(t_dlist **lst, void (*del)(void *));
void            ft_lstiterD(t_dlist *lst, void (*f)(void *));
t_dlist            *ft_lstmapD(t_dlist *lst, void *(*f)(void *),
                    void (*del)(void *));

#endif
