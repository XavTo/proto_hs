/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

int check_press(sfRenderWindow *window, sfEvent event)
{
    if (event.mouseMove.y >= 100 && event.mouseMove.y <= 170) {
        if (event.mouseButton.y >= 450 && event.mouseButton.y <= 530) {}
    }
    if (event.mouseMove.y >= 370 && event.mouseMove.y <= 440) {
        if (event.mouseButton.y >= 450 && event.mouseButton.y <= 530) {}
    }
}

card_t create_minion(card_t card, sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *back = sfTexture_createFromFile("pic/plateau1.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.63, 0.63};
    sfVector2f p = {-50, 0};
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfSprite_scale(my_spr, size);
    sfSprite_setPosition(my_spr, p);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) check_press(window, event);
        }
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        sfRenderWindow_display(window);
    }
    return (card);
}