#if 0
#include<stdio.h>
#include"All_Functions.h"
#include<stdarg.h>

bool TransposeSMatrix(TSMatrix M, TSMatrix& T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		int q = 1;
		for (int col = 1; col <= M.nu; ++col)
		{
			for (int p = 1; p <= M.tu; ++p)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
	return true;
}

bool FastTransposeSMatrix(TSMatrix M, TSMatrix& T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	int num[MAXSIZE + 1], cpot[MAXSIZE + 1];
	if (T.tu)
	{
		for (int col = 1; col <= M.nu; ++col)
			num[col] = 0;
		for (int t = 1; t <= M.tu; ++t)
			++num[M.data[t].j];
		cpot[1] = 1;
		for (int col = 2; col <= M.nu; +col)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (int p = 1; p <= M.tu; ++p)
		{
			int col = M.data[p].j;
			int q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			++cpot[col];
		}
	}
	return true;
}
#endif
