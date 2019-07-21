#include "fillit.h"

int		ft_add(int a, int b)
{
	return (a + b);
}


static char	*ft_clr_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	return ((char*)str);
}

int			ft_atoi(const char *str)
{
	int					isneg;
	int long long		nbr;

	nbr = 0;
	isneg = 0;
	str = ft_clr_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg++;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (isneg)
		return (-nbr);
	return (nbr);
}


void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = -1;
	while (++i < (int)n)
		((unsigned char*)s)[i] = 0;
}


char	*ft_capitalize(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
					|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
			i++;
		while (str[i] && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + 32;
			i++;
		}
		i++;
	}
	return (str);
}


int		ft_divide(int a, int b)
{
	if (!a || !b)
		return (0);
	return (a / b);
}



char	**ft_getnextline(char *str)
{
	return (ft_strsplit(str, '\n'));
}

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}


int		ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}


int		ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}


int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}


int		ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}


static void	ft_isneg(int *n, int *isneg)
{
	if (*n < 0)
	{
		*isneg += 1;
		*n *= -1;
	}
}

static void	ft_len(int n, int *len, int isneg)
{
	if (n == 0)
		*len = 2;
	while (n /= 10)
		*len += 1;
	if (isneg)
		*len += 1;
	*len += 2;
}

static int	ft_end(int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		isneg;
	char	*ptr;
	int		len;

	isneg = 0;
	len = 0;
	if (ft_end(n))
		return (0);
	ft_isneg(&n, &isneg);
	ft_len(n, &len, isneg);
	ptr = (char*)malloc(sizeof(char) * (len));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || ptr == 0)
		return (!ptr ? 0 : ft_strcpy(ptr, "0"));
	ft_bzero(ptr, len--);
	ptr[--len] = '0' + n % 10;
	while (n /= 10)
		ptr[--len] = '0' + n % 10;
	if (isneg)
		ptr[0] = '-';
	return (ptr);
}


void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}


void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = NULL;
	while ((*alst) != NULL)
	{
		tmp = *alst;
		(*alst) = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
}


void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = 0;
	}
}


void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *buff;

	if (!lst || !f)
		return (lst);
	new = f(lst);
	buff = new;
	while (lst->next != 0)
	{
		lst = lst->next;
		buff->next = f(lst);
		buff = buff->next;
	}
	return (new);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	if ((lst = ft_memalloc(sizeof(t_list))) && content)
	{
		if ((lst->content = malloc(content_size)))
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
		else
			ft_memdel((void **)&lst);
	}
	return (lst);
}


void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
	{
		ptr = malloc(size);
		if (ptr)
		{
			ft_bzero(ptr, size);
			return (ptr);
		}
	}
	return (0);
}


void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int i;

	i = -1;
	if ((int)n < 0)
		n = ft_strlen(s2);
	while (++i < (int)n)
	{
		((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
		if (((unsigned char*)s1)[i] == (unsigned char)c)
			return (s1 + i + 1);
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = -1;
	while (++i < (int)n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((void*)s + i);
	}
	return ((void*)0);
}


int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	i = 0;
	if (n <= 0)
		return (0);
	n--;
	while (a[i] == b[i] && i < (int)n)
		i++;
	return (((int)a[i]) - ((int)b[i]));
}


void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char*)s1)[i] = ((unsigned char *)s2)[i];
	return (s1);
}


void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = ((void*)0);
	}
}


void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (s1 < s2)
	{
		while (++i < n)
			((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
	}
	else
		while (n--)
			((unsigned char*)s1)[n] = ((unsigned char*)s2)[n];
	return (s1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;

	i = -1;
	while (++i < (int)len)
		((unsigned char*)b)[i] = (char)c;
	return (b);
}


int		ft_multiply(int a, int b)
{
	return (a * b);
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putendl(char const *str)
{
	ft_putstr((char*)str);
	ft_putstr("\n");
}


void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}


void	ft_putnbr(int n)
{
	char	a;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n > -1 && n < 10 && n != -2147483648)
	{
		a = n + '0';
		write(1, &a, 1);
	}
	else if (n != -2147483648 && n > -1)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 0 && n != -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
}


void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n > -1 && n < 10 && n != -2147483648)
	{
		a = n + '0';
		write(fd, &a, 1);
	}
	else if (n != -2147483648 && n > -1)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}


void	ft_putstr(char *str)
{
	size_t	i;

	if (str)
	{
		i = -1;
		while (str[++i])
			write(1, &str[i], 1);
	}
}


void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (s)
	{
		i = -1;
		while (s[++i])
			write(fd, &s[i], 1);
	}
}


char	*ft_strcat(char *s1, const char *src)
{
	int		i;
	int		x;

	i = -1;
	x = -1;
	while (s1[++i])
		;
	while (src[++x])
		s1[i++] = src[x];
	s1[i] = '\0';
	return (s1);
}


char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if ((char)c == '\0' && !s[0])
		return ((char*)s + i);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char*)s + i);
		i++;
		if ((char)c == s[i])
			return ((char*)s + i);
	}
	return ((char*)0);
}


void	ft_strclr(char *a)
{
	int		i;

	if (a)
	{
		i = ft_strlen(a);
		while (--i > -1)
			a[i] = '\0';
	}
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}


char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}


void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = ((char*)0);
	}
}


