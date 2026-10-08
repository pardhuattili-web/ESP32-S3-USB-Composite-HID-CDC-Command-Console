#pragma once
#include <stdint.h>
typedef struct { uint8_t modifiers; uint8_t keycodes[6]; } hid_keyboard_report_t;
enum { HID_MOD_CTRL=1U<<1, HID_MOD_SHIFT=1U<<2, HID_MOD_ALT=1U<<3 };
void hid_keyboard_init(void);
int hid_keyboard_send(const hid_keyboard_report_t *report);
int hid_keyboard_release_all(void);
