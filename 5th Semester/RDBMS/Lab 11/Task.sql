-- Task 1
create table salary (
    id number,
    name varchar2(10),
    salary number,
    constraint pk_salary_id primary key(id)
);

insert into salary values (1, 'ishrak', 1000);
insert into salary values (2, 'ishfar', 2000);
insert into salary values (3, 'shakleen', 3000);
insert into salary values (4, 'shoumo', 4000);
insert into salary values (5, 'nahid', 5000);

SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER salary_trigger
BEFORE UPDATE ON salary
FOR EACH ROW
BEGIN
    dbms_output.put_line('Old salary is ' || :OLD.salary);
    dbms_output.put_line('New salary is ' || :NEW.salary);
END;
/

update salary set salary=2000 where id = 1;

-- Task 2
create table iut (
    id varchar2(8),
    dot date,
    dept varchar2(1),
    prog varchar2(1),
    section varchar2(1)
);

SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER auto_gen_id_trigger
BEFORE insert ON iut
FOR EACH ROW
DECLARE
    admission varchar2(10);
    d varchar2(10);
    p varchar2(10);
    s varchar2(10);
    xxx varchar2(10);
    gen_ID varchar2(10);
BEGIN
    admission := TO_CHAR(:NEW.dot, 'YYYY');
    dbms_output.put_line('YYYY is ' || admission);

    admission := SUBSTR(admission, 3, 2);
    dbms_output.put_line('YY is ' || admission);

    d := :NEW.dept;
    dbms_output.put_line('D is ' || d);

    p := :NEW.prog;
    dbms_output.put_line('P is ' || p);

    s := :NEW.section;
    dbms_output.put_line('S is ' || s);

    xxx := TO_CHAR(auto_id.NEXTVAL);
    xxx := LPAD(xxx, 3, '0');
    dbms_output.put_line('xxx is ' || xxx);

    dbms_output.put_line('Calling GENID');
    gen_ID := GenID(xxx, admission, d, p, s);
    dbms_output.put_line('GEN ID is ' || gen_ID);

    :NEW.id := gen_ID;
END;
/


CREATE OR REPLACE function GenID
(
    sid in varchar2,
    dot in varchar2, 
    deptID in varchar2, 
    progID in varchar2, 
    secID in varchar2
) return varchar2 is
    id varchar2(8);
begin  
    id := dot || deptID || progID || secID || sid;
    return id;
end;
/

CREATE SEQUENCE auto_id
MINVALUE 1
MAXVALUE 999
START WITH 1
INCREMENT BY 1
CACHE 10;

insert into iut values (NULL, to_date('01/01/2018', 'DD/MM/YYYY'), '1', '1', '1');