# 14.5 Denormalization
_What is the denormalization ? Explain the pros and cons._

Denormalization is a technique to improve the read performance of a database by organizing the data that are commonly loaded together in a single table _denormalizing_ the database and avoiding executing expensive joins. These technique is useful to improve scalability of the database and improve the performance perceived by the end user.
 On the contrary this technique introduces data duplication to avoid the join operations and so requires the application logic to keep track of the repeated values while doing update operations to maintain consistency in the data.
 
 A database in a _denormalized_ form has been first normalized and then destructured, by for example violating the 3 normal form; _Denormalization_ should not be considered an unstructured form.
 