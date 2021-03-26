#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
 int t, n, act_num = 0;
 int i, j, k;
 int box, flag = 0;
 int x[1005];
 scanf ("%d", &t);

 for (i = 0; i < t; i++) {
  act_num = 0;
  flag = 0;
  scanf ("%d", &n);
  for (j = 0; j < 1005; j++) {
   x[j] = 0;
  }
  for (j = 0; j < n; j++) {

   scanf ("%d", &x[j]);
  }

  for (j = 0; j < n - 1; j++) {
   for (k = 1; k < n - 1; k++) {
    if (x[k] > x[k + 1] && x[k] < x[k - 1]) {
     act_num++;
     box = x[k + 1];
     x[k + 1] = x[k - 1];
     x[k - 1] = box;
    }
   }
  }
  for (j = 0; j < n - 1; j++) {
   if (x[j] > x[j + 1]) {
    flag = 1;
    break;
   }
  }
  if (0 == flag) {
   printf ("%d\n", act_num);
  } else {
   printf ("-1\n");
  }
 }

 return 0;
}