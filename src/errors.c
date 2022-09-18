/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:52 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/19 00:18:38 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void if_correct_argc(int argc)
{
    if (argc != 2)
    {
        ft_printf("Sorry, wrong amount of arguments!");
            exit(EXIT_FAILURE);
    }
}

void print_error_msg(char *msg)
{
    ft_printf("%s", msg);
    exit(EXIT_FAILURE);
}