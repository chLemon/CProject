#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int x[1000005];

int one_dsg (int n);
int two_dsg (int n);

int main()
{
 int n, max, min;
 int i, a, flag = 0;
 int j, dsg_1, dsg_2;
 int num_flag;
 long long plus;
 
 scanf ("%d", &n);
 
 for (i = 0; i < n; i++){
  scanf ("%d", &x[i]);
 }//读入数据  
 
 if (n & 1){
  for (i = 0; i < n; i++){
   
   a = x[i] ^ 1;
   flag = 0;
  
   for (j = i + 1; j < n; j++){
    if (x[j] ^ a == 1){
     flag = 1;
     break;
    }
   }
   
   if (flag == 1){
    continue;
   }
   else{
    printf ("1 %d", x[i]);
    return 0;
   }
   
  }
 }//奇数个时必定有1个单身狗 
 
 for (i = 0; i < n; i++){
   
  a = x[i] ^ 1;
  flag = 0;
  
  for (j = i + 1; j < n; j++){
   if ((x[j] ^ a)== 1){
    flag = 1;
    break;
   }
  }
   
  if (flag == 0 && num_flag == 0){
   dsg_1 = x[j];
   num_flag++;
   continue;
  }
  else if (flag == 0 && num_flag == 1){
   dsg_2 = x[j];
   break;
  } 
 }//偶数时找到这两个数 
 
 if (flag == 0){
  plus = (long long) dsg_1 * dsg_2;
  printf ("2 %lld", plus);
  return 0;
 }//输出两个乘积 
 
 max = x[0];
 min = x[0];
 
 for (i = 0; i < n; i++){
  if (x[i] > max){
   max = x[i];
  }
  if (x[i] < min){
   min = x[i];
  }
 }
 
  printf ("%d %d", min, max); 
 return 0;
}