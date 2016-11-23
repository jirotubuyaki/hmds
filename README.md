# hmds: An R Package for Heuristic High and Multi Dimensional Scaling

## Abstract
In this document, I propose the heuristic to calculate the coordinates in high dimensions. If the similarities or distances between two points and dimensions in the space are given, this heuristic calculates approximate coordinates in high dimensions. And if the similarities or distances have a contradict in metric space, the method calculates approximate coordinates. Its coordinates are available for lots of analysis. This heuristic proposed by R package.

## Introduction
Multi-Dimensional Scaling(MDS)[@Borg2005] is a statistical method in order to put points at coordinates. If the similarities or distances between the two points are given, MDS can put the data into two or three dimensional coordinate space. In this package, I proposed a heuristic in order to calculate coordinates in high dimensional space from the data of similarities or distances between two points. This heuristic calculates approximate coordinates in the dimensions given by user. And if the similarities or distances have a contradict in metric space, the method calculates approximate coordinates. And several important methods like Clustering[@Liu2007], Nearest Neighbor Search[@Zezula2006] and Data Visualization[@Ben2007] require coordinates in high dimensions as coordinate space. And this heuristic acts as follows. First of all, this program randomly puts the points in the high dimensional space. Its dimensions  are given by user. Then distances between two points compare with the given data in turns. If distances are longer than the data, the distances is made shorter by moving coordinates. If distance is shorter than the data, the distance is made longer. This iteration continues until the sum of distances becomes smaller than approximate rate or a limit of iteration. As a result, an approximate coordinate points in all data are acquired.

## Installation
If download from Github you can use devtools by the commands:

```
> library(devtools)
> install_github("jirotubuyaki/hmds")
```

Once the packages are installed, it needs to be made accessible to the current R session by the commands:

```
> library(hmds)
```

For online help facilities or the details of a particular command (such as the function hmds) you can type:

```
> help(package="hmds")
```
##Method
This pakage has only one method. And it is excused by:

```
> output <- hmds(data = input, dim=20, approx=1.2, itera=10000)
```

Let's args be

* data is a numeric symmetric matrix of input data. it describe the distance between two points.
* dim describe dimensions of distance space between two points.
* approx is approximate rate of difference between input distance and output distanced. If the difference between input and output are shorter than approximate rate, iterations are halt.
* itera is iteration numbers to search space between all each two points.

Then let's return be

* output is a numeric matrix of points in a distance space. row is items. col is dimensions.

##Data
This package includes a sample dataset. The dataset containing a matrix of similarity between two points. The dataset is generated by R. Please check the data like this:

```
> data(package="hmds")
```

##Conclusions
The heuristic for Multi Dimensional Scaling is described and explain how to use. This package can produce the approximate coordinates in high dimentions. And several improvements are planed. Please send suggestion and report bugs to okadaalgorithm@gmail.com.


## Acknowledgments
This activity would not have been possible without the support of my family and friends. To my family, thank you for lots of encouragement for me and inspiring me to follow my dreams. I am especially grateful to my parents, who supported me all aspects.  


##References
Borg, Groenen, I. 2005. “Modern Multidimensional Scaling.” Springer-Verlag.  
Fry, Ben. 2007. “Visualizing Data Exploring and Explaining Data with the Processing Environment.” O’Reilly
Media.  
Liu, Bingh. 2007. “Web Data Mining Exploring Hyperlinks, Contents, and Usage Data.” Springer-Verlag pp.
117-146,  
Zezula, Amato, P. 2006. “Similarity Search.” IEEE Transactions on Pattern Analysis and Machine Intelligence.  
