/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/12 14:46:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int detect_flags(char *line, int i)
{
    int old_index;
    
    old_index = i;
    while (line[i] && line[i] != ' ')
    {
        if (line[i] == '-')
        {
            printf(" --> FLAGS : [");
            while (line[i] && line[i] != ' ')
            {
                printf("%c", line[i]);
                i++;
            }
            printf("]");
            // printf("index apres flags --> %d : char : %c\n", i +1, line[i+1]);
            return (i + 1);
        }
        i++;
    }
    printf(" --> FLAGS : [NULL]");
    // printf("\nindex sans flags --> %d : char : %c\n", old_index +1, line[old_index]);
    return (old_index);
}

void arguments_detection(char *line, int i)
{
    while (line[i])
    {
        if (!(is_separator(line, i)))
        {
            printf(" --> ARGUMENTS : [");
            while (line[i] && !(is_separator(line, i)))
            {
                printf("%c", line[i]);
                i++;
            }
            printf("]\n");
        }
        i++;
        return ;
    }
}

int search_built_in(char *line, char *built_in)
{
	int i;
    int new_index;
	int count;
	
	i = 0;
	count = 0;
	while (line[i])
	{
		if (is_in_str(line, i, built_in))
		{
			printf("BUILT_IN : [%s]", built_in);
            new_index = detect_flags(line, i + ft_strlen(built_in));
            arguments_detection(line, new_index);
			count++;
		}
		i++;
	}
	return (count);
}

void built_in_detection(char *str)
{
	search_built_in(str, "echo ");
	search_built_in(str, "cd ");
	search_built_in(str, "pwd ");
	search_built_in(str, "export ");
	search_built_in(str, "unset ");
	search_built_in(str, "env ");
	search_built_in(str, "exit ");

	return ;
}

// void file_detection(char *str)
// {
    
// }