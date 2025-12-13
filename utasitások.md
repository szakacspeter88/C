#1. Felrakod a csomagokat:

```
sudo pacman -S alsa-lib pipewire-alsa
```

#2. Lefordítod a forráskódot:
```
gcc beep.c -o beep -lasound -lm
```

#3. Futtatod:
```
./beep
```

1. Ezek a csomagok elvileg már fent vannak nálad:
```
sudo pacman -S pipewire pkgconf base-devel
```

2. Így tudod fordítani:
```
gcc -o beep beep.c $(pkg-config --cflags --libs libpipewire-0.3) -lm
```

3. Majd futtatás:
```
./beep
```
