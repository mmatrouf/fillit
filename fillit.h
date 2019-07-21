#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_tetrisa
{
	char	a;
	char	tetri[4][5];
	int		x[4];
	int		y[4];
}				t_tetrisa;

typedef struct	s_file
{
	t_tetrisa	file[26];
	char		**map;
	int			count;
}				t_file;

int 	ft_map_size(t_file h);
void	ft_del_tet(t_file *h, int i, int size);
int 	ft_add_tet(t_file *h, int i, int size, int x, int y);
void	ft_map_new(t_file *h, int size);
void	ft_upperleft(t_file *h);
void	ft_coor(t_tetrisa *t);
int		ft_stock(int fd, t_file *t);
int		ft_form(t_tetrisa t);
int		ft_test(int fd, t_tetrisa *t);
int		ft_count(t_tetrisa t);
int		ft_sqrt(int n);
int		ft_solve(t_file *h, int size, int n);
void	ft_display(t_file *t, int size);
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strnew(size_t size);
int				ft_atoi(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putstr(char *str);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrchr(const char *s1, int c);
int				ft_isalnum(int c);
void			ft_memdel(void **ap);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			**ft_strsplit(char const *s, char c);
int				ft_isalpha(int c);
void			*ft_memmove(void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s1, int c);
size_t			ft_strlen(const char *str);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_isascii(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_strclr(char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_isdigit(int c);
void			ft_putchar(char c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s);
int				ft_isprint(int c);
void			ft_putchar_fd(char c, int fd);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
char			*ft_itoa(int n);
void			ft_putendl(char const *s);
void			ft_strdel(char **as);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strdup(const char *s);
char			*ft_strncpy(char *dest, const char *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_putnbr(int n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_multiply(int a, int b);
int				ft_divide(int a, int b);
int				ft_add(int a, int b);
int				ft_subtract(int a, int b);
char			**ft_getnextline(char *str);
char			*ft_capitalize(char *str);
int				ft_wordcount(char *str);
#endif
