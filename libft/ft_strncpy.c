//
// Created by den_b_000 on 20.09.2019.
//

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
    size_t	c;
    int		end;

    c = 0;
    end = 0;
    while (c < n)
    {
        if (s2[c] && !end)
            s1[c] = s2[c];
        else
        {
            s1[c] = '\0';
            end = 1;
        }
        c++;
    }
    return (s1);
}
