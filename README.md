# 42-FdF
An introduction project to the graphics branch @ 42.

Reads in a height map to generate a 3D model that the user can interact with!

This project will only work on MacOS El Capitan/Sierra/HighSierra(maybe) and even then, no promises! 

### Usage
After running `make` to generate the fdf executable you can run the program with `./fdf [valid_fdf_file]`.

A valid fdf file will consist of a matrix of number delimited by spaces. Each number's position represents an (x , y) coordinate with the value of the number itself representing a height (z).

Valid fdf files will always have the same number of elements per row.

Example fdf file:

![Example:](/screen/1m9uNoOMLSE.jpg)

### Output
The program will attempt to render the model described by the fdf file in a graphical window.

![Example:](/screen/42f.png)

