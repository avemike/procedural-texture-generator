## WIP: procedural texture generator

### Features Todo:
- [x] Turbulence
- [x] Clouds
  - [ ] Refactor HSL functions - make them work with 0..1 instead of 0..255
- [x] Marble
- [x] Wood
- [ ] Fix: saving file with padding
- [x] GTK

### Optional Todo:
- [ ] 3D Noise
    - [ ] .gif compatibility
- [ ] Elaborate on conventions
    - [ ] what I mean by pattern and texture
### Refactor Todo: 
- [ ] make indexer for RGB/HSL type
- [x] make modular noises
- [ ] put handlers in separate directory
- [ ] separate ui logic

### Conventions
- _Pattern_ is an array of values in type double in range 0..1. It helps with representing image pixel data in black and white.
- _Texture_ is an array of values in type RGB.
  - RGB is structure of unsigned chars { red, blue, green }