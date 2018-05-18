#define MINUS_INFINITE -9999

int
find_max_crossing_subarr(
	int *arr, 
	int low, 
	int mid, 
	int high,
	int *max_left,
	int *max_right)
{
	int left_sum = MINUS_INFINITE; 
	int right_sum = MINUS_INFINITE;
	int sum = 0;

	for (int i = mid; i >= low; --i)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			*max_left = i;
		}
	}

	sum = 0;

	for (int j = mid+1; j <= high; ++j)
	{
		sum += arr[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			*max_right = j;
		}
	}

	return left_sum + right_sum;
}

int
find_max_subarr(
	int *arr,
	int low,
	int high,
	int *max_left,
	int *max_right)
{
	int mid = 0;
	int left_sum = 0;
	int right_sum = 0;
	int cross_sum = 0;
	int left_low = 0;
	int left_high = 0;
	int right_low = 0;
	int right_high = 0;
	int cross_low = 0;
	int cross_high = 0;

	if (high == low)
	{
		*max_left = low;
		*max_right = high;
		return arr[low];
	}
	else
	{
		mid = (low + high) / 2;
		left_sum = find_max_subarr(arr, low, mid, &left_low, &left_high);
		right_sum = find_max_subarr(arr, mid+1, high, &right_low, &right_high);
		cross_sum = find_max_crossing_subarr(arr, low, mid, high, &cross_low, &cross_high);
	}

	if (left_sum >= right_sum && left_sum >= cross_sum)
	{
		*max_left = left_low;
		*max_right = left_high;
		return left_sum;
	}
	else if (right_sum >= left_sum && right_sum >= cross_sum)
	{
		*max_left = right_low;
		*max_right = right_high;
		return right_sum;
	}
	else
	{
		*max_left = cross_low;
		*max_right = cross_high;
		return cross_sum;
	}
}
