# A simple and easy to use Orbit Simulator

Author: Konstantin Winkel

## Description

This library provides a simple way of simulating gravity based systems like orbits. It provides utility to observe objects and relations between objects and control how these objects behave in the form of easy to use template classes.

For detailed documentation of all classes, methods and constants provided please consult the wiki [here]()

## Building and Installation

After cloning the repository simly run the script `build.sh` to build the library. If you wish to install the lib file and header files to your maschine (for example to use it in your own projects) run the script `build-and-install.sh`.

Some Examples are also provided to show the library in action. To build them add the parameter `-DBUILD_EXAMPLES=ON` to either of the scripts.

The commands below show how to clon, fully install the library and build the examples

```bash
git clone https://github.com/KonstantinWinkel/OrbitSimulator
cd OrbitSimulation
./scripts/build-and-install.sh -DBUILD_EXAMPLES=ON
```

## Executing the examples and plotting the results

To execute an example, e.g. `01-Simple-Orbit`, simply run the executable created by the build scripts. This will create some `.csv` files that contain the results of the simulation. To plot the results use the python script provided in the `scripts` directory. Make sure to give the path to the folder containing the `.csv` files.

```bash
cd build
./01-Simple-Orbit
./../scripts/plotter.py .
```

## Future Work

Any feature suggestions or improvements are welcome.

While the python script does provide a simple way to plot the results of a simulation, in the future a GUI system will be built to show the results in a more clear way and to set up simulations on the fly.
