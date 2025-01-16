# 👉LIBFT : A 42 PROJECT👈

## GRADE
✅ 125 %

## DESCRIPTION
This is the first project of the 42 Cursus !

It consists in creating your own library with some standard functions that you can use later in your projects.
This serves as an introduction to programming and the C language !

## FUNCTIONS
Basic functions : 

| NAME  | PROTOTYPE |
| ------------- | ------------- |
| `ft_isalpha` | int	ft_isalpha(int c); |
| `ft_isdigit` | int	ft_isdigit(int c)  |
| `ft_isalnum` | int	ft_isalnum(int c); |
| `ft_isascii` | int	ft_isascii(int c); |
| `ft_isprint` | int	ft_isprint(int c); |
| `ft_strlen` | size_t	ft_strlen(const char *str); |
| `ft_memset` | void	*ft_memset(void *s, int c, size_t n); |
| `ft_bzero` | void	*ft_bzero(void *s, size_t n); |
| `ft_memcpy` | void	*ft_memcpy(void *dest, const void *src, size_t n); |
| `ft_memmove` | void	*ft_memmove(void *dest, const void *src, size_t n); |
| `ft_strlcpy` | size_t	ft_strlcpy(char *dest, const char *src, size_t size); |
| `ft_strlcat` | size_t	ft_strlcat(char *dest, const char *src, size_t size); |
| `ft_toupper` | int	ft_toupper(int c); |
| `ft_tolower` | int	ft_tolower(int c); |
| `ft_strchr` | char	*ft_strchr(const char *s, int c); |
| `ft_strrchr` | char	*ft_strrchr(const char *s, int c); |
| `ft_strncmp` | int	ft_strncmp(const char *s1, const char *s2, size_t n); |
| `ft_memchr` | void	*ft_memchr(const void *s, int c, size_t n); |
| `ft_memcmp` | int	ft_memcmp(const void *s1, const void *s2, size_t n); |
| `ft_strnstr` | char	*ft_strnstr(const char *big, const char *little, size_t len); |
| `ft_atoi` | int	ft_atoi(const char *str); |
| `ft_calloc` | void	*ft_calloc(size_t nmemb, size_t size); |
| `ft_strdup` | char	*ft_strdup(const char *s); |


Additional functions : 

| NAME  | PROTOTYPE |
| ------------- | ------------- |
| `ft_substr` | char *ft_substr(char const *s, unsigned int start, size_t len); |
| `ft_strjoin` | char *ft_strjoin(char const *s1, char const *s2); |
| `ft_strtrim` | char *ft_strtrim(char const *s1, char const *set); |
| `ft_split` | char **ft_split(char const *s, char c); |
| `ft_itoa` | char	*ft_itoa(int n); |
| `ft_strmapi` | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); |
| `ft_striteri` | void ft_striteri(char *s, void (*f)(unsigned int, char*)); |
| `ft_putchar_fd` | void ft_putchar_fd(char c, int fd); |
| `ft_putstr_fd` | void ft_putstr_fd(char *s, int fd); |
| `ft_putendl_fd` | void ft_putendl_fd(char *s, int fd); |
| `ft_putnbr_fd` | void ft_putnbr_fd(int n, int fd); |

## BONUS FUNCTIONS
To do the bonus functions, you need to implement a list structure : 
```
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| NAME  | PROTOTYPE |
| ------------- | ------------- |
| `ft_lstnew` | t_list *ft_lstnew(void *content); |
| `ft_lstadd_front` | void ft_lstadd_front(t_list **lst, t_list *new); |
| `ft_lstsize` | int ft_lstsize(t_list *lst); |
| `ft_lstlast` | t_list *ft_lstlast(t_list *lst); |
| `ft_lstadd_back` | void ft_lstadd_back(t_list **lst, t_list *new); |
| `ft_lstdelone` | void ft_lstdelone(t_list *lst, void (*del)(void *)); |
| `ft_lstclear` | void ft_lstclear(t_list **lst, void (*del)(void *)); |
| `ft_lstiter` | void ft_lstiter(t_list *lst, void (*f)(void *)); |
| `ft_lstmap` |  t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); |
