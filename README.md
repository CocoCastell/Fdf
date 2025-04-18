# About Fdf

This project is about representing a landscape as a 3D object in which all  
surfaces are outlined in lines. The use of the graphical library MiniLibX is asked.  

# How to run

First compile in the directory with  
```
make
```

Then run the programm with one map argument  
```
./fdf test_maps/pyramid.fdf  
```
# Implementation

- MiniLibX tools: pixel are stored in a buffer (image) and then the buffer is sent to the window.

- Breshenham algorithm to draw the lines.

- Isometric and oblic view algorithm.

- 2 types of gradient: one continous from both height extremities and the other one
  changing color when reaching a new level. I used linear interpolation.

- Trigonometric functions for rotations on 3 axis.

- Temporary and permanent translation.

- Menu, zoom and different color themes.

# Grade

✅ 125/100

# Results

![Screeshot](./assets/Fdf-T1.png)  

![Screenshot](./assets/Fdf-42.png)  

![Gif](./assets/Fdf-Pyramid.gif)  

# Ressources

https://www.youtube.com/watch?v=CceepU1vIKo  
https://harm-smits.github.io/42docs/libs/minilibx

