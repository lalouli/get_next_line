/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:57 by hlalouli          #+#    #+#             */
/*   Updated: 2021/12/08 15:40:41 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

int		ft_strlen(char *s);
char	*ft_strdup( char *s1);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*new_line(char *hou);
int		line(char *hou);
char	*rest(char *hou);
char	*get_next_line(int fd);

#endif
