/*
** EPITECH PROJECT, 2020
** my_hs
** File description:
** first
*/

#include "hs.h"

int my_swap(card_t *card1, card_t *card2)
{
    card_t swap;

    swap = *card1;
    *card1 = *card2;
    *card2 = swap;
}

card_t *my_attack(sfRenderWindow *window, card_t *card, card_t *carden1, card_t *carden2)
{
    int i = 0;
    while (card[i].name != NULL) {
        if (card[i].pos.x >= carden1->pos.x - 100 && card[i].pos.x <= carden1->pos.x + 100
            && card[i].pos.y >= carden1->pos.y - 120 && card[i].pos.y <= carden1->pos.y + 130) {
            if (carden2->provoc == true) {
                printf("you can't attack this minios, another one got provocation\n");
                break;
            }
            if (card[i].shield == true) card[i].shield = false;
            else card[i].pv = card[i].pv - carden1->attack;
            carden1->pv = carden1->pv - card[i].attack;
            if (card[i].pv <= 0) card[i].name = NULL, carden1->provoc = false;
            if (carden1->pv <= 0) {
                if (carden1->name == NULL) carden1->name = NULL;
                else my_swap(carden1, carden2), carden2->name = NULL;
            }
        }
        if (card[i].pos.x >= carden2->pos.x - 100 && card[i].pos.x <= carden2->pos.x + 100
            && card[i].pos.y >= carden2->pos.y - 120 && card[i].pos.y <= carden2->pos.y + 130) {
                if (carden1->provoc == true) {
                printf("you can't attack this minios, another one got provocation\n");
                break;
            }
            if (card[i].shield == true) card[i].shield = false;
            else card[i].pv = card[i].pv - carden2->attack;
            carden2->pv = carden2->pv - card[i].attack;
            if (card[i].pv <= 0) {
                if (card[i + 1].name == NULL) card[i].name = NULL;
                else my_swap(&card[i], &card[i + 1]), card[i + 1].name = NULL;
            }
            if (carden2->pv <= 0) carden2->name = NULL, carden2->provoc = false;
        }
        i++;
    }
    return (card);
}

card_t *my_check_combat(sfRenderWindow *window, int i, int *a, card_t *card, card_t *carden1, card_t *carden2)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && 
        (sfMouse_getPositionRenderWindow(window).x - 100 <= card[i].pos.x && sfMouse_getPositionRenderWindow(window).x + 10 >= card[i].pos.x) &&
        (sfMouse_getPositionRenderWindow(window).y - 150 <= card[i].pos.y && sfMouse_getPositionRenderWindow(window).y >= card[i].pos.y)) {
        card[i].pos.x = sfMouse_getPositionRenderWindow(window).x - 50;
        card[i].pos.y = sfMouse_getPositionRenderWindow(window).y - 80;
        *a = 1;
    }
    if (*a == 1 && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        card[i].pos.x = sfMouse_getPositionRenderWindow(window).x - 50;
        card[i].pos.y = sfMouse_getPositionRenderWindow(window).y - 80;
    }
    else if (*a == 1) {
        card = my_attack(window, card, carden1, carden2), card[i].pos.x = card[i].save.x, card[i].pos.y = card[i].save.y, *a = 0;
    }
    return (card);
}