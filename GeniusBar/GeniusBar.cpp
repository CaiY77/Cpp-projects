/*
Cai Hui Yang
*/

#include "GeniusBar.hpp"


GeniusBar::GeniusBar() {
  number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
}

bool GeniusBar::addWaitingCustomer(Customer& new_customer){
  if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS){
    genius_bar_[number_of_customers_++] = new_customer;
    current_wait_time_ += WAIT_TIME_INCREMENT;
    new_customer.updateWaitTime(current_wait_time_);

    return true;
  } // if statment
  return false;
} // end of func

bool GeniusBar::assignGeniusToCustomer(){
  if ((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)){
    number_of_customers_--;
    number_of_available_geniuses_--;

    return true;
  } // if statment
return false;
} //end of func

bool GeniusBar::releaseGenius(){
  if ( number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES){
    number_of_available_geniuses_++;

    return true;
  } // if statment
  return false;
} // end of func

bool GeniusBar::updateCustomersWaitTime(){
  if (number_of_customers_ > 0){
    current_wait_time_  += WAIT_TIME_INCREMENT;
    return true;
  } // if statment
  return false;
} // end of func
