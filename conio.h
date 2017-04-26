#include <termios.h>
#include <stdio.h>

#define BIT(x) (0x01 < (x))
#define BIT_SET(x,y) ((x) |= (y))
#define BIT_CLEAR(x,y) ((x) &= (~(y)))
#define BIT_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK(x,y) (((x) & (y)) == (y))

const unsigned int FLAG_MASK = BIT(4);
const unsigned int UNCOVERED_MASK = BIT(5);
const unsigned int MINE_MASK = BIT(6);

void initTermios(int echo);

/* Restore old terminal i/o settings */
void resetTermios(void);

/* Read 1 character - echo defines echo mode */
char getch_(int echo);

/* Read 1 character without echo */
char getch(void);

/* Read 1 character with echo */
char getche(void);

unsigned int cell;

inline _Bool has_mine(unsigned int cell) {
        return BITMASK_CHECK(cell, MINE_MASK);
}

inline void put_mine(unsigned int cell) {
        BIT_SET(cell, MINE_MASK);
}
inline _Bool has_uncovered(unsigned int cell) {
        return BITMASK_CHECK(cell, UNCOVERED_MASK);
}

inline _Bool has_flag(unsigned int cell) {
        return BITMASK_CHECK(cell, FLAG_MASK);
}

inline void remove_flag(unsigned int cell) {
        BIT_CLEAR(cell, FLAG_MASK);
}

inline void uncovered(unsigned int cell) {
        BIT_SET(cell, UNCOVERED_MASK);
}

