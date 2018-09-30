//Checks which of the two motor values is higher.
	int max (float a, float b)
	{ if (a > b) // If a is greater than b
		{
			return a; // Return a
		}
		else // If b is greater than a
		{
			return b; // Return b
		}
	}

	// Checks which of the two values is lower
	int min (float a, float b)
	{
		if (a < b) // If a is less than b
		{
			return a; // Return a
		}
		else // If b is less than a
		{
			return b; // Return b
		}
	}

	/* This function "brackets" (or constrains) the values so that it is not greater than the range*/
	float constrain (float min, float max, float value)
	{
		if (value > max)
		{
			return max;
		}
		if (value < min)
		{
			return min;
		}
		else
		{
			return value;
		}
	}

		/* This function assigns sign a value dependent on the ballAngle*/
	int sign (int x)
	{
		if (x > 0) // If x is greater than 0
		{
			return 1; // Sign is equal to 1
		}
		else if (x < 0) // If x is less than 0
		{
			return -1; // Sign is equal -1
		}
		else // If x is equal to 0
		{
			return 0; // Sign is equal to 0
		}
	}
	int mean (int a, int b)
	{

