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

int create_sprite(sfTexture **back, sfTexture **back1, sfSprite **my_spr, sfSprite **sp)
{
    sfVector2f size = {0.63, 0.63};
    sfVector2f p = {-50, 0};
    sfVector2f p1 = {330, 255};
    sfVector2f save = {330, 255};
    sfSprite_setTexture(*my_spr, *back, sfTrue), sfSprite_scale(*my_spr, size);
    sfSprite_setPosition(*my_spr, p), sfSprite_setTexture(*sp, *back1, sfTrue);
    sfSprite_setPosition(*sp, p1);
}

int my_event(sfEvent event, sfRenderWindow *window, char *str, int *i)
{
    int ret = *i;

    if (event.type == sfEvtClosed) sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) return (choose_card(window, str));
        else str = keyboard(str, i, ret), str[*i] = '\0';
    }
}

int my_name(sfRenderWindow *wd, char *str, int tic)
{
    int i = 0;
    int r = i;
    sfEvent evt;
    sfTexture *back = sfTexture_createFromFile("pic/plateau2.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfTexture *back1 = sfTexture_createFromFile("pic/wait.png", NULL);
    sfSprite *sp = sfSprite_create();
    sfVector2f p = {330, 255};
    sfVector2f sv = p;
    create_sprite(&back, &back1, &my_spr, &sp), str[i] = '\0';
    while (sfRenderWindow_isOpen(wd)) {
        while (sfRenderWindow_pollEvent(wd, &evt)) my_event(evt, wd, str, &i);
        if (r > i && i >= 0)
            p.x = sv.x + (60 * i - 1), tic = 0, sfSprite_setPosition(sp, p);
        if (r < i) p.x = sv.x + (60 * i), tic = 0, sfSprite_setPosition(sp, p);
        r = i, sfRenderWindow_drawSprite(wd, my_spr, NULL);
        if (tic <= 50 && i != 7) sfRenderWindow_drawSprite(wd, sp, NULL);
        draw_str(wd, str, sv), sfRenderWindow_display(wd), tic++;
        if (tic >= 100) tic = 0;
    }
}