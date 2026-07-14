# Chinese Lantern

A decorative 2D animation built with C and OpenGL/FreeGLUT, rendering a 
swinging Chinese lantern with a layered glow effect and gentle pendulum motion.

## Features
- Smooth swinging animation using sinusoidal rotation for natural pendulum motion
- Layered "glow" effect achieved by drawing multiple semi-transparent concentric circles
- Lantern body rendered as a procedurally generated polygon circle
- Simple tail/string element drawn with `GL_LINES`
- Double-buffered rendering for flicker-free animation

## Tech Stack
- **Language:** C
- **Graphics:** OpenGL, FreeGLUT

## How to Build & Run

### Linux
```bash
sudo apt-get install freeglut3-dev
gcc main.cpp -o chinese_lantern -lGL -lGLU -lglut -lm
./chinese_lantern
```

### Windows (MinGW)
```bash
gcc main.cpp -o chinese_lantern.exe -lfreeglut -lopengl32 -lglu32
chinese_lantern.exe
```

## Technical Highlights
- Circle geometry generated manually via trigonometric vertex calculation 
  (`GL_POLYGON`, 100 segments) for smooth curves
- Glow effect built by layering multiple translucent circles of increasing 
  radius rather than using a texture or shader
- Swing motion driven by `sinf()` applied to rotation angle, creating smooth 
  oscillation without linear interpolation artifacts
- Matrix stack (`glPushMatrix` / `glPopMatrix`) used to isolate lantern 
  transformations from the rest of the scene
