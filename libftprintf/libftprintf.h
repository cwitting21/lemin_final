/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:25:17 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 11:57:09 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define TYPES "dfosxXiucp%b"
# define SIZE 4933
# define BASE 10
# define INDEX_MINUS	0
# define INDEX_PLUS		1
# define INDEX_SPACE	2
# define INDEX_SHARP	3
# define INDEX_ZERO 	4
# define NO_PRECISION	-1
# define IS_PRECISION(arg) (arg > 0)

typedef struct			s_print
{
	char				buffer[SIZE];
	int					buf_i;
	char				*start;
	char				*end;
	size_t				szof_fmt;
	size_t				szof_lens;
	size_t				sflt;
	int					ret;
	va_list				ap;
	int					is_neg;
	struct{
		int				whole_len;
		int				fract_len;
		int				all_len;
	}					flt;
	struct{
		int				len_f;
		int				len_s;
		int				len_z;
		int				len_num;
		int				len_all;
	}					lens;
	struct{
		char			flags[5];
		int				width;
		int				prec;
		short			size;
		char			type;
	}					fmt;
}						t_print;

union					u_ld
{
	long double			ldb;
	struct{
		unsigned long	mnt : 64;
		unsigned short	exp : 15;
		unsigned char	s :	1;
	}					bits;
};

typedef	struct			s_bfr
{
	char				buf[SIZE];
	int					pow;
	int					i;
}						t_bfr;

typedef	struct			s_nbr_parts
{
	char				whole[SIZE];
	char				frac[SIZE];
	int					i_frac_s;
	int					i_frac_e;
	char				fr_buf[SIZE];
}						t_nbr_parts;

typedef struct			s_float
{
	t_nbr_parts			parts;
	t_bfr				p_buf;
	int					p_arr[64];
	int					k;
	char				res[SIZE];
}						t_float;

int						ft_printf(const char *format, ...);
unsigned long long		get_num_type(t_print *obj);
long double				extract_float(t_print *obj);
t_print					*new_obj(char *format);
void					parse(t_print *obj);
void					parse_flags(t_print *obj);
void					parse_width(t_print *obj);
void					parse_prec(t_print *obj);
void					parse_type(t_print *obj);
void					print(t_print *obj);
void					putnbr_base(t_print *obj, unsigned long long d,
						int base);
void					output_float(t_float *obj_flt, t_print *obj);
void					handle_fractional(t_float *obj_flt);
void					add_zeroes(char *str);
void					normalise_whole(char *str);
void					round_float(t_print *obj, t_float *obj_flt, int i);
void					normalise_frac(char *str);
void					sum_arr(t_float *obj_flt, int code);
void					putnbr_float(t_print *obj, t_float *obj_flt,
						int tmp[3], int i);
void					handle_whole(t_float *obj_flt);
int						len_num_base(unsigned long long num, int base);
int						print_percentage(t_print *obj);
int						print_space(int len);
int						print_zero(int len);
int						print_s(t_print *obj);
int						print_c(t_print *obj);
int						print_d(t_print *obj);
int						print_x(t_print *obj);
int						print_o(t_print *obj);
int						print_p(t_print *obj);
int						print_u(t_print *obj);
int						format_output(t_print *obj);
int						parse_size(t_print *obj);
int						clean(t_print *obj);
int						handle_float(t_print *obj);
int						get_len_float(t_float *obj_flt, t_print *obj);
int						print_space_o(int *len);
int						print_binary(t_print *obj);
int						print_zero_o(int *len);
int						check_if_need_zeroes(t_float *obj_flt, int power);
int						nbr_has_whole_part(t_float *obj_flt);
int						nbr_has_frac_part(t_float *obj_flt);

#endif
