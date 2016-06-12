#14.4 JOINS
_What are the different types of joins ? Please explain how they differ and why certain types are better in certain situations_


A join statement combine the rows in two tables by a predicate on the the values in a subset of their columns.

There exist the *CROSS* join *Cartesian Product* and the Natural join, then there are the *LEFT* and *RIGHT* joins and then there are *OUTER* and *INNER* joins.

## Cross
The *Cross* join will produce rows that combine each row from the first table to the second table. The base predicate is true.

## Natural
The natural join combines the rows in the tables by matching the values selecting the columns with the same name from each table.


## Inner Join
The Inner join row is created from each couple of rows that matches a predicate over the values of the columns. 
The predicate syntax is similar to the where clause and the deprecated implicit syntax is actually a where cause.
The explicit syntax uses the keyword JOIN to specify the other table and the keyword ON to mark the start of the predicate.

## Outer Join
The joined table retains their row even when there are no matching rows. By identifying the two sides of the JOIN keyword with left and right the *OUTER* join is further specialized in *LEFT*, *RIGHT* and *FULL* are keywords used to specify which table keeps its rows; either left, right or both tables.

In this kind of JOIN when for a source row does not exist a matching row, the resulting row will contains NULL value for each columns on the joining side.
