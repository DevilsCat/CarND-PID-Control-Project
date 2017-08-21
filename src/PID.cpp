#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(): 
  int_errors_(0.0f),
  prev_cte_(0.0f),
  p_error(0.0f), 
  i_error(0.0f), 
  d_error(0.0f)
{}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  // Update P error
  p_error = -Kp * cte;
  
  // Update I error
  int_errors_ += cte;
  i_error = -Ki * int_errors_;

  // Update D error
  d_error = -Kd * (cte - prev_cte_);
  prev_cte_ = cte;
}

double PID::TotalError() {
  return p_error + i_error + d_error;
}

