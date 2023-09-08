/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:21:10 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/08 11:59:01 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount - withdrawal > 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount - withdrawal
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		_amount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << _nbWithdrawals
			<< ";refused"
			<< std::endl;
		return (false);
	}
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::cout
		<< "["
		<< std::setw(2)
		<< std::localtime(&time)->tm_year + 1900
		<< std::setw(2)
		<< std::setfill('0')
		<< std::localtime(&time)->tm_mon
		<< std::setw(2)
		<< std::localtime(&time)->tm_mday
		<< "_"
		<< std::setw(2)
		<< std::localtime(&time)->tm_hour
		<< std::setw(2)
		<< std::localtime(&time)->tm_min
		<< std::setw(2)
		<< std::localtime(&time)->tm_sec
		<< "] ";
}
