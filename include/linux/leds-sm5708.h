/*
 * Flash-LED device driver for SM5708
 *
 * Copyright (C) 2015 Silicon Mitus
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef __LEDS_SM5708_H__
#define __LEDS_SM5708_H__

#include <linux/leds/msm_ext_pmic_flash.h>

#define __MANGLE_NAME(_f_) _f_##_sm5708

enum {
	SM5708_FLED_0   = 0x0,
	SM5708_FLED_1,
	SM5708_FLED_MAX,
};

struct sm5708_fled_platform_data {
	struct {
		unsigned short flash_current_mA;
		unsigned short torch_current_mA;
		unsigned short preflash_current_mA;
		bool used_gpio;
		int flash_en_pin;
		int torch_en_pin;
	} led[SM5708_FLED_MAX];
};

int sm5708_fled_prepare_flash(unsigned char index);
int sm5708_fled_torch_on(unsigned char index);
int sm5708_fled_flash_on(unsigned char index);
int sm5708_fled_preflash(unsigned char index);
int sm5708_fled_led_off(unsigned char index);
int sm5708_fled_torch_set_current(unsigned char index, int current_ma);
int sm5708_fled_turn_on_only_torch(unsigned char index);



// For msm_led_trigger
int sm5708_fled_torch_on(unsigned char index);
int sm5708_fled_flash_on(unsigned char index);
int sm5708_fled_preflash(unsigned char index);

int sm5708_fled_led_off(unsigned char index);
int sm5708_fled_muic_camera_flash_work_on(void);
int sm5708_fled_muic_camera_flash_work_off(void);
int sm5708_fled_pre_flash_on(unsigned char index, int32_t pre_flash_current_mA);
int sm5708_fled_flash_on_set_current(unsigned char index, int32_t flash_current_mA);

// For msm_flash
int msm_fled_led_off_sm5708(ext_pmic_flash_ctrl_t *flash_ctrl);
int msm_fled_torch_on_sm5708(ext_pmic_flash_ctrl_t *flash_ctrl);
int msm_fled_flash_on_sm5708(ext_pmic_flash_ctrl_t *flash_ctrl);
int msm_fled_pre_flash_on_sm5708(ext_pmic_flash_ctrl_t *flash_ctrl);
int msm_fled_flash_on_set_current_sm5708(ext_pmic_flash_ctrl_t *flash_ctrl);

#endif
