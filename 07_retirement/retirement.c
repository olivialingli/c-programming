#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
  typedef struct  _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  int month=3;
  for(int i = 0; i < working.months; i++){
    if(month==12){
      month=0;
      startAge++;
    }
    printf("Age %3d month %2d you have $%.2lf\n", startAge, month, initial);
    initial += initial*working.rate_of_return+working.contribution;
    month++;
  }
  for(int i = 0; i < retired.months; i++){
    if(month==12){
      month=0;
      startAge++;
    }
    printf("Age %3d month %2d you have $%.2lf\n", startAge, month, initial);
    initial += initial*retired.rate_of_return+retired.contribution;
    month++;
  }
}

int main(void){
  retire_info working;
  retire_info retired;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01/12;
  retirement(27, 21345, working, retired);
  return 0;
}
  
