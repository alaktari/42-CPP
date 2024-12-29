#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac == 4 && av[2][0])
	{
		std::ifstream input_f;
		std::ofstream output_f;
		std::string replace_file;

		input_f.open(av[1]);
		if (!input_f.is_open())
			return (std::cerr << "Error: can't open the input file '" << av[1] << "'" << std::endl, 1);

		replace_file = av[1];
		replace_file += ".replace";
		output_f.open(replace_file.c_str());
		if (!output_f.is_open())
			return (std::cerr << "ERROR: Can't open the output file '" << replace_file << "'" << std::endl, 1);
		
		return (read_and_write(av[2], av[3], input_f, output_f));
		
	}
	else
		std::cout << "Expected:   ./sed    [filename]  [s1]  [s2]\n";

}
