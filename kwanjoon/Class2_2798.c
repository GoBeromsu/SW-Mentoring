#include <stdio.h>

 

int absolute_value(int a, int b) // 절댓값 구하는 함수

{

  if (a-b>0)

    return a-b;

  else return b-a;

}

 

int main(void)

{

  int N,M; // N은 카드의 계수, M은 타겟값

  scanf("%d %d", &N, &M);

 

  int array[N];

  int sum[(N*(N-1)*(N-2))/6];

  int count = 0;

  

  for(int i = 0; i < N; i++)

    {

      scanf("%d",&array[i]);

    }

 

  /* 모든 배열의 원소 3개씩 합하는 경우의 수는 (N*(N-1)*(N-2))/6 */

  for(int i = 0; i < N; i++)

    {

      for(int k = 0; k < N; k++)

        {

          if(k == i)

            continue;

          for(int l = 0; l < N; l++)

            {

              if(l == k || l == i)

                continue;

              

              sum[count] = array[i] + array[k] + array[l];

              count ++;

            }

        }

    }

 

  int result;

  

  for(int i = 0; i < (N*(N-1)*(N-2))/6 ; i++)

    {

      result = absolute_value(M,sum[0]);

      if (absolute_value(M,sum[i]) < result)

        result = absolute_value(M,sum[i]);

    }

 

  printf("%d", result);

  

  return 0;

}