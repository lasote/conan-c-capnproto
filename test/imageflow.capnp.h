#ifndef CAPN_971BCC4AFCC2D821
#define CAPN_971BCC4AFCC2D821
/* AUTO GENERATED - DO NOT EDIT */
#include <capnp_c.h>

#if CAPN_VERSION != 1
#error "version mismatch between capnp_c.h and generated code"
#endif


#ifdef __cplusplus
extern "C" {
#endif

struct Crop;

typedef struct {capn_ptr p;} Crop_ptr;

typedef struct {capn_ptr p;} Crop_list;

struct Crop {
	uint32_t x1;
	uint32_t x2;
	uint32_t y1;
	uint32_t y2;
};

static const size_t Crop_word_count = 2;

static const size_t Crop_pointer_count = 0;

static const size_t Crop_struct_bytes_count = 16;

uint32_t Crop_get_x1(Crop_ptr p);

uint32_t Crop_get_x2(Crop_ptr p);

uint32_t Crop_get_y1(Crop_ptr p);

uint32_t Crop_get_y2(Crop_ptr p);

void Crop_set_x1(Crop_ptr p, uint32_t x1);

void Crop_set_x2(Crop_ptr p, uint32_t x2);

void Crop_set_y1(Crop_ptr p, uint32_t y1);

void Crop_set_y2(Crop_ptr p, uint32_t y2);

Crop_ptr new_Crop(struct capn_segment*);

Crop_list new_Crop_list(struct capn_segment*, int len);

void read_Crop(struct Crop*, Crop_ptr);

void write_Crop(const struct Crop*, Crop_ptr);

void get_Crop(struct Crop*, Crop_list, int i);

void set_Crop(const struct Crop*, Crop_list, int i);

#ifdef __cplusplus
}
#endif
#endif
