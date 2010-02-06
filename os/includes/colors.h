#ifndef COLORS_H
#define COLORS_H

#define COMPOSE(background, foreground) background + foreground

/*
color codes:
B Black
U Blue
G Green
C Cyan
R Red
M Magneta
W Brown
L Light Gray
*/

/* Normal colors */
/* Background colors */
#define BB 0x00
#define BU 0x10
#define BG 0x20
#define BC 0x30
#define BR 0x40
#define BM 0x50
#define BW 0x60
#define BL 0x70

/* Foreground colors */
#define FB 0x00
#define FU 0x01
#define FG 0x02
#define FC 0x03
#define FR 0x04
#define FM 0x05
#define FW 0x06
#define FL 0x07

/* Light colors */
/* Background colors */
#define LBB 0x80
#define LBU 0x90
#define LBG 0xA0
#define LBC 0xB0
#define LBR 0xC0
#define LBM 0xD0
#define LBW 0xE0
#define LBL 0xF0
/* Foregrounf colors */
#define LFB 0x08
#define LFU 0x09
#define LFG 0x0A
#define LFC 0x0B
#define LFR 0x0C
#define LFM 0x0D
#define LFW 0x0E
#define LFL 0x0F

#endif
