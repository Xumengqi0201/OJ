	bool isall_negative = true;
	int ThisSum = 0 ,start = 0 , end = 0 , tem_start = 0 , MaxSum = -1;
	for (int i = 0 ; i < len ; i++)
	{
		cin >> sequence[i];
		if (sequence[i] >= 0){
			isall_negative = false;
		}

		ThisSum += sequence[i];
		if (ThisSum > MaxSum){
			MaxSum = ThisSum;
			end = i;
			start = tem_start;
		}
		else if (ThisSum < 0){
			ThisSum = 0;
			tem_start = i+1;
		}

	}

	if (isall_negative)
	{
		 printf("%d %d %d",0,sequence[0],sequence[len-1]);
	}
	else
	{
		cout << MaxSum << ' ' << sequence[start];
		cout << ' ' << sequence[end] << '\n';
	}


	return 0;
}