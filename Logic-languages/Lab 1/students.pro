domains 
	lastname, group, district, grade, condition = symbol.

predicates
	%student(symbol,symbol, symbol,symbol,symbol).
	student(lastname, group, district, grade, condition).
	%grant(symbol,symbol).
	grant(lastname, condition).

clauses
 	student("Ivanov"   , "IU7-61", "Strogino"  , "A", "").
	student("Petrov"   , "IU7-63", "Chertanovo", "B", "scholar").
	student("Skvortcov", "IU7-62", "Kuncevo"   , "E", "").
	student("Smirnov"  , "IU7-65", "Bibirevo"  , "C", "scholar").
	student("Kozlov"   , "IU7-63", "Ramenki"   , "C", "orphan").
	student("Novikov"  , "IU7-64", "Myakinino" , "D", "scholar").
	student("Kuznecov" , "IU7-63", "Arbat"     , "E", "scholar").
	student("Popov"    , "IU7-65", "Myakinino" , "B", "").
	student("Sokolov"  , "IU7-62", "Kuncevo"   , "A", "orphan").
	student("Lebedev"  , "IU7-61", "Kurkino"   , "B", "scholar").
	student("Morozov"  , "IU7-65", "Kuncevo"   , "B", "").
	student("Petrov"   , "IU7-63", "Ramenki"   , "C", "orphan").
	student("Volkov"   , "IU7-62", "Strogino"  , "A", "orphan").
	student("Vasilev"  , "IU7-64", "Strogino"  , "B", "scholar").
	student("Pavlov"   , "IU7-61", "Ramenki"   , "D", "orphan").
	%student("A", "IU7-61", "Ramenki", "A","orphan").
	
	grant(Lastname, Condition) :- student(Lastname, _, _, _, Condition).

goal
 	% Students that are in the same group
	%student(Lastname, "IU7-61", _, _, _).
	%student(Lastname, "IU7-62", _, _, _).
	%student(Lastname, "IU7-63", _, _, _).
	%student(A,_,_,_,_),student(B,_,_,A,_).
	% Students that are in the same group and district
	%student(Lastname, "IU7-63", "Ramenki", _, _).
	
	% Students that are have grant
	grant(Lastname, "scholar").
