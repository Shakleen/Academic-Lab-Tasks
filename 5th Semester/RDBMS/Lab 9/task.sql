create table AccountProperties (
    id integer,
    name varchar2(30),
    iRate number,
    gp integer,
    constraint pk_ap_id primary key(id)
);

insert into AccountProperties values (1, 'daily', 0.0004, 1);
insert into AccountProperties values (2, 'monthly', 0.0005, 2);
insert into AccountProperties values (3, 'quarterly', 0.0055, 3);
insert into AccountProperties values (4, 'biyearly', 0.0006, 4);
insert into AccountProperties values (5, 'yearly', 0.0065, 5);

create table Accounts (
    id integer,
    name varchar2(30),
    accCode integer,
    balance number,
    lastDateInterest date,
    constraint pk_ac_id primary key(id),
    constraint pk_ac_acc foreign key(accCode) references AccountProperties(id)
);

insert into Accounts values(1, 'ishrak', 1, 2000, to_date('01/01/2018', 'DD/MM/YYYY'));
insert into Accounts values(2, 'ishfar', 2, 2000, to_date('01/04/2018', 'DD/MM/YYYY'));
insert into Accounts values(3, 'abir', 3, 2000, to_date('01/07/2018', 'DD/MM/YYYY'));
insert into Accounts values(4, 'lami', 4, 2000, to_date('01/08/2019', 'DD/MM/YYYY'));
insert into Accounts values(5, 'ovi', 5, 2000, to_date('01/09/2018', 'DD/MM/YYYY'));
insert into Accounts values(6, 'shihan', 1, 2000, to_date('01/11/2018', 'DD/MM/YYYY'));
insert into Accounts values(7, 'himel', 2, 2000, to_date('01/02/2018', 'DD/MM/YYYY'));
insert into Accounts values(8, 'shishir', 4, 2000, to_date('01/06/2018', 'DD/MM/YYYY'));
insert into Accounts values(9, 'rukon', 3, 2000, to_date('01/09/2019', 'DD/MM/YYYY'));
insert into Accounts values(10, 'angel', 5, 2000, to_date('01/11/2017', 'DD/MM/YYYY'));

-- Task 1
CREATE OR REPLACE function Profit(aid IN integer) return number is
    bal number := 0;
    rate number := 0;
    accType integer := 0;
    daysSinceLast integer := 0;
    total number := 0;
    gp number := 0;
    prof number := 0;
begin  
    select accCode, balance, SysDate - lastDateInterest
    into accType, bal, daysSinceLast
    from Accounts 
    where Accounts.id = aid;

    select iRate
    into rate
    from AccountProperties
    where gp = accType;

    dbms_output.put_line('Number of days passed is ' || daysSinceLast);

    total := bal;

    if (accType = 2) then
        gp := daysSinceLast / 30;
    elsif (accType = 3) then
        gp := daysSinceLast / 90;
    elsif (accType = 4) then
        gp := daysSinceLast / 180;
    elsif (accType = 5) then
        gp := daysSinceLast / 365;
    else
        gp:= daysSinceLast;
    end if;

    dbms_output.put_line('GP ' || gp || ' rate ' || rate);

    for i in 1 .. gp loop
      total := total + total * rate;
    end loop;

    prof := total-bal;
    dbms_output.put_line('Total ' || total);
    dbms_output.put_line('Profit ' || prof);

    return prof;
end;
/

SET SERVEROUTPUT ON;
Declare
    prof number := 0;
BEGIN
    prof := Profit(1);
END;
/

DECLARE
    id integer := 0;
    prof number := 0;
    cursor acc is select * from Accounts;    
BEGIN
    for account in acc
    loop
        id := account.id;
        prof := Profit(id);
        dbms_output.put_line('Profit for ' || account.id || ' is ' || prof); 
        update accounts set balance = balance + prof where id = account.id;
    end loop;
END;
/