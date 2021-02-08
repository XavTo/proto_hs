/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

int my_strlen(char const *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
        c++;
    return (c);
}

int sl(void)
{
    usleep(60000);
}

char *keyboard3(char *str, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum6)) str[*i] = '6', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum7)) str[*i] = '7', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum8)) str[*i] = '8', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum9)) str[*i] = '9', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad0)) str[*i] = '0', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1)) str[*i] = '1', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2)) str[*i] = '2', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3)) str[*i] = '3', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4)) str[*i] = '4', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad5)) str[*i] = '5', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad6)) str[*i] = '6', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad7)) str[*i] = '7', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad8)) str[*i] = '8', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9)) str[*i] = '9', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeySpace)) str[*i] = ' ', sl(), (*i)++;
    return (str);
}

char *keyboard2(char *str, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyO)) str[*i] = 'o', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyP)) str[*i] = 'p', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) str[*i] = 'q', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyR)) str[*i] = 'r', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyS)) str[*i] = 's', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyT)) str[*i] = 't', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyU)) str[*i] = 'u', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyV)) str[*i] = 'v', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyW)) str[*i] = 'v', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyX)) str[*i] = 'x', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyY)) str[*i] = 'y', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) str[*i] = 'z', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum0)) str[*i] = '0', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) str[*i] = '1', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) str[*i] = '2', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) str[*i] = '3', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) str[*i] = '4', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum5)) str[*i] = '5', sl(), (*i)++;
    str = keyboard3(str, i);
    return (str);
}

char *keyboard(char *str, int *i, int ret)
{
    if ((sfKeyboard_isKeyPressed(sfKeyBack)) && *i > 0)
        str[(*i) - 1] = '\0', (*i)--;
    if (*i == 7) return (str);
    if (sfKeyboard_isKeyPressed(sfKeyA)) str[*i] = 'a', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyB)) str[*i] = 'b', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyC)) str[*i] = 'c', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyD)) str[*i] = 'd', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyE)) str[*i] = 'e', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyF)) str[*i] = 'f', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyG)) str[*i] = 'g', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyH)) str[*i] = 'h', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyI)) str[*i] = 'i', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyJ)) str[*i] = 'j', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyK)) str[*i] = 'k', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyL)) str[*i] = 'l', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyM)) str[*i] = 'm', sl(), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyN)) str[*i] = 'n', sl(), (*i)++;
    if (*i > ret) str = realloc(str, my_strlen(str) + 1);
    str = keyboard2(str, i);
    return (str);
}