# 备忘录

## 第一次安装

```
brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc@7
brew install dfu-programmer
brew install gcc-arm-none-eabi
brew install avrdude
```

```
brew install teensy_loader_cli
```

## 编译生成 HEX 文件

```
// make __KEYBOARD_NAME__-__KEYMAP_NAME__
make ergodox_ez-dddrop_dev
```

## 烧制

```
teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_.hex
```
