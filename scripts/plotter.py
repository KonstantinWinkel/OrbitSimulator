#!/usr/bin/env python3

# Author: Konstantin Winkel

import glob
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import os
import pandas
import sys

if len(sys.argv) < 2:
    print("please specify a path to the .csv files")
    exit(-1)

path = sys.argv[1]
os.chdir(path)


def plotPositions():
    result = glob.glob('Position*.csv')

    if len(result) == 0:
        return

    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111, projection='3d')

    for file in result:
        points = pandas.read_csv(file)
        if file == "PositionEarth.csv":
            r = 6378000
            u, v = np.mgrid[0:2*np.pi:9j, 0:np.pi:9j]
            x = r * np.cos(u)*np.sin(v)
            y = r * np.sin(u)*np.sin(v)
            z = r * np.cos(v)
            ax.plot_wireframe(x, y, z, color='y')
        
        ax.plot3D(points['x'].values, points['y'].values, points['z'].values)

    lim = 1e7
    ax.axes.set_xlim3d(left   = -lim, right = lim)
    ax.axes.set_ylim3d(bottom = -lim, top   = lim) 
    ax.axes.set_zlim3d(bottom = -lim, top   = lim)

    ax.set_box_aspect([1,1,1])
    plt.show()

def plotSpeeds():
    result = glob.glob('Speed*.csv')

    if len(result) == 0:
        return

    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111, )

    for file in result:
        points = pandas.read_csv(file)
        
        ax.plot(points['t'].values, points['v'].values,)

    plt.show()

def plotDistances():
    result = glob.glob('Distance*.csv')

    if len(result) == 0:
        return

    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111, )

    for file in result:
        points = pandas.read_csv(file)
        
        ax.plot(points['t'].values, points['s'].values,)

    plt.show()

plotPositions()
plotSpeeds()
plotDistances()