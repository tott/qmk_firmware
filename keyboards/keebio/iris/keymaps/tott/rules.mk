# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

ENCODER_ENABLE = yes
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
UNICODE_ENABLE = yes         # Unicode
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
SPLIT_KEYBOARD = yes
