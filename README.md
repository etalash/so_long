# So_Long Project – 42 School

This repository contains my **So_Long** project from 42 School. The project focuses on learning **basic 2D game development**, event-driven programming, and using **MLX42** for graphics and window management.

---

## So_Long – 2D Game Project

`So_Long` is a simple 2D game where the player navigates a map, collects items, and reaches the exit while avoiding obstacles.

### Overview

The project teaches **game logic implementation, map parsing, and event handling**.

### Features

* 2D grid-based map navigation
* Player movement and collision detection
* Collectibles and exit mechanics
* Dynamic map parsing from `.ber` files
* Window rendering using **MLX42**
* Key event handling for player input

### Controls

| Key   | Action            |
| ----- | ----------------- |
| W / S | Move up / down    |
| A / D | Move left / right |
| ESC   | Exit game         |

### Map Rules

* Maps must be **fully enclosed by walls** (`1`)
* Valid characters:

  * `0` — empty space
  * `1` — wall
  * `C` — collectible
  * `E` — exit
  * `P` — player starting position
* Exactly **one player start** and at least **one exit** required
* Any invalid map = program exits with error

### Installation & Build

```bash
git clone <repo-url>
cd so_long
make
./so_long maps/<map>.ber
```

### Notes

* Focuses on integrating **graphics, event handling, and game logic**.
* Teaches map validation, collision handling, and basic game loop design.

---

## Languages

* C — 96.6%
* Makefile — 3.4%
