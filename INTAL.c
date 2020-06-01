#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* intal_add(const char* intal1, const char* intal2)
{
	int larger,temp;
	char* sum = (char*)malloc(sizeof(char) * 1002); // THE INTAL THAT HAS THE SUM OF INTAL1 AND INTAL2
	char* larger_intal = (char*)malloc(sizeof(char) * 1001);
	int carry = 0;
	int i1 = strlen(intal1) - 1;
	int i2 = strlen(intal2) - 1;

	if (i1 >= i2)
	{
		larger = i1 + 1;
		strcpy (larger_intal, intal1); //INTAL WITH LARGER OR EQUAL DIGITS
	}
	else
	{
		larger = i2 + 1;
		strcpy (larger_intal, intal2);
	}


	while ((i1 != -1) && (i2 != -1))
	{
		if (((intal1[i1] + intal2[i2] - 48) + carry) < 58) // < 10
		{
			sum [larger] =	(intal1[i1] + intal2[i2] - 48) + carry; // ASCII VALUE OF '0" is 48
			carry = 0;
		}
		else
		{
			switch((intal1[i1] + intal2[i2] - 48) + carry)
			{
				case 58 : sum[larger] = 48; // 10 -> 0 (0 is sum carry is 1 for all these switch cases)
					break;
				case 59 : sum[larger] = 49; // 11 -> 1
					break;
				case 60 : sum[larger] = 50; // 12 -> 2
					break;
				case 61 : sum[larger] = 51; // 13 -> 3
					break;
				case 62 : sum[larger] = 52; // 14 -> 4
					break;
				case 63 : sum[larger] = 53; // 15 -> 5
					break;
				case 64 : sum[larger] = 54; // 16 -> 6
					break;
				case 65 : sum[larger] = 55; // 17 -> 7
					break;
				case 66 : sum[larger] = 56; // 18 -> 8
					break;
				case 67 : sum[larger] = 57; // 19 -> 9
					break;
			}
			carry = 1;
		}
		--i1; --i2; --larger;
	}

	if (i1 == i2) // IF NO. OF DIGITS IS SAME IN BOTH INTALS
	{
		if (carry == 0) // NO OVERFLOW AFTER PERFORMING SUM
		{

			for (int a = 0; a < (strlen(intal1)); a++)
			{
				sum[a] = sum[a + 1]; // SHIFT EVERY DIGIT BACK AND MAKE LAST DIGIT NULL
			}
			sum[strlen(intal1)] = '\0';
		}
		else                   // IF THERE IS OVERFLOW
		{
			sum[0] = 49; // MAKE FIRST DIGIT 1
			sum[strlen(intal1) + 1] = '\0';
		}
	}

	else // IF NO. OF DIGITS IS NOT THE SAME IN BOTH THE INTALS ADDING THE REMAINING DIGITS OF THE GREATER INTAL
	{ // ADDING THE REMAINING DIGITS OF THE GREATER INTAL
		int temp = larger;
		for (int i = larger - 1; i >= 0; i--)
		{

			if(((larger_intal[i] - 48) + carry) >= 10)
			{

				sum[temp] = '0'; // 0
				carry = 1;
			}
			else
			{
				sum[temp] = larger_intal[i] + carry;
				carry = 0;
			}
		--temp;

		}// END OF FOR LOOP

		if (carry == 0) // NO OVERFLOW AFTER PERFORMING SUM
		{

			for (int a = 0; a < (strlen(larger_intal)); a++)
			{
				sum[a] = sum[a + 1]; // SHIFT EVERY DIGIT BACK AND MAKE LAST DIGIT NULL
			}
			sum[strlen(larger_intal)] = '\0';
		}
		else                    // IF THERE IS OVERFLOW
		{
			sum[0] = '1'; // MAKE FIRST DIGIT 1
			sum[strlen(larger_intal) + 1] = '\0';
		}
	} // END OF ELSE CONDITION

		free (larger_intal);

		return sum;
}




