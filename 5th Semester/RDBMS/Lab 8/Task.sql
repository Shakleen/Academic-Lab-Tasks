-- task 1
create table employee(
    id number,
    name varchar2(25),
    salary number,
    designation varchar2(25),
    constraint pk_eid primary key(id)
);

insert into employee values(1, 'ishrak', 3000, 'officer');
insert into employee values(2, 'ishfar', 5000, 'teacher');
insert into employee values(3, 'ovi', 3500, 'assistant-officer');
insert into employee values(4, 'abir', 4000, 'officer');
insert into employee values(5, 'lami', 4000, 'teacher');
insert into employee values(6, 'oishee', 4000, 'assistant-officer');

SET SERVEROUTPUT ON;
DECLARE
    total_rows number(2);
BEGIN
    UPDATE employee
    SET salary = salary + salary * 0.5
    WHERE salary < 5000 AND designation in ('officer', 'assistant-officer');
    IF sql%notfound THEN
        dbms_output.put_line(’no customers selected’);
    ELSIF sql%found THEN
        total_rows := sql%rowcount;
        dbms_output.put_line( total_rows || ’ customers selected ’);
    END IF;
END;
/

-- Task 2
create table transactions (
    user_id number,
    amount number,
    t_date date
);

insert into transactions values (1, 500000, to_date('01/01/2019', 'DD/MM/YYYY'));
insert into transactions values (1, 800000, to_date('02/02/2019', 'DD/MM/YYYY'));
insert into transactions values (1, 300000, to_date('03/03/2019', 'DD/MM/YYYY'));
insert into transactions values (1, 700000, to_date('05/04/2019', 'DD/MM/YYYY'));
insert into transactions values (2, 300000, to_date('05/05/2019', 'DD/MM/YYYY'));
insert into transactions values (2, 200000, to_date('01/06/2019', 'DD/MM/YYYY'));
insert into transactions values (2, 100000, to_date('01/07/2019', 'DD/MM/YYYY'));
insert into transactions values (2, 300000, to_date('01/08/2019', 'DD/MM/YYYY'));
insert into transactions values (3, 100000, to_date('01/09/2019', 'DD/MM/YYYY'));
insert into transactions values (3, 400000, to_date('01/10/2019', 'DD/MM/YYYY'));
insert into transactions values (3, 500000, to_date('01/11/2019', 'DD/MM/YYYY'));
insert into transactions values (3, 900000, to_date('01/12/2019', 'DD/MM/YYYY'));

create table loan_type(
    scheme number,
    installment_number number,
    charge number,
    min_transaction number,
    constraint pk_scheme primary key(scheme)
);

insert into loan_type values (1, 30, 5, 2000000);
insert into loan_type values (2, 20, 10, 1000000);
insert into loan_type values (3, 15, 15, 500000);

CREATE OR REPLACE function getTotalTransaction(id IN number) return number is
    total_transaction number := 0;
    cursor user_transaction is
        select user_id, amount from transactions where user_id = id;
begin  
  for transaction in user_transaction
  loop
    total_transaction := total_transaction + transaction.amount;
  end loop;

  return total_transaction;
end;
/

DECLARE
    user_transaction number := 0;
    cursor schemes is 
    select * from loan_type;    
BEGIN
    user_transaction := getTotalTransaction(4);
    for scheme in schemes
    loop
        if user_transaction >= scheme.min_transaction then
            dbms_output.put_line('Scheme selected is ' || scheme.scheme);
            exit;
        end if;
    end loop;
END;
/

