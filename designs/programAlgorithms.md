# Program Algorithms
These are the steps the program takes to be able to perform its fucntions as an ATM.

## ATM Process flow
- Walk to the ATM
- Input the PIN
- Transact
- Pick card
- Leave

## This program scope
1. Pin Validation
2. **Transact**

## 1. Pin Validation
- Input pin
- Check pin against correct pin
- if pin is correct: proceed to transact
- if pin is incorrect: provide 3 chances for reattempts
- recheck the pin
- count attempts
- if maximum attempts are exceeded: block card and terminate

## 2. Transact
- withdraw
- check balance
- deposit
- print ministatement

## 2.1 Withdraw
- Enter amount to withdraw
- if amount withdrawn is greater than the account balance: forbid withdrawal
- if amount is less than account balance: withdraw the amount
- return the resultant balance

## 2.2 Check balance
- Print the current account balance

## 2.3 Deposit
- Enter amount to deposit
- Add amount to the balance
- return the resulting balance

## 2.4 Print ministatemnt
- Show message that ministatement is being printed.
