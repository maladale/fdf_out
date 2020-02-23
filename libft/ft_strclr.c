//
// Created by den_b_000 on 16.09.2019.
//

void ft_strclr(char *s)
{
    char *tmp;

    if (s)
    {
        tmp = s;
        while (*tmp) {
            *tmp = '\0';
            tmp++;
        }
    }
}

