// C program to reverse a string
#include <stdio.h>

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(char* begin, char* end)
{
	char temp;
	while (begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

// C program for above approach

void reverseWords(char* s)
{
	char* word_begin = NULL;

	// /* temp is for word boundary */
	char* temp = s;

	/*STEP 1 of the above algorithm */
	while (*temp)
	{

		/*This condition is to make sure that the
		string start with valid character (not
		space) only*/
		if ((word_begin == NULL) &&
				(*temp != ' '))
		{
			word_begin = temp;
		}
		if (word_begin && ((*(temp + 1) == ' ') ||
			(*(temp + 1) == '\0')))
		{
			reverse(word_begin, temp);
			word_begin = NULL;
		}
		temp++;
	} /* End of while */

	/*STEP 2 of the above algorithm */
	reverse(s, temp - 1);
}

// Driver Code
int main()
{
	char s[] = "i like this program very much";
	char* temp = s;
	reverseWords(s);
	printf("%s", s);
	return 0;
}
