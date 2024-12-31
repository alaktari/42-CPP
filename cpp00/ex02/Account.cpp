#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0; // total number of accounts
int Account::_totalAmount = 0; // total amount accross all acounts
int Account::_totalNbDeposits = 0; // totoal number of deposits made across all accounts
int	Account::_totalNbWithdrawals = 0; // total withdraws made accross all accounts

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts; // the index (ID) of the account
	_amount = initial_deposit; // the current amount int he account
	_nbDeposits = 0; // number of deposits made into this account
	_nbWithdrawals = 0; // number of  withdraws made from this acount

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::_displayTimestamp( void )
{
	int month;
	int day;
	int hour;
	int minute;
	int second;

	std::time_t currentTime = std::time(NULL);
	std::tm		*localTime = std::localtime(&currentTime);

	std::cout << "[";
	std::cout << 1900 + localTime->tm_year;
	month = 1 + localTime->tm_mon;
	if (month < 10)
		std::cout << "0";
	std::cout << month;

	day = localTime->tm_mday;
	if (day < 10)
		std::cout << "0";
	std::cout << day;
	std::cout << "_";
	hour = localTime->tm_hour;
	if (hour < 10)
		std::cout << "0";
	std::cout << hour;
	minute = localTime->tm_min;
	if (minute < 10)
		std::cout << "0";
	std::cout << minute;
	second = localTime->tm_sec;
	if (second < 10)
		std::cout << "0";
	std::cout << second;
	std::cout << "] ";
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	}
	else
		return ((std::cout << "refused\n"), false);
	return true;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";totat:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}
