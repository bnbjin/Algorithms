#Pseudo Code  
###QUICKSORT  
if (p < r)  
&emsp;q = PARTITION(A, p, r)  
&emsp;QUICKSORT(A, p, q-1)  
&emsp;QUICKSORT(A, q+1, r)  

###PARTITION  
x = A[r]  
i = p -1  
for j = p to r -1  
&emsp;if A[j] <= x  
&emsp;&emsp;i = i +1  
&emsp;&emsp;*exchange* A[i] with A[j]  
*exchange* A[i+1] with A[r]
return i+1  

>**Loop Invariant(PARTITION)**  
&emsp;1. if p <= k <= i, then A[k] <= x.  
&emsp;2. if i+1 <= k <= j-1, then A[k] > x.  
&emsp;3. if k == r, then A[k] == x  

#思想  
&emsp;递归把当前数组划分为两个数组，取其中一个元素为中心点，大于该元素值的划分到一个组，小于等于该值的划分到另一个组。  
#时间复杂度  
* 期望 θ(nlogn)，且常数因子很小
* 最差 θ(n2)
