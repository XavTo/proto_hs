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

int draw_str(sfRenderWindow *window, char *str, sfVector2f pos)
{
    sfFont* font = sfFont_createFromFile("font/font.ttf");
    sfText* text = sfText_create();

    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text), sfFont_destroy(font);
}

char *keyboard3(char *str, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum6)) str[*i] = '6', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum7)) str[*i] = '7', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum8)) str[*i] = '8', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum9)) str[*i] = '9', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad0)) str[*i] = '0', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1)) str[*i] = '1', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2)) str[*i] = '2', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3)) str[*i] = '3', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4)) str[*i] = '4', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad5)) str[*i] = '5', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad6)) str[*i] = '6', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad7)) str[*i] = '7', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad8)) str[*i] = '8', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9)) str[*i] = '9', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeySpace)) str[*i] = ' ', usleep(150000), (*i)++;
    return (str);
}

char *keyboard2(char *str, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyO)) str[*i] = 'o', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyP)) str[*i] = 'p', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) str[*i] = 'q', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyR)) str[*i] = 'r', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyS)) str[*i] = 's', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyT)) str[*i] = 't', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyU)) str[*i] = 'u', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyV)) str[*i] = 'v', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyW)) str[*i] = 'v', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyX)) str[*i] = 'x', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyY)) str[*i] = 'y', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) str[*i] = 'z', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum0)) str[*i] = '0', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) str[*i] = '1', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) str[*i] = '2', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) str[*i] = '3', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) str[*i] = '4', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyNum5)) str[*i] = '5', usleep(150000), (*i)++;
    str = keyboard3(str, i);
    return (str);
}

char *keyboard(char *str, int *i, int ret, sfRenderWindow *window)
{
    if ((sfKeyboard_isKeyPressed(sfKeyBack)) && *i > 0)
        str[(*i) - 1] = '\0', usleep(150000), (*i)--;
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) choose_card(window);
    if (*i == 7) return (str);
    if (sfKeyboard_isKeyPressed(sfKeyA)) str[*i] = 'a', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyB)) str[*i] = 'b', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyC)) str[*i] = 'c', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyD)) str[*i] = 'd', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyE)) str[*i] = 'e', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyF)) str[*i] = 'f', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyG)) str[*i] = 'g', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyH)) str[*i] = 'h', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyI)) str[*i] = 'i', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyJ)) str[*i] = 'j', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyK)) str[*i] = 'k', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyL)) str[*i] = 'l', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyM)) str[*i] = 'm', usleep(150000), (*i)++;
    if (sfKeyboard_isKeyPressed(sfKeyN)) str[*i] = 'n', usleep(150000), (*i)++;
    if (*i > ret) str = realloc(str, my_strlen(str) + 1);
    str = keyboard2(str, i);
    return (str);
}

int my_name(sfRenderWindow *window)
{
    int tic = 0;
    int i = 0;
    int ret = i;
    char *str = malloc(sizeof(char) * 2);
    sfEvent event;
    sfTexture *back = sfTexture_createFromFile("pic/plateau2.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfTexture *back1 = sfTexture_createFromFile("pic/wait.png", NULL);
    sfSprite *my_spr1 = sfSprite_create();
    sfVector2f size = {0.63, 0.63};
    sfVector2f p = {-50, 0};
    sfVector2f p1 = {330, 255};
    sfVector2f save = {330, 255};
    sfSprite_setTexture(my_spr, back, sfTrue), sfSprite_scale(my_spr, size);
    sfSprite_setPosition(my_spr, p), sfSprite_setTexture(my_spr1, back1, sfTrue);
    sfSprite_setPosition(my_spr1, p1);
     while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            str = keyboard(str, &i, ret, window), str[i] = '\0';
        }
        if (ret > i && i >= 0) p1.x = save.x + (60 * i - 1), tic = 0, sfSprite_setPosition(my_spr1, p1);
        if (ret < i) p1.x = save.x + (60 * i), tic = 0, sfSprite_setPosition(my_spr1, p1);
        ret = i;
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        if (tic <= 50 && i != 7) sfRenderWindow_drawSprite(window, my_spr1, NULL);
        draw_str(window, str, save);
        sfRenderWindow_display(window), tic++;
        if (tic >= 100) tic = 0;
    }
}