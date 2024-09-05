//
// Created by milesosborne on 8/19/24.
//

#include "GPIO.h"


void gpio_init(gpio_port *port_cfg) {
    /* Upon initialization, set each register to 0 */
    *port_cfg->pin_type_config = 0;
    *port_cfg->output_data_register = 0;
    *port_cfg->output_mode_config = 0;
    *port_cfg->pull_up_pull_down_config = 0;
    *port_cfg->input_data_register = 0;
}

void gpio_enable_port(gpio_port *port_cfg) {
    /* Set each pin to output mode (pin_type_config) */
    uint8_t pin_type_state =
            (OUTPUT << 0) | (OUTPUT << 1) | (OUTPUT << 2) | (OUTPUT << 3) |
            (OUTPUT << 4) | (OUTPUT << 5) | (OUTPUT << 6) | (OUTPUT << 7);

    memset(port_cfg->pin_type_config, pin_type_state, REG_SIZE_IN_BYTES);

    /* Set each output pin to push-pull config (output_mode_config) */
    memset(port_cfg->output_mode_config, PUSH_PULL, REG_SIZE_IN_BYTES);

    /* Set each output pin value to 0 (output_data_register) */
    memset(port_cfg->output_data_register, LOW, REG_SIZE_IN_BYTES);

    return;
}

void gpio_set_pin_type(gpio_port *port_cfg, uint8_t pin, pin_type type) {
    if (pin > MAX_PIN_NUMBER || pin < MIN_PIN_NUMBER) {
        return;
    }
    if (type == INPUT) {
        *port_cfg->pin_type_config &= ~(1 << pin);
    } else if (type == OUTPUT) {
        *port_cfg->pin_type_config |= (1 << pin);
    } else {
        return;
    }
}

void gpio_set_input_mode(gpio_port* port_cfg, uint8_t pin, input_mode_cfg modeCfg)
{
    if (pin > MAX_PIN_NUMBER || pin < MIN_PIN_NUMBER) {
        return;
    }

    if (modeCfg == PULL_UP)
    {
        *port_cfg->pull_up_pull_down_config |= (1 << pin);
    }

    if (modeCfg == PULL_DOWN)
    {
        *port_cfg->pull_up_pull_down_config &= ~(1 << pin);
    }

}

void gpio_set_output_mode(gpio_port* port_cfg, uint8_t pin, output_mode_cfg modeCfg) {
    if (pin > MAX_PIN_NUMBER || pin < MIN_PIN_NUMBER) {
        return;
    }

    if (modeCfg == OPEN_DRAIN)
    {
        *port_cfg->output_mode_config |= (1 << pin);
    }

    if (modeCfg == PUSH_PULL)
    {
        *port_cfg->output_mode_config &= ~(1 << pin);
    }
}

void gpio_set_output_pin(gpio_port *port_cfg, uint8_t pin) {
    if (pin > MAX_PIN_NUMBER || pin < MIN_PIN_NUMBER) {
        return;
    }
    *port_cfg->output_data_register |= (1 << pin);
}

void gpio_clear_output_pin(gpio_port *port_cfg, uint8_t pin)
{
    if (pin > MAX_PIN_NUMBER || pin < MIN_PIN_NUMBER) {
        return;
    }
    *port_cfg->output_data_register &= ~(1 << pin);
}

void gpio_read_pin(void) {
    return;
}