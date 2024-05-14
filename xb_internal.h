/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xb_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:17 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 13:14:23 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef XB_INTERNAL_H
# define XB_INTERNAL_H
# include "xb.h"
# define UNIX_READ_BUFFER_SIZE 1024

typedef struct s_printf_token
{
	int		length;
	char	*string;
}	t_printf_token;

typedef union u_conversion_arg
{
	char			rune;
	int				i32;
	unsigned int	u32;
	long			i64;
	const char		*s8;
}	t_conversion;

typedef struct s_printf_infos
{
	int						is_alt_form;
	int						is_left_justify;
	int						is_sign_always_present;
	int						is_sign_space_always_present;
	int						is_padding_zero;
	int						is_precised;
	struct s_printf_infos_length
	{
		int					format;
		int					total;
		int					padding;
		int					precision;
		int					field_width;
	}						length;
	char					conversion;
	union u_conversion_arg	argument;
}	t_printf_infos;

t_printf_token	xb_token_from_rune(t_printf_infos infos);
t_printf_token	xb_token_from_cstr(t_printf_infos infos);
t_printf_token	xb_token_from_addr(t_printf_infos infos);
t_printf_token	xb_token_from_idec(t_printf_infos infos);
t_printf_token	xb_token_from_udec(t_printf_infos infos);
t_printf_token	xb_token_from_uhex(t_printf_infos infos);

int				xb_internal_atoi(const char *src, int accept_signs);
#endif
