void BubbleSort(int *A, int len)
{
	int key;

	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (A[i] < A[j])
			{
				key = A[i];
				A[i] = A[j];
				A[j] = key;
			}
		}
	}
}
