#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

void	ft_replace(std::string &buffer, ssize_t possition, std::string replacement);
int     read_and_write(std::string s1, std::string s2, std::ifstream &input_f, std::ofstream &output_f);

#endif