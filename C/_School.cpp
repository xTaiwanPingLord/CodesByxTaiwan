#include <stdio.h>
#include <stdlib.h>
void QuickSort(int *data, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	else
	{
		int pivot = data[left];
		int i = left + 1;
		int j = right;
		while (1)
		{
			while (i <= right)
			{
				if (pivot < data[i])
				{
					break;
				}
				i++;
			}

			while (j > left)
			{
				if (pivot > data[j])
				{
					break;
				}
				j--;
			}
			if (i >= j)
			{
				break;
			}
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		int temp = data[j];
		data[j] = data[left];
		data[left] = temp;
		QuickSort(data, left, j - 1);
		QuickSort(data, j + 1, right);
	}
}

int main()
{
	int i, n, data[10];

	printf("請輸入資料筆數 n(<= 10): ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("請輸入第 %d 筆資料: ", i + 1);
		scanf("%d", &data[i]);
	}

	// 執行快速排序法
	QuickSort(data, 0, n - 1);

	printf("\n排序後的結果: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\n");
	system("pause");
}