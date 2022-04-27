```SQL
CREATE TABLE Reserves(sid INTEGER,bid INTEGER,day DATE,
    FOREIGN KEY(sid) REFERENCES Sailors,
    FOREIGN KEY(bid) REFERENCES Boats,
    CONSTRAINTS nointerlakeRES
    CHECK('Interlake'<>(
        SELECT B.bname
        FROM Boats B
        WHERE B.bid=Reserves.bid
    )))
```

```sql
CREATE DOMAIN ratingval INTEGER DEFAULT 1 CHECK(VALUE>=1 AND VALUE<=10>)
```

```SQL
CREATE TABLE Sailors(sid INTEGER,SNAME
                    sname CHAR(10),
                    rating INTEGER,
                    age REAL,
                    PRIMARY KEY(sid),
                    CHECK(rating>=1 and rating<=10)
                    CHECK((select count (S.sid)from sailors s))+
                    (select count(b.bid) from boats b)<100

)
```

```SQL
CREATE ASSERTION smallClub
CHECK ((select count(s.sid) from sailors s)+
        (select count(b.bid) from boats b)<100
    )
```

```sql
CREATE TRIGGER init_count BEFORE insertion students
    declare
        count integer;
    begin
        count:=0;
    end
```

```sql
create trigger incr_count after inssertion students
    when(new.age<18)
    FOR EACH ROW
    BEGIN   
        count:=count+1;
    END
```

```sql
create trigger set_count after insert on students
REFERENCING NEW TABLE AS insertedTuples
FOR EACH STATEMENT
INSERT
    INTO statisticsTable(modTable,ModType,Count)
    Select 'Students','insert',count *
    from insertedTuples I
    WHERE I.age<18
```

```sql
create trigger overdraft after update on Accounts
referencing new row as Nrows
For EACH ROW
WHEN Nrow.balance <0
BEGIN ATMOIC
    INSERT INTO Borrower
        (select customerName,accountNumber
        from Depositor D
        where Nrow.accoutnNumber = D.accountNumber);
    INSERT INTO Loan Values 
        (Nrows.accountNumber,Nrows.branchName - Nrows.balance);
    update Account SET balance=0
        WHERE Account.accountNumber = Nrows.accountNumber
END

```