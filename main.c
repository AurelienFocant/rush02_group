int main(int argc, char **argv)
{
	if (argv_zero_error(argc, argv) || argv_error(argc, argv) || argc_error(argc))
	{
		ft_putchar("Error\n");
		return (0);
	}

	return (0);
}
