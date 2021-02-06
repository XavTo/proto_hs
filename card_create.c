/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

int draw_text(card_t card, sfRenderWindow *window)
{
    char *str = malloc(sizeof(char) * 3);
    int *status = malloc(sizeof(int) * 4);
    int i = 0;
    sfVector2f stat = {card.pos.x + 18, card.pos.y + 112};
    sfVector2f newpos;
    sfVector2f pos = card.pos;
    sfFont* font = sfFont_createFromFile("font/font.ttf");
    sfText* text = sfText_create();
    sfFont* bonus = sfFont_createFromFile("font/font.ttf");
    sfText* other = sfText_create();
    status[0] = card.pv, status[1] = card.attack, status[2] = card.cost;

    while (i != 3) {
        str[0] = status[i] + 48, str[1] = '\0';
        if (status[i] > 9)
            str[0] = '0' + status[i] / 10, str[1] = '0' + status[i] % 10, str[2] = '\0';
        sfText_setColor(text, sfWhite);
        sfText_setColor(other, sfBlack);
        sfText_setString(text, str);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 30);
        if (i == 0) {
            newpos.x = pos.x + 85, newpos.y = pos.y + 120;
            if (card.shield == true) {
                sfText_setCharacterSize(other, 11);
                sfText_setString(other, "divine shield");
                sfText_setFont(other, bonus);
                sfText_setPosition(other, stat);
                sfRenderWindow_drawText(window, other, NULL);
            }
            if (card.provoc == true) {
                sfText_setCharacterSize(other, 11);
                sfText_setString(other, "provocation");
                sfText_setFont(other, bonus);
                sfText_setPosition(other, stat);
                sfRenderWindow_drawText(window, other, NULL);
            }
        }
        if (i == 1) newpos.x = pos.x + 5, newpos.y = pos.y + 120;
        if (i == 2) newpos.x = pos.x + 5, newpos.y = pos.y + 5;
        sfText_setPosition(text, newpos);
        sfRenderWindow_drawText(window, text, NULL);
        i++;
    }
    free(status), free(str), sfText_destroy(text), sfFont_destroy(font);
}

int drawimg(char *str, sfRenderWindow *window, sfVector2f pos, card_t card)
{
    sfTexture *back = sfTexture_createFromFile(card.name, NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.1, 0.1};
    sfSprite_scale(my_spr, size);
    pos.x += 25, pos.y += 16;
    sfSprite_setPosition(my_spr, pos);
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

int display_card(sfRenderWindow *window, card_t *card, card_t *carden)
{
    int i = 0;
    sfTexture *back = sfTexture_createFromFile("pic/card_empty.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {0.4, 0.4};
    sfSprite_scale(my_spr, size);
    while (carden[i].name != NULL) {
        sfSprite_setPosition(my_spr, carden[i].pos);
        sfSprite_setTexture(my_spr, back, sfTrue);
        drawimg(carden[i].name, window, carden[i].pos, carden[i]);
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        draw_text(carden[i], window);
        i++;
    }
    i = 0;
    while (card[i].name != NULL) {
        sfSprite_setPosition(my_spr, card[i].pos);
        sfSprite_setTexture(my_spr, back, sfTrue);
        drawimg(card[i].name, window, card[i].pos, card[i]);
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        draw_text(card[i], window);
        i++;
    }
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}