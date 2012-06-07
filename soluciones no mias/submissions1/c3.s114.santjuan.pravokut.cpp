#include<cstdio>

int main()
{
		int n;
		scanf("%d", &n);
		int puntos[n][2];
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &puntos[i][0], &puntos[i][1]);
		}
		int cuenta = 0;
		for(int i = 0; i < n; i++)
		{
			int *a = puntos[i];
			for(int j = i + 1; j < n; j++)
			{
				int *b = puntos[j];
				long long side11 = (a[0] - b[0]);
				side11 *= side11;
				long long side12 = (a[1] - b[1]);
				side12 *= side12;
				long long side1 = side11 + side12;
				for(int k = j + 1; k < n; k++) 
				{
					int *c = puntos[k];
					long long side21 = (a[0] - c[0]);
					side21 *= side21;
					long long side22 = (a[1] - c[1]);
					side22 *= side22;
					long long side2 = side21 + side22;
					long long side31 = (b[0] - c[0]);
					side31 *= side31;
					long long side32 = (b[1] - c[1]);
					side32 *= side32;
					long long side3 = side31 + side32;
					if(((side1) == ((side2) + (side3))) || ((side2) == ((side1) + (side3))) || ((side3) == ((side1) + (side2))))
						 cuenta++;
				}
			}
		}
		printf("%d\n", cuenta);
	}
