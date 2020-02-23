//
// Created by den_b_000 on 20.09.2019.
//

char	*ft_strcpy(char *s1, const char *s2)
{
    int	i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}