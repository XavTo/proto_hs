/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

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

int my_textbox(sfEvent event, sfRenderWindow *window, char *str, int *i)
{
    int ret = *i;

    if (event.type == sfEvtClosed) sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            return (choose_card(window, str));
        else str = keyboard(str, i, ret), str[*i] = '\0';
    }
}

int my_clinio(sfRenderWindow *wd, int *clinio, char *str, sfVector2f pos)
{
    sfTexture *back1 = sfTexture_createFromFile("pic/wait.png", NULL);
    sfSprite *sp = sfSprite_create();
    int move = 0;

    while (str[move] != 0)
        move++;
    pos.x = pos.x + (60 * move);
    sfSprite_setTexture(sp, back1, sfTrue);
    sfSprite_setPosition(sp, pos);
    if (*clinio <= 50 && move != 7)
        sfRenderWindow_drawSprite(wd, sp, NULL);
    (*clinio)++;
    if (*clinio >= 100) 
        *clinio = 0;
    sfTexture_destroy(back1), sfSprite_destroy(sp);
}

int get_keyboard_input(sfRenderWindow *wd, char *str)
{
    int i = 0;
    int clinio = 0;
    sfEvent evt;
    sfTexture *back = sfTexture_createFromFile("pic/plateau2.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.63, 0.63};
    sfVector2f p = {-50, 0};
    sfVector2f save = {330, 255};

    sfSprite_setTexture(my_spr, back, sfTrue), sfSprite_scale(my_spr, size);
    sfSprite_setPosition(my_spr, p), str[0] = '\0';
    while (sfRenderWindow_isOpen(wd)) {
        while (sfRenderWindow_pollEvent(wd, &evt))
            my_textbox(evt, wd, str, &i);
        sfRenderWindow_drawSprite(wd, my_spr, NULL);
        my_clinio(wd, &clinio, str, save);
        draw_str(wd, str, save);
        sfRenderWindow_display(wd);
    }
}