int intal_compare(const char* intal1, const char* intal2)
{
	int flag = 0;
    	if(strlen(intal1) > strlen(intal2))
    	{
        	return 1;
    	} // IF INTAL1 HAS MORE DIGITS THAN INTAL2
   	else if(strlen(intal2) > strlen(intal1))
    	{
        	return -1;
    	} // IF INTAL2 HAS MORE DIGITS THAN INTAL1
   	else if(strlen(intal1) == strlen(intal2))
    	{ // IF THEY HAVE EQUAL NUMBER OF DIGITS, COMPARE DIGIT BY DIGIT
        	for (int i = 0; i < strlen(intal1); i++)
        	{
            		if (intal1[i] > intal2[i])
            		{
                    		flag = 1;
                    		break;
            		}
            		else if (intal2[i] > intal1[i])
            		{
                    		flag = 2;
		    		break;
    	    		}
        	}
    		if(flag == 1)
     		{
         		return 1;
     		} // INTAL1 > INTAL2
     		else if (flag == 2)
     		{
         		return -1;
     		} // INTAL2 > INTAL1
     		else return 0; // IF BOTH THE NUMBERS ARE EQUAL

    	} // END OF OUTER ELSE IF
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int zeros = 0; // NO. OF ZEROS TO BE APPENDED AT A LEVEL
	char* prod = (char*)malloc(sizeof(char) * 3000);
	char* level = (char*)malloc(sizeof(char) * 1002); // STORES PRODUCT AT A GIVEN LEVEL
	prod = "0";
	char* larger_intal = (char*)malloc(sizeof(char) * 1001);
	char* smaller_intal = (char*)malloc(sizeof(char) * 1001);
	int m, larger, smaller;
	int carry = 0;
	int i1 = strlen(intal1) - 1;
	int i2 = strlen(intal2) - 1;
	if (i1 >= i2)
	{
		larger = i1 + 1;
		smaller = i2;
		strcpy(larger_intal, intal1);
		strcpy(smaller_intal, intal2); // INTAL WITH LARGER OR EQUAL DIGITS
	}
	else
	{
		larger = i2 + 1;
		smaller = i1;
		strcpy(larger_intal, intal2);
		strcpy(smaller_intal, intal1);
	}
	int temp = larger - 1;
	for (int i = smaller; i >= 0; i--)
	{
		for (int j = temp; j >= 0; j--)
		{
			m = (smaller_intal[i] - 48) * (larger_intal[j] - 48) + carry;
			level[larger] = (m % 10) + 48;
			carry = (m / 10) ;
			larger--;
		}
		larger = strlen(larger_intal);

		if(carry != 0)
		{
			level[0] = carry + 48;
			level[strlen(larger_intal) + 1] = '\0';
			carry = 0;
		}
		else
		{
			for (int a = 0; a < (strlen(larger_intal)); a++)
			{
				level[a] = level[a + 1]; // SHIFT EVERY DIGIT BACK AND MAKE LAST DIGIT NULL
			}
			level[strlen(larger_intal)] = '\0';
		}

		for (int x = 0; x < zeros; ++x)
		{
			int flag = strlen(level);
			level[flag] = '0';
			level[flag + 1] = '\0';
			++flag;
		}
		prod = intal_add(level,prod);
		++zeros;


	}
	free (level);
	free (larger_intal);
	free (smaller_intal);

	return prod;

}

char* coin_row_problem(char **arr, int n)
{
  	char** f = (char**)malloc((n + 1) * sizeof(char*));
  	f[0] = (char*)malloc(2 * sizeof(char));
  	f[0][0] = '0';
  	f[0][1] = '\0';

  	for(int i = 0; i < n; ++i)
	{
    		f[i + 1] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));
    		strcpy(f[i + 1], arr[i]);
  	}

  	for(int i = 2; i < n + 1; ++i)
	{
    		char* val = intal_add(arr[i -1], f[i - 2]);
    		if(intal_compare(val, f[i - 1]) > 0)
		{
      			char* tmp = f[i];
      			f[i] = val;
      			free(tmp);
    		}
		else
		{
      			free(f[i]);
      			f[i] = (char*) malloc((strlen(f[i - 1]) + 1) * sizeof(char));
      			strcpy(f[i], f[i - 1]);
      			free(val);
    		}
  	}

  	char* result = (char*)malloc((strlen(f[n]) + 1) * sizeof(char));
  	strcpy(result, f[n]);

  	for(int i = 0; i < n + 1; ++i)
	{
    		free(f[i]);
  	}

	free(f);

  	return result;
}







