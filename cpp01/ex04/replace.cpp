#include "replace.hpp"

void	ft_replace(std::string &buffer, ssize_t possition, std::string replacement, int len)
{
	buffer.erase(possition, len);
	buffer.insert(possition, replacement);
}

int	read_and_write(std::string s1, std::string s2, std::ifstream &input_f, std::ofstream &output_f)
{
	std::string buffer;
	ssize_t possition;

	while (getline(input_f, buffer))
	{
		possition = buffer.find(s1);
		while (possition >= 0)
		{
			ft_replace(buffer, possition, s2, s1.length());
			possition = buffer.find(s1);
		}
		output_f << buffer;
		if (!input_f.eof())
			output_f << std::endl;
	}
	if (input_f.fail() && !input_f.eof())
		return ((std::cerr << "Error: 'getline' failed!\n"), 1);
	return 0;
}