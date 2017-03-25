template <class T>
void MergeSort(
	T *_SourceArray, 
	T *_WorkArray,
	unsigned int _iStart,
	unsigned int _iEnd)
{
	unsigned int iMiddle;

	if (_iStart < _iEnd)
	{
		iMiddle = (_iStart + _iEnd) / 2;
		MergeSort<T>(_SourceArray, _WorkArray, _iStart, iMiddle);
		MergeSort<T>(_SourceArray, _WorkArray, iMiddle+1, _iEnd);
		Merge<T>(_SourceArray, _WorkArray, _iStart, iMiddle, _iEnd);
	}
}

template <class T>
void Merge(
	T *_SourceArray,
	T *_WorkArray,
	unsigned int _iStart,
	unsigned int _iMiddle,
	unsigned int _iEnd)
{
	unsigned int i = _iStart;
	unsigned int j = _iMiddle + 1;
	unsigned int k = _iStart;

	while (i <= _iMiddle && j <= _iEnd)
	{
		if (_SourceArray[i] < _SourceArray[j])
		{
			_WorkArray[k++] = _SourceArray[i++]; 
		}
		else
		{
			_WorkArray[k++] = _SourceArray[j++];
		}
	}

	while (i <= _iMiddle)
	{
		_WorkArray[k++] = _SourceArray[i++];
	}

	while (j <= _iEnd)
	{
		_WorkArray[k++] = _SourceArray[j++];
	}

	for (k = _iStart; k <= _iEnd; ++k)
	{
		_SourceArray[k] = _WorkArray[k];
	}
}
