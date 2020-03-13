#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>

class BankAccount : public QObject
{
    Q_OBJECT

    Q_PROPERTY(
            QString holderName READ holderName
            WRITE setHolderName
            )

    Q_PROPERTY(
            long balance READ balance CONSTANT
            )

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    QString holderName() {
        return m_holderName;
    }

    void setHolderName(QString name) {
        m_holderName = name;
    }

    long balance() {
        return m_balance;
    }
private:
    QString m_holderName;
    long m_balance;
};

#endif // BANKACCOUNT_H
