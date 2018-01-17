## PID Controller Project Writeup ##

**PID Controller Project**
In this project, I implemented PID Controller, in order to drive a car in the simulator. 

----
### PID controller implementation overview ###

I adapted the PID controller (proportional, integral and derivative influence) for cross track error (CTE) value.
For every sampling step by simulator, I set the following steps.
* update each error value (#27-32, UpdateError function in PID.cpp)
* calcurate each coefficient and optimize them by twiddle approach (#68-88, in main.cpp)
* based on the errors and co efficients above, calculate steering value (#91-95, in main.cpp)

Also, I added throttle adjustment when cte is large.


### the effect of the P, I, D component of the PID algorithm in their implementation ###

A video of the resule of my project can be found [here.](https://github.com/shotaro12oyama/udacity-PID-Controller/blob/master/project_video.mov)

* The "P" component will steer the car in proportion to CTE. If I set P larger, then the response of the steering become faster, but it cause faster oscillation.

* The "I" component is integral sums up all CTEs up to that point. Depending on the situation, it is likely the car drives on one side of the lane, so it can be mitigated with feedback based on I. But if I is too large, car has faster oscillations. If I is too small, car will be kept on one side of the lane.

* The "D" component is derivate is the change in CTE from one value to the next. If the derivative is quickly changing, D will make steering faster. But if the car is moving toward the center, D will make steering smoother. If I set D larger, the steering_angle got changed very frequently, though the car will be well-centered. If D is smaller, the car will keep oscillation. 


### how to choose the final hyperparameters (P, I, D coefficients). 

I chose the final hyperparameters by the following way.
* Try several P coefficient and find the one which has appropriate speed of oscillations
* Try several I coefficient in order to the car can keep center lane.
* Try several D coefficient in order to mitigate the oscillations caused by the P coefficient above
* I implemented Twiddle approach to optimise coefficient on each occasion.

Finally, I initially set each coefficients as (P, I, D) = (0.4, 0.000001, 6.0), and Twiddle.