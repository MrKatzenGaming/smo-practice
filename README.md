# Practice Mod

This is a mod for Super Mario Odyssey that adds different features that intend to aid in speedrun practice (but can also be used for other reasons)
### Features
- Position saving and restoring
- Moon refreshing
- Toggle Autosaving on/off
- Stage warping
- Info display (player position, velocity, speed, etc.)
- Other small features

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Building

Build has only been tested on WSL2 running Ubuntu 20.04.1.

Just run:
```
DEVKITPRO={path_to_devkitpro} make
```

On Ubuntu (and other Debian-based systems), devkitPro will be installed to `/opt/devkitpro` by default:

```
DEVKITPRO=/opt/devkitpro/ make
```

## Installing (Atmosphère)

After a successful build, transfer:

- `smo-practice100.elf` to `/atmosphere/contents/0100000000010000/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips` to `/atmosphere/exefs_patches/starlight_patch_100/3CA12DFAAF9C82DA064D1698DF79CDA1.ips`
- `romfs` to `/atmosphere/contents/0100000000010000/romfs`

# Credits
- CraftyBoss - [work on TextWriter](https://github.com/CraftyBoss/Starlight-SMO-LayoutEditing)
- bryce_____ - [Example](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example)
- devkitA64
- libnx - switch build rules