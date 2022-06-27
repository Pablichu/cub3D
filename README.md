# Cub3d

Remember the old Wolfestein? Or the old Doom? Well, in this project you have to use the same method: *"raycastin"*

But it is mandatory to use the mlx library which works only in Mac because in 42 we develope in Macs. You could run this library in linux so I'll leave a link about it: 
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux

There are two versions that can be compiled: the mandatory and the bonus. For the mandatory just do "make", and for the bonus do "make bonus". Then you'll have the executable "cub3D". Be careful, the mandatory and bonus executable has the same name.
Now, the executable needs a path to a ".cub" that has all the information it needs. Feel free to check or even make your own "map.cub". Basically the files.cub have a resolution, textures path (bonus has roof and ceiling textures) and a map of 1 & 0. 1 are walls and 0 are floors. Every 0 has to be inside a 1 wall.
Now what's important: do "./cub3D 'path to .cub'" and then the game will start. Again, be careful with the version you are using:
- Mandatory maps do not work with bonus executable.
- Same logic the other way, bonus maps do not work with mandatory executable.
- Mandatory maps are located in maps/basic_maps.
- Bonus maps are located in maps/bonus.

Execute every map you want. But the real fun is in the bonus executable with "speedrun.cub" map. I recommend to play this map first.

# Controls
- 'W' to move forward.
- 'S' to move backward.
- 'A' to move left.
- 'D' to move right.
- Left arrow to rotate the camera to the left.
- Right arrow to rotate the camera to the right.

With bonus executable there is a _ship_ you can take. Wiht it, the movement system changes a little bit.
Have fun! And if you like it let me know!
