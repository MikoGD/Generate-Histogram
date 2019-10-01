#include "getio.h"

// Displays error message depending on the return of parseInput
void displayErrorMessage(isNatNumCode code)
{
	switch(code)
	{
		case not_number:
			printf("ERROR INVALID INPUT: Only numbers can be entered\n");
			printf("Please enter a valid number\n\n");

			break;
		//END CASE 2
		
		case negative:
			printf("ERROR INVALID INPUT: Only positive numbers can be entered\n");
			printf("Please enter a valid number\n\n");

			break;
		//END CASE 3

		case float_num:
			printf("ERROR INVALID INPUT: Only whole numbers can be entered\n");
			printf("Please enter a valid number\n\n");

			break;
		//END CASE 4

		case empty:
			printf("ERROR INVALID INPUT: Please enter in a number\n");
			break;

		default:
			printf("ERROR\n\n");
	}//END SWITCH
}//END displayErrorMessage()

//Get user input and adds \0 to the end of the input
void getInput(char *input, size_t *nBytes)
{
	int i = 0;
	//Get input and store it in input
	getline(&input, nBytes, stdin);
	
	/* Goes through the string until it finds a \n.
	 * Replace it with \0.
	 * Exit when it finds \0.
	 * This is done as using getline will put '\n' at the end of the input
	 * instead of a '\0' making it not a real string.
	 */
    while(input[i] != '\0')
	{
		if(input[i] == '\n')
		{
			input[i] = '\0';
		}//END IF

		i++;
	}//END WHILE
}//END getInput()

/*
 * Goes through the input and check if it is valid.
 * The only valid input is an natural number, all other input are invalid.
 * Codes used are from the paresInputCode enum
 */
isNatNumCode isNatNum (char *input)
{
	int i = 0;
	
	//Check if the user entered nothing
	if(*input != '\0')
	{
		//Check if the user entered a minus
		if(*input != '-')
		{
			//Loop through the string to check for a '.' or a non-numeric character
			while(input[i] != '\0')
			{
				//Checks if the character is non-numeric
				if(isdigit(input[i]) == 0)
				{
					/*
					 * Since we know it is not a number we check if the character is
					 * a period ('.') or another non-numeric character to return the right
					 * value for the error
					 */ 
					if(input[i] == '.')
					{
						return float_num;
					}
					else
					{
						return not_number;
					}//END WHILE INNER IF
				}//END WHILE IF		

				i++;
			}//END WHILE
		}
		else
		{
			return negative;
		}//END INNER IF

	}//END IF
	else
	{
		return empty;
	}//END IF

	return valid;
}//END parseInput()
