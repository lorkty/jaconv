#pragma once

#include <stdio.h>
#include <math.h>

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
  printf("###################  Square mesearments  ##############\n\n\n");
  printf("## Choose first\n## (1) mm^2\n## (2) cm^2\n## (3) m^2\n## (4)km^2\n ");
  printf("## Input >> ");
  scanf("%d", &from);
  printf("## Choose second\n##(1) mm^2\n## (2) cm^2\n## (3) m^2\n## (4) km^2\n");
  printf("## Input >> ");
  scanf("%d", &to);
  printf("## Input num >> ");
  scanf("%lf", &beginnum);
  endnum = (beginnum * pow((equalmeters[from - 1] / equalmeters[to - 1]), 2));
  printf("First = %.5g, Second = %.5g\n", beginnum, endnum);

  printf(" Press Enter to continue... ");
  getchar();
  getchar();

}



char menu(){
  int action = 0;

  printf("###################  CONVERTER  ###################\n");
  printf("################### Version 0.0.03  ################\n\n\n");

  printf("## Choose the measerment. ##\n");
  printf("## 0. Exit                ##\n");
  printf("## 1. Length              ##\n");
  printf("## 2. Square              ##\n");
  printf("## 3. Volume              ##\n");
  printf("## 4. Speed               ##\n");
  printf("  Input >> ");
  scanf("%d", &action);

  if (action >= 0 && action < 10){
    switch (action){
      case 1:
        len();
        break;
      case 2:
        square();
        break;
      case 3:
        //volume();
        break;
      case 4:
        //speed();
        break;
      case 0:
        return 'q';
        break;
    }
  }
  return 'r';
}
