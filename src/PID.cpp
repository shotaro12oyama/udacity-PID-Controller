#include "PID.h"
#include <random>
#include <numeric>
#include <math.h>
#include <iostream>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
    Kp = kp;
    Ki = ki;
    Kd = kd;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    std::cout << "d_error = " << d_error << "i_error = " << i_error << "p_error = " << p_error << std::endl;
}

double PID::TotalError() {
    return fabs(Kp * p_error + Kd * d_error + Ki * i_error);
}


void PID::SetCoef(double kp, double ki, double kd) {
    Kp = kp;
    Ki = ki;
    Kd = kd;
}
