#include "bankaccount.h"
#include "bank.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    QObject::connect(
                this, &BankAccount::balanceChanged,
                parentBank, &Bank::totalBalanceChanged);
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    emit balanceChanged(m_balance);
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
    emit balanceChanged(m_balance);
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
    emit balanceChanged(m_balance);
}
