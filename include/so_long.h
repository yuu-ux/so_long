// 構造体定義
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
    void *mlx;
    void *win;
}   t_vars;

// 標準ライブラリ
#include <stdlib.h>
#include <string.h>
