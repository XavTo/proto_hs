/*
** EPITECH PROJECT, 2020
** runner
** File description:
** bottstrap
*/

#ifndef hs_h
#define hs_h

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int attack;
    int pv;
    int cost;
    bool provoc;
    bool shield;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f save;
    int i;
} card_t;

int display_card(sfRenderWindow *window, card_t *card, card_t *carden);
card_t *my_check_combat(sfRenderWindow *window, int i, int *a, card_t *card, card_t *carden1, card_t *carden2);

#endif