//
// Created by milesosborne on 8/19/24.
//

#ifndef ESE5180_GPIO_H
#define ESE5180_GPIO_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define REG_SIZE_IN_BYTES 4
#define LOW 0
#define HIGH 1
#define MAX_PIN_NUMBER 31
#define MIN_PIN_NUMBER 0

#define GPIO_PIN_0      0
#define GPIO_PIN_1      1
#define GPIO_PIN_2      2
#define GPIO_PIN_3      3
#define GPIO_PIN_4      4
#define GPIO_PIN_5      5
#define GPIO_PIN_6      6
#define GPIO_PIN_7      7
#define GPIO_PIN_8      8
#define GPIO_PIN_9      9
#define GPIO_PIN_10     10
#define GPIO_PIN_11     11
#define GPIO_PIN_12     12
#define GPIO_PIN_13     13
#define GPIO_PIN_14     14
#define GPIO_PIN_15     15
#define GPIO_PIN_16     16
#define GPIO_PIN_17     17
#define GPIO_PIN_18     18
#define GPIO_PIN_19     19
#define GPIO_PIN_20     20
#define GPIO_PIN_21     21
#define GPIO_PIN_22     22
#define GPIO_PIN_23     23
#define GPIO_PIN_24     24
#define GPIO_PIN_25     25
#define GPIO_PIN_26     26
#define GPIO_PIN_27     27
#define GPIO_PIN_28     28
#define GPIO_PIN_29     29
#define GPIO_PIN_30     30
#define GPIO_PIN_31     31

typedef enum
{
    INPUT,
    OUTPUT
}pin_type;

typedef enum
{
    PUSH_PULL,
    OPEN_DRAIN
}output_mode_cfg;

typedef enum
{
    PULL_DOWN,
    PULL_UP
}input_mode_cfg;


// NOTE: Assuming 32-bit address space for all target platforms.
typedef struct
{
    uint32_t* pin_type_config;
    uint32_t* output_data_register;
    uint32_t* output_mode_config;
    uint32_t* pull_up_pull_down_config;
    uint32_t* input_data_register;
}gpio_port;

void gpio_init(gpio_port* port_cfg);
void gpio_enable_port(gpio_port* port_cfg);
void gpio_set_pin_type(gpio_port* port_cfg, uint8_t pin, pin_type type);
void gpio_set_input_mode(gpio_port* port_cfg, uint8_t pin, input_mode_cfg modeCfg);
void gpio_set_output_mode(gpio_port* port_cfg, uint8_t pin, output_mode_cfg modeCfg);
void gpio_set_output_pin(gpio_port *port_cfg, uint8_t pin);
void gpio_clear_output_pin(gpio_port *port_cfg, uint8_t pin);
void gpio_read_pin(void);


#endif //ESE5180_GPIO_H
