template <class T>
SUBARRAY_INFO* FindMaxSubArray(
	SUBARRAY_INFO *_pSAInfo,
	T *_pSourceArray, 
	unsigned int _iLow,
	unsigned int _iHigh)
{
	unsigned int low = 0;
	unsigned int high = 0;
	int sum = -255;
	unsigned int iMiddle = (_iLow + _iHigh) / 2;
	

	if ( _iHigh == _iLow)
	{
		_pSAInfo->low = _iLow;
		_pSAInfo->high = _iHigh;
		_pSAInfo->sum = _pSourceArray[_iLow];
		return _pSAInfo;
	}
	else
	{
		FindMaxSubArray(_pSAInfo, _pSourceArray, _iLow, iMiddle);
		if (_pSAInfo->sum > sum)
		{
			low = _pSAInfo->low;
			high = _pSAInfo->high;
			sum = _pSAInfo->sum;
		}
		FindMaxSubArray(_pSAInfo, _pSourceArray, iMiddle+1, _iHigh);
		if (_pSAInfo->sum > sum)
		{
			low = _pSAInfo->low;
			high = _pSAInfo->high;
			sum = _pSAInfo->sum;
		}
		FindMaxCrossingSubArray<T>(_pSAInfo, _pSourceArray, _iLow, iMiddle, _iHigh); 
		if (_pSAInfo->sum > sum)
		{
			low = _pSAInfo->low;
			high = _pSAInfo->high;
			sum = _pSAInfo->sum;
		}

		_pSAInfo->low = low;
		_pSAInfo->high = high;
		_pSAInfo->sum = sum;
		
		return _pSAInfo;
	}
}


template <class T>
SUBARRAY_INFO* FindMaxCrossingSubArray(
	SUBARRAY_INFO *_pSAInfo,
	T *_pSourceArray,
	unsigned int _iLow,
	unsigned int _iMiddle,
	unsigned int _iHigh)
{
	unsigned int maxleft = 0;
	unsigned int maxright = 0;
	int leftsum = - 255;
	int rightsum = -255;
	int sum = 0;
	
	for (int i = _iMiddle; i >= (int)_iLow; --i)
	{
		sum += _pSourceArray[i];
		if (sum > leftsum)
		{
			leftsum = sum;
			maxleft = i;
		}
	}

	sum = 0;
	for (unsigned int j = _iMiddle+1; j <= _iHigh; ++j)
	{
		sum += _pSourceArray[j];
		if (sum > rightsum)
		{
			rightsum = sum;
			maxright = j;
		}
	}

	_pSAInfo->low = maxleft;
	_pSAInfo->high = maxright;
	_pSAInfo->sum = leftsum + rightsum;
	return _pSAInfo;
}
