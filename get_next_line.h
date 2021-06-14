/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:45:50 by root              #+#    #+#             */
/*   Updated: 2021/06/07 15:03:40 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h> //open
# include <fcntl.h> //open
# include <stdio.h> //printf
# include <unistd.h> //vérifier à quoi servent ces bibliothèques

int				get_next_line(int fd, char **line);
unsigned int	ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strchr(char *str, char n);
char			*ft_strjoin(char *s1, char *s2);

#endif