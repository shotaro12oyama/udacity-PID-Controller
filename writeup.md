## PID Controller Project Writeup ##

**PID Controller Project**
In this project, I implemented PID Controller, in order to drive a car in the simulator. 


----
### PID controller implementation overview ###

I adapted the feadback of PID controller (proportional, integral and derivative influence) for cross track error (CTE) value.
For every sampling step by simulator,
** update each error value (#27-32, UpdateError function in PID.cpp)
** calcurate each coefficient and optimize them by twiddle approach (#68-88, in main.cpp)
** based on the errors and co efficients above, calculate steering value (#91-95, in main.cpp)
** To make more steering comfortable, I set steering value = 0, when CTE value is not large. twiddle approach also make the steering angle smaller.


### the effect of the P, I, D component of the PID algorithm in their implementation ###

A video of the simulated car driving around the track can be found [here.](https://github.com/mvirgo/PID-Control-Project/blob/master/project_video.mov)
Visual aids are encouraged, i.e. record of a small video of the car in the simulator and describe what each component is set to.

Please include in your writeup a description of the the effect of the P, I, D component of the PID algorithm in your implementation. Thanks!

Hint: Note that in general P cause the car to move toward the reference trajectory but will overshoot and cause oscillations, d helps to combat oscillations and i helps to combat bias. You could try various type of controllers (P. PD, and PID) to lay down the impact of each of the components.




### how to choose the final hyperparameters (P, I, D coefficients). 

I chose the final hyperparameters by the following way.
** Try several P coefficient and find the one which has appropriate speed of oscillations
** Try several D coefficient in order to mitigate the oscillations caused by the P coefficient above
** Try several I coefficient in order to mitigate the 
** 

In addtion to the above, 
