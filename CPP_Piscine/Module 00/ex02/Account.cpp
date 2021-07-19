#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) :	_accountIndex(getNbAccounts()),
									_amount(initial_deposit),
									_nbDeposits(0),
									_nbWithdrawals(0) {
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
				<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}


void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals
					 << std::endl;
	} else {
		std::cout << "refused" << std::endl;
		return (false);
	}
	return (true);
}

int		Account::checkAmount( void ) const {
	return (0);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
				<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::_displayTimestamp( void ) {
	std::time_t	epoch_time;
	struct tm	*cur_time;
	char		form_time[20];

	epoch_time = std::time(nullptr);
	cur_time = localtime(&epoch_time);
	if (std::strftime(form_time, 20, "[%Y%m%d_%H%M%S] ", cur_time))
		std::cout << form_time;
}