char* intal_diff(const char* intal1, const char* intal2)
{
	int larger, smaller, temp, i, j;
	int *mark = (int*)malloc(sizeof(int) * 1001);
	char* difference = (char*)malloc(sizeof(char) * 1001);
	char* larger_intal = (char*)malloc(sizeof(char) * 1001);
	char* smaller_intal = (char*)malloc(sizeof(char) * 1001);
	int i1 = strlen(intal1) - 1;
	int i2 = strlen(intal2) - 1;
	int comp = intal_compare(intal1, intal2);
	if (comp == 1)
	{
		larger = i1;
		smaller = i2;
		strcpy(larger_intal, intal1);
		strcpy(smaller_intal, intal2);
	}
	else if (comp == -1)
	{
		larger = i2;
		smaller = i1;
		strcpy(larger_intal, intal2);
		strcpy(smaller_intal, intal1);
	}
	else
	{
		return "0";
	}

	for (int i = 0; i <= larger; i++)
	{
		mark[i] = 0;
	}

	i = larger;
	j = smaller;
	while ((i >= 0) && (j >= 0))
	{
		if ((larger_intal[i] >= smaller_intal[j]) && (mark[i] == 0))
		{
			difference[i] = larger_intal[i] - smaller_intal[j] + 48;
		}
		else if (mark[i] == 1)
		{
			int x = 9 - (smaller_intal[j] - 48);
			difference[i] = x + 48;
		}
		else
		{
			int x = (10 + (larger_intal[i] - 48)) - (smaller_intal[j] - 48);
			difference[i] = x + 48;
			for (int a = i - 1; a >= 0; a--)
			{
				if (larger_intal[a] != 48)
				{
					--larger_intal[a];
					break;
				}
				else
				{
					mark[a] = 1;
					continue;
				}
			}
		}
		--i;
		--j;

	}

	if (i != j) // NO. OF DIGITS IS NOT THE SAME
	{
		for ( ;i >= 0; i--)
		{
			if(mark[i] == 0)
			{
				difference[i] = larger_intal[i];
			}
			else
			{
				difference[i] = 57;
			}

		}
	}

	temp = strlen(larger_intal);

	while (1)
	{
		if (difference[0] != 48)
		{
			break;
		}
		for (int a = 0; a < temp; a++)
		{
			difference[a] = difference[a + 1];
			difference[temp] = '\0';
		}

		--temp;
	}


	return difference;
}




char* intal_fibonacci(unsigned int n)
{
	char *f1 = (char*)malloc(sizeof(char) * 1001);
	char *f2 = (char*)malloc(sizeof(char) * 1001);
	char *fib = (char*)malloc(sizeof(char) * 1002);
	if (n == 0)
	{
		return "0";
	}
	else if (n == 1)
	{
		return "1";
	}
	else
	{
		f1 = "0";
		f2 = "1";
		for (int i = 1; i < n; i++)
		{

			fib = intal_add (f1,f2);
			f1 = f2;
			f2 = fib;
		}
	}


	return fib;
}




char* intal_factorial(unsigned int n)
{
	if(n == 0)
	{
		return "1";
	}
	if (n == 1)
	{
		return "1";
	}
	char* s = (char*)malloc(sizeof(char) * 1001);
	char* fact = (char*)malloc(sizeof(char) * 1001);
	s = "2";
	fact = "1";

	for (int i = 2; i <= n; i++)
	{
		fact = intal_multiply (fact,s);
		s = intal_add(s,"1");
	}

	return fact;
}


char* intal_pow(const char* intal1, unsigned int n)
{
	if (strcmp(intal1,"0") == 0)
	{
		return 0;
	}
	char *pow = (char*)malloc(sizeof(char)*1001);
	pow = "1";
	for (int i = 0; i < n; i++)
	{
		pow = intal_multiply (intal1, pow);
	}
	return pow;
}



int intal_max(char **arr, int n)
{
	int max = 0;
	for (int i = 0;	i < n; i++)
	{
		if ((intal_compare (arr[i], arr[max]) == 1))
		{
			max = i;
		}
	}
	return max;
}




int intal_min(char **arr, int n)
{
	int min = 0;
	for (int i = 0;	i < n; i++)
	{
		if ((intal_compare (arr[i], arr[min]) == 1))
		{
			continue;
		}
		else
		{
			min = i;
		}

	}
	return min;
}



int intal_search(char **arr, int n, const char* key)
{
	for (int i = 0;	i < n; i++)
	{
		if ((intal_compare (key, arr[i]) == 0))
		{
			return i;
		}

	}
	return -1;
}

void main ()
{
    char *s = (char*)malloc(sizeof(1001));
    s = intal_add ("10002", "986");
    printf ("%s",s);
    printf ("\n");
    // IN A SIMILAR FASHION, CALL THE OTHER FUNCTIONS THAT HAVE BEEN DEFINED.
}






















