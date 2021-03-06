/**********************************************************************
    ENCE260 Assignment

    Joshua, WYLLIE - jwy31
    Man On, LAI    - mla134
**********************************************************************/

#ifndef TRON_H
#define TRON_H

#include "system.h"
#include "tinygl.h"

#define LIGHTBIKE_INC 1
#define LIGHTBIKE_MOVE_PERIOD 200
#define LIGHTBIKE_SNAKE_LEN 4
#define LIGHTBIKE_DONT_DISPLAY 111


typedef enum
{
    UP, DOWN, LEFT, RIGHT
} direction_t;

typedef enum
{
    NEITHER, CONTROLER, LISTNER, BOTH
} which_bike_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
} position_t;

typedef struct
{
    position_t pos;
    uint8_t value;
} pixel_t;

typedef struct
{
    uint16_t move_period;
    uint16_t move_clock;
} tron_timer;

typedef struct
{
    direction_t direction;
    direction_t last_direction;
    position_t position;
    pixel_t snake[8];
    tron_timer timer;
} tron_lightbike_t;

void tron_init(tron_lightbike_t*, direction_t, position_t);

void tron_set_lightbike_dir(tron_lightbike_t*, direction_t);

void tron_move_lightbike(tron_lightbike_t*);

which_bike_t tron_collision(tron_lightbike_t*, tron_lightbike_t*);

void tron_update(tron_lightbike_t*);

#endif
