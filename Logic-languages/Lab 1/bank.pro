domains
	lastname, bank = symbol.
	money, minmoney = integer. 

predicates
	deposit(lastname, bank, integer).
	depositor(lastname, bank, money, minmoney).

clauses
	deposit("Ivanov"   , sberbank, 1000).
	deposit("Petrov"   , citibank, 5000).
	deposit("Skvortcov", rsb     , 4999).
	deposit("Smirnov"  , tinkoff , 2999).
	deposit("Kozlov"   , rsb     , 10000).
	deposit("Novikov"  , sberbank, 3549).
	deposit("Kuznecov" , sberbank, 9999).
	deposit("Popov"    , tinkoff , 20000).
	deposit("Sokolov"  , tinkoff , 20001).
	deposit("Lebedev"  , rsb     , 15499).
	deposit("Morozov"  , sberbank, 2500).
	deposit("Petrov"   , vtb     , 5555).
	deposit("Volkov"   , vtb     , 300).
	deposit("Vasilev"  , rsb     , 7890).
	deposit("Pavlov"   , vtb     , 200).
	
	depositor(Lastname, Bank, Money, MinMoney) :- 
		deposit(Lastname, Bank, Money), 
		Money > MinMoney.

goal
	depositor(Lastname, sberbank, Money, 1000).
