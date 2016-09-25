#ifndef _VDP_H_
#define _VDP_H_

#define vdp_txt 0
#define vdp_grp1 1
#define vdp_grp2 2
#define vdp_mult 3

#define vdp_trasnp	0
#define vdp_black 	1
#define vdp_green	2
#define vdp_lgreen	3
#define vdp_dblue	4
#define vdp_blue 	5
#define vdp_dred	6
#define vdp_lblue	7
#define vdp_red 	8
#define vdp_lred	9
#define vdp_yellow	10
#define vdp_lyellow	11
#define vdp_dgreen	12
#define vdp_magenta	13
#define vdp_grey	14
#define vdp_white	15

#define vdp_base_names_grp1     0x1800
#define vdp_base_color_grp1     0x2000
#define vdp_base_chars_grp1     0x0000
#define vdp_base_spatr_grp1     0x1b00
#define vdp_base_sppat_grp1     0x3800

#define vdp_hw_max_sprites      32
#define vdp_hw_max_patterns     255

struct vdp_hw_sprite {
	byte y;
	byte x;
	byte pattern;
	byte color;
};

extern void vdp_screen_disable(void);
extern void vdp_screen_enable(void);
extern void vdp_set_mode(char mode);
extern void vdp_set_color(char ink, char border);
extern void vdp_poke(uint address, byte value);
extern byte vdp_peek(uint address);
extern void vdp_memset(uint vaddress, uint size, byte value);
extern void vdp_copy_to_vram(byte * buffer, uint vaddress, uint length);
extern void vdp_copy_to_vram_di(byte * buffer, uint vaddress, uint length);
extern void vdp_copy_from_vram(uint vaddress, byte * buffer, uint length);
extern void vdp_set_hw_sprite(struct vdp_hw_sprite *spr, char spi);
extern void vdp_set_hw_sprite_di(byte * spr, uint spi);
extern void vdp_init_hw_sprites(char spritesize, char zoom);
extern void vdp_fastcopy_nametable(byte * buffer);
extern void vdp_fastcopy_nametable_di(byte * buffer);
extern void vdp_fastcopy16(byte * src_ram, uint dst_vram);
extern void vdp_clear_grp1(byte color);
extern void vdp_print_grp1(char x, char y, char *msg);

#endif