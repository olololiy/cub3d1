# include <sys/types.h>
# include <string.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
//# include "libft1/libft.h"
//# include "get_next_line.h"

typedef struct	s_config
{
	int		r;
	int 	no;
	int 	so;
	int		we;
	int 	ea;
	int 	s;
	int 	f;
	int 	c;
	int		count_conf;
	int		r_weight;
	int		r_height;
	char 	*no_texture;
}				t_config;


typedef struct	s_list
{
    void			*content;
    size_t			content_size;
    struct s_list	*next;
}				t_list;
int		get_next_line(int fd, char **line);
int parser(t_config *config);
//int				ft_atoi(const	char *str, t_config *config);
//int		ft_isalpha(int c);
//void	*ft_strchr(const void *s, int c);
//int		ft_isdigit(int c);
//void	ft_lstadd_back(t_list **alst, t_list *new);
//void	ft_putchar(char c);
//void		ft_putstr(char  *str);
//void	ft_putendl(char *s);
//void	ft_lstadd_back(t_list **alst, t_list *new);
//t_list	*ft_lstnew(void *content);
//int		ft_lstsize(t_list *lst);
//void	*ft_calloc(size_t count, size_t size);