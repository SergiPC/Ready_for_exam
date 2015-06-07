unsigned int fib(unsigned int pos_number)
{
	unsigned int fib_num = 1;
	unsigned int tmp = 0;

	for (unsigned int i = 0; i < pos_number; i++)
	{
		fib_num += tmp;
		tmp = fib_num;
	}

	return fib_num;
}