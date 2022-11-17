/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:30:02 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/17 22:11:15 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

//index
// amount
// created..

#include	<iostream>
#include	<ctime>
#include	"Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit ){
	_nbAccounts += 1;
	_totalAmount += initial_deposit; // 이건 왜 this 가 되었지? 

	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
} // 왜 cnt index 가 반대로 흘러가지 ? 

void	Account::_displayTimestamp( void ){
	time_t	raw_time;
	struct tm* timeinfo;
	char	buf[80];
	
	time(&raw_time);
	timeinfo = localtime(&raw_time);
	strftime(buf, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buf;
	// https://modoocode.com/122
}


int	Account::getNbAccounts( void ){
	return (_nbAccounts);	// ?
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}


void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);

	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl; // 여기서 ++ 하면은 적용 되나 ?
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
}

