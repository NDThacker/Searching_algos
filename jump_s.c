#include <stdio.h>
#include <math.h>
// Author Naman THacker


int jump_search(int *, int, int);

void main()
{
	int length;
	printf("Enter Number of elements :");
	scanf("%d", &length);

	int arr[length], sel;
	int *ar = arr;

	printf("\nEnter sorted integer list :");

	for(sel = 0; sel < length; sel++)
		scanf("%d", &ar[sel]);

	printf("\nEnter element to search :");
	scanf("%d", &sel);

	int ind = jump_search(ar, length, sel);

	if(ind == -1)
		printf("\nElement not found..!\n");
	else
		printf("\nElement found at %d\n", ind+1);
}

int jump_search(int *arr, int len, int ele)
{
	int inter = (int)sqrt((double)len);

	int ind, sind;

	for(ind = 0; ind < len; ind = (ind + inter) % len)
	{
		if(ele == arr[ind])
			return ind;
		else if(ele < arr[ind])
		{
			for(sind = ind - 1; sind >= ind - inter; sind--)
			{
				if(arr[sind] == ele)
				{
					return sind;
				}
			}
			return -1;
		}

	}
	return -1;
}