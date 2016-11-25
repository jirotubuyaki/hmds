---
title: "hmds: An R Package for Heuristic High and Multi Dimensional Scaling"
tags:
  - R
  - Rcpp
  - Multi-Dimensional Scaling(MDS)
  - Clustering
  - Heuristic
authors:
 - name: Masashi Okada
   orcid: 0000-0000-0000-0000
   affiliation: Okada Algorithm Private Invention Research Laboratory
date: 24 November 2016
bibliography: paper.bib
---
# Summary
Multi-Dimensional Scaling(MDS)[@Carroll1980] is a statistical method in order to put objects at coordinates. If the similarities or distances between two objects are given, MDS can put objects into two or three dimensional coordinate space. In this package, I propose a heuristic in order to calculate coordinates in high dimensional space from the data of similarities or distances between two objects. The heuristic calculates approximate coordinates in the dimensions given by user. And if the similarities or distances have contradiction in metric space, the method can calculate approximate coordinates. And several important methods like Clustering [@Liu2007] and Data Visualization [@Ben2007] require coordinates in high dimensions. And the heuristic acts as follows. First of all, the heuristic randomly puts the objects in the high dimensional space. The number of dimensions is given by user. Then the distances between two objects are compared with the given data in turns. If the distance is longer than the distance of two objects in the data, the distances is made shorter by moving the objects in coordinate space. If the distance is shorter than the data, the distance is made longer. The iteration continues until the sum of distances is less than an approximate rate. And if the sum of distances is not less than the rate, the program exits by the limit of iteration count. As a result, approximate coordinate points of all objects are acquired.

# References
