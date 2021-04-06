/*
Cai Hui Yang
*/
#include "Customer.hpp"

Customer::Customer() {}

Customer::Customer(string name, string device, int wait_time){
  name_ = name;
  defective_device_ = device;
  wait_time_= wait_time;
} // end of func

string Customer::getName(){
  return name_;
} // end of func

string Customer::getDevice(){
  return defective_device_;
} // end of func

int Customer::getWaitTime(){
  return wait_time_;
} // end of func

void Customer::updateWaitTime(int new_wait_time){
  wait_time_ = new_wait_time;
} // end of func
