# CS205 C/ C++ Programming - Lab Assignment1

> Name: 黄玉安(Huang Yu'an)

> SID: 11610303

### Part 1 - Analysis

Given two place's latitude and longitude: lat1, lon1, lat2, lon2.

First calculate `phi = 90 - latitude` and `theta = longitude`, pay attention to change angle angle to radian.

Then use the formula to calculate the distance between them:

 $d = R*Arccos(c)$ 

which c is calculated by 

$c = sin(phi1)*sin(phi2)*cos(theta1-theta2) + cos(phi1)*cos(phi2)$ 

and R is the radius of earth (6371km).

### Part 2 - Code



### Part 3 - Result & Verification





### Part 4 - Difficulties & Solutions

We should notice the new line problem in cin, so use cin.ignore()

