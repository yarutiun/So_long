/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:52 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/19 14:27:50 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void if_correct_argc(int argc)
{
    if (argc != 2)
    {
        ft_putstr_fd("Sorry, wrong amount of arguments!", 1);
            exit(EXIT_FAILURE);
    }
}

void print_error_msg(char *msg)
{
    ft_putstr_fd(msg, 1);
    exit(EXIT_FAILURE);
}