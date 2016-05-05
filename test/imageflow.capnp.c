#include "imageflow.capnp.h"
/* AUTO GENERATED - DO NOT EDIT */

Crop_ptr new_Crop(struct capn_segment *s) {
	Crop_ptr p;
	p.p = capn_new_struct(s, 16, 0);
	return p;
}
Crop_list new_Crop_list(struct capn_segment *s, int len) {
	Crop_list p;
	p.p = capn_new_list(s, len, 16, 0);
	return p;
}
void read_Crop(struct Crop *s, Crop_ptr p) {
	capn_resolve(&p.p);
	s->x1 = capn_read32(p.p, 0);
	s->x2 = capn_read32(p.p, 4);
	s->y1 = capn_read32(p.p, 8);
	s->y2 = capn_read32(p.p, 12);
}
void write_Crop(const struct Crop *s, Crop_ptr p) {
	capn_resolve(&p.p);
	capn_write32(p.p, 0, s->x1);
	capn_write32(p.p, 4, s->x2);
	capn_write32(p.p, 8, s->y1);
	capn_write32(p.p, 12, s->y2);
}
void get_Crop(struct Crop *s, Crop_list l, int i) {
	Crop_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_Crop(s, p);
}
void set_Crop(const struct Crop *s, Crop_list l, int i) {
	Crop_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_Crop(s, p);
}

uint32_t Crop_get_x1(Crop_ptr p)
{
	uint32_t x1;
	x1 = capn_read32(p.p, 0);
	return x1;
}

uint32_t Crop_get_x2(Crop_ptr p)
{
	uint32_t x2;
	x2 = capn_read32(p.p, 4);
	return x2;
}

uint32_t Crop_get_y1(Crop_ptr p)
{
	uint32_t y1;
	y1 = capn_read32(p.p, 8);
	return y1;
}

uint32_t Crop_get_y2(Crop_ptr p)
{
	uint32_t y2;
	y2 = capn_read32(p.p, 12);
	return y2;
}

void Crop_set_x1(Crop_ptr p, uint32_t x1)
{
	capn_write32(p.p, 0, x1);
}

void Crop_set_x2(Crop_ptr p, uint32_t x2)
{
	capn_write32(p.p, 4, x2);
}

void Crop_set_y1(Crop_ptr p, uint32_t y1)
{
	capn_write32(p.p, 8, y1);
}

void Crop_set_y2(Crop_ptr p, uint32_t y2)
{
	capn_write32(p.p, 12, y2);
}

int main(){
	return 0;
}