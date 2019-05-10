# AMJ60
AMJ60 Keyboard tmk firmware

# Customizations
- keymap: [src/keymap_customized.c](src/keymap_customized.c)
- bin: [AMJ60_lufa.hex](AMJ60_lufa.hex)

## Flash Commands
Use [dfu-programmer](https://github.com/dfu-programmer/dfu-programmer) project. After "reset":
1. `dfu-programmer atmega32u4 erase --force`
1. `dfu-programmer atmega32u4 flash AMJ60_lufa.hex`
1. `dfu-programmer atmega32u4 launch`
