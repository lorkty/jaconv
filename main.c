#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void len();
void square();
void volume();
void quit();
char menu();


float equalmeters[4] = {0.001, 0.01, 1, 1000}; // mm, cm, m, km - 0.001, 0.01, 1, 1000
char run;

typedef struct{ // Структура опций меню
  const char *description;
  void (*func)();
} menuoptions;

menuoptions menuopt[] = { // Массив опций
  {"Exit", quit},
  {"Length", len}, 
  {"Square", square},
  {"Volume", volume}
};

int main(){
  run = 'r';
  system("clear");
  while(run == 'r'){
    system("clear");
    run = 'q';
    run = menu();
  }
  return 0;
}

void len(){   // Функция перевода длин
  double beginnum, endnum; // входное число - преобразованное число
  int from, to; // для выбора
  printf("###################  Len - Function  ##############\n\n\n");
  printf("## Choose first\n## (1) mm\n## (2) cm\n## (3) m\n## (4)km\n ");
  printf("## Input >> ");
  scanf("%d", &from);
  printf("## Choose second\n##(1) mm\n## (2) cm\n## (3) m\n## (4) km\n");
  printf("## Input >> ");
  scanf("%d", &to);
  printf("## Input num >> ");
  scanf("%lf", &beginnum);
  endnum = (beginnum * (equalmeters[from - 1] / equalmeters[to - 1]));
  printf("First = %.5g, Second = %.5g\n", beginnum, endnum);

  printf(" Press Enter to continue... ");
  getchar();
  getchar();
}

void square(){
  double beginnum, endnum;
  int from, to;
  printf("###################  square mesearments  ##############\n\n\n");
  printf("## Choose first\n## (1) mm^2\n## (2) cm^2\n## (3) m^2\n## (4)km^2\n");
  printf("## Input >> ");
  scanf("%d", &from);
  printf("## Choose second\n##(1) mm^2\n## (2) cm^2\n## (3) m^2\n## (4) km^2\n");
  printf("## Input >> ");
  scanf("%d", &to);
  printf("## Input num >> ");
  scanf("%lf", &beginnum);
  endnum = (beginnum * pow((equalmeters[from - 1] / equalmeters[to - 1]), 2));
  printf("first = %.5g, second = %.5g\n", beginnum, endnum);

  printf(" Press enter to continue... ");
  getchar();
  getchar();

}
void volume(){
  printf("Volume\n");
  getchar();
  getchar();
}

char menu(){
  int action;
  int i;

  printf("###################  CONVERTER  ###################\n");
  printf("################### Version 0.0.05  ###############\n\n\n");
  printf("## Choose the measerment.\n");
  for(i = 0; i < sizeof(menuopt) / sizeof(menuopt[0]); i++)
    printf("## (%d) %s\n", i, menuopt[i].description);
  printf("## Input >> ");
  scanf("%d", &action);

  if (action >= 0 && action <= sizeof(menuopt) / sizeof(menuopt[0])){
    menuopt[action].func();
    return run;
  }
  else{
    printf("Ошибка ввода. Повторите попытку. \n");
    return run;
  }
}
void quit(){
  run = 'q';
}