char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		a;
	int		i;

	a = (int)ft_strlen(str);
	cpy = (char*)malloc(sizeof(char) * a + 1);
	i = -1;
	if (cpy)
	{
		while (++i < a)
			cpy[i] = str[i];
		cpy[i] = '\0';
	}
	return (cpy);
}


int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 && s2)
		if (!ft_strcmp(s1, s2))
			return (1);
	return (0);
}


void	ft_striter(char *s, void (*f)(char*))
{
	int	i;

	if (s && f)
	{
		i = -1;
		while (s[++i])
			f(&s[i]);
	}
}


void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = -1;
		while (s[++i])
			f(i, &s[i]);
	}
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ptr;

	i = -1;
	if (!s1 && s2)
		return ((char*)s2);
	if (s1 && !s2)
		return ((char*)s1);
	if (!s1 && !s2)
		return (0);
	ptr = (char*)malloc(sizeof(char) * (1 + ft_strlen(s1) + ft_strlen(s2)));
	if (ptr == 0)
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	z;

	z = 0;
	while (dst[z] && z < size)
		z++;
	if (size == z)
		return (size + ft_strlen(src));
	ft_strncat(&dst[z], src, size - z - 1);
	return (z + ft_strlen(src));
}


size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}


char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*ptr;

	if (s && f)
	{
		i = -1;
		ptr = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (ptr)
		{
			while (s[++i])
				ptr[i] = f(s[i]);
			ptr[i] = '\0';
			return (ptr);
		}
	}
	return (0);
}


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	if (s && f)
	{
		i = -1;
		ptr = (char*)malloc(sizeof(char) * (int)ft_strlen(s) + 1);
		if (ptr)
		{
			while (s[++i])
				ptr[i] = f(i, s[i]);
			ptr[i] = '\0';
		}
		return (ptr);
	}
	return (0);
}


char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		x;

	i = ft_strlen(dest);
	x = -1;
	while (src[++x] && n)
	{
		dest[i] = src[x];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while (s1[i] == s2[i] && s2[i] && s1[i] && i < n)
		i++;
	return (((int)(unsigned char)s1[i]) - ((int)(unsigned char)s2[i]));
}


char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}


int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		if (!(ft_strncmp(s1, s2, n)))
			return (1);
	return (0);
}


char	*ft_strnew(size_t size)
{
	char	*a;

	if (!(a = (char*)malloc(size + 1)))
		return (0);
	ft_bzero((void*)a, 1 + size);
	return (a);
}


char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		x;

	i = -1;
	if (!s2[0])
		return ((char*)s1);
	while (s1[++i] && i < (int)n)
	{
		x = 0;
		while (s1[i + x] == s2[x] && i + x < (int)n)
		{
			if (!s2[x + 1])
				return ((char*)s1 + i);
			x++;
		}
	}
	return (0);
}


char	*ft_strrchr(const char *s1, int c)
{
	int		i;
	int		ctr;

	i = -1;
	ctr = -1;
	while (s1[++i])
		if (s1[i] == (const char)c)
			ctr = i;
	if (c == 0)
		ctr = i;
	if (ctr > -1)
		return ((char*)s1 + ctr);
	else
		return ((char*)0);
}


static int	cnt_words(const char *s, char c)
{
	int	ctr;
	int i;

	i = 0;
	ctr = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			ctr++;
		i++;
	}
	return (ctr);
}

static int	wordlen(const char *s, char c)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i + x] != c && s[i + x])
		x++;
	return (x);
}

static void	set_dptr(const char *s, char **dptr, int *i, char c)
{
	int		len;

	len = 0;
	while (*i < cnt_words(s, c))
	{
		while (s[len] == c)
			len++;
		dptr[*i] = ft_strsub(&s[len], 0, wordlen(&s[len], c));
		len += wordlen(&s[len], c);
		*i += 1;
	}
	dptr[*i] = 0;
}

char		**ft_strsplit(const char *s, char c)
{
	char	**dptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
	{
		dptr = (char**)malloc(sizeof(char *));
		dptr[0] = 0;
		return (dptr);
	}
	if (!(dptr = (char**)malloc(sizeof(char *) * (cnt_words(s, c) + 1))))
		return (0);
	set_dptr(s, dptr, &i, c);
	return (dptr);
}


char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		x;

	if (!s2[0])
		return ((char*)s1);
	i = -1;
	while (s1[++i])
	{
		x = 0;
		while (s1[i + x] == s2[x])
		{
			if (!s2[x + 1])
				return ((char*)&s1[i]);
			x++;
		}
	}
	return (NULL);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (0);
	ptr = (char*)malloc(sizeof(char) * ((int)len + 1));
	if (ptr)
	{
		while (s[start + i] && i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = 0;
		return (ptr);
	}
	return (0);
}


char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	i;
	size_t	x;

	i = 0;
	if (!s)
		return (0);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	x = ft_strlen(s);
	while (x != 0 && ((s[x - 1] == ' ') || (s[x - 1] == '\n')
				|| (s[x - 1] == '\t')))
		x--;
	ptr = (char*)malloc(sizeof(char) * (x + 1));
	if (ptr)
	{
		ft_strncpy(ptr, s, x);
		ptr[x] = '\0';
	}
	return (ptr);
}



int		ft_subtract(int a, int b)
{
	return (a - b);
}


int		ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}


int		ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

int		ft_wordcount(char *str)
{
	int i;
	int ctr;

	ctr = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i + 1] == ' ')
				|| (str[i] != ' ' && str[i + 1] == 0))
			ctr++;
		i++;
	}
	return (ctr);
}
