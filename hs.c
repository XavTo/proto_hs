/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

int reset(sfRenderWindow *window);

int print_fps(sfRenderWindow *window, int fps)
{
    char *str = my_itoa(fps);
    sfVector2f pos = {10, 10};
    sfFont* font = sfFont_createFromFile("font/font.ttf");
    sfText* text = sfText_create();

    if (fps >= 60)
        sfText_setColor(text, sfGreen);
    else
        sfText_setColor(text, sfRed);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text), sfFont_destroy(font);
}

int my_replay(sfRenderWindow *window, int i)
{
    if (i == 1) {
        if ((sfMouse_getPositionRenderWindow(window).x >= 850 && sfMouse_getPositionRenderWindow(window).x <= 970) &&
        (sfMouse_getPositionRenderWindow(window).y >= 250 && sfMouse_getPositionRenderWindow(window).y <= 310))
            return (reset(window));
    }
    sfTexture *back = sfTexture_createFromFile("pic/replay.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.5, 0.5};
    sfVector2f p = {860, 270};
    sfSprite_scale(my_spr, size);
    sfSprite_setPosition(my_spr, p);
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

int my_game(sfRenderWindow *window, card_t *card, card_t *carden)
{
    sfEvent event;
    int fps = 0;
    sfClock *clock = sfClock_create();
    int i = 0;
    int first = 0;
    int second = 0;
    int stock_fps = 30;
    sfTexture *back = sfTexture_createFromFile("pic/plateau.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.63, 0.63};
    sfVector2f p = {-50, 0};
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfSprite_scale(my_spr, size);
    sfSprite_setPosition(my_spr, p);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) my_replay(window, 1);
        }
        if (second != 1) card = my_check_combat(window, 0, &first, card, &carden[0], &carden[1]);
        if (first != 1) card = my_check_combat(window, 1, &second, card, &carden[0], &carden[1]);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        my_replay(window, 0);
        display_card(window, card, carden);
        print_fps(window, stock_fps);
        sfRenderWindow_display(window);
        if (sfClock_getElapsedTime(clock).microseconds >= 1000000)
            sfClock_restart(clock), stock_fps = fps, fps = 0;
        fps++;
    }
}

int choose_card(sfRenderWindow *window, char *str)
{
    int i = 1;
    card_t *card = malloc(sizeof(card_t) * i);
    card_t *carden = malloc(sizeof(card_t) * i);
    card[0].pos.x = 400, card[0].pos.y = 300;
    card[0].save.x = 400, card[0].save.y = 300;
    card[0].filepath = "pic/minions/magi.jpg", card[0].name = str;
    card[0].pv = 7, card[0].attack = 6, card[0].cost = 6;
    card[0].shield = false, card[0].provoc = false;

    i++, card = realloc(card, sizeof(card_t) * i);
    card[1].pos.x = 600, card[1].pos.y = 300;
    card[1].save.x = 600, card[1].save.y = 300;
    card[1].filepath = "pic/minions/minirobot.jpg", card[1].name = "robot";
    card[1].pv = 2, card[1].attack = 2, card[1].cost = 2;
    card[1].shield = true, card[1].provoc = false;

    carden[0].pos.x = 400, carden[0].pos.y = 150;
    carden[0].save.x = 400, carden[0].save.y = 150;
    carden[0].filepath = "pic/minions/yeti.jpg", carden[0].name = "yeti";
    carden[0].pv = 5, carden[0].attack = 4, carden[0].cost = 4;
    carden[0].shield = false, carden[0].provoc = false;
    
    carden = realloc(carden, sizeof(card_t) * i);
    carden[1].pos.x = 600, carden[1].pos.y = 150;
    carden[1].save.x = 600, carden[1].save.y = 150;
    carden[1].filepath = "pic/minions/senjin.jpg", carden[1].name = "senjin";
    carden[1].pv = 5, carden[1].attack = 3, carden[1].cost = 4;
    carden[1].shield = false, carden[1].provoc = true;

    card[2].filepath = NULL;
    carden[2].filepath = NULL;
    my_game(window, card, carden);
}

int reset(sfRenderWindow *window)
{
    char *str = malloc(sizeof(char) * 2);
    my_name(window, str, 0);
    choose_card(window, str);
    return (0);
}

int main()
{
    sfRenderWindow *window;
    char *str = malloc(sizeof(char) * 2);
    sfEvent event;
    sfVideoMode video_m = {1080, 650, 32};
    window = sfRenderWindow_create(video_m, "Hs", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 90);
    sfRenderWindow_clear(window, sfBlack);
    my_name(window, str, 0);
    choose_card(window, str);
}