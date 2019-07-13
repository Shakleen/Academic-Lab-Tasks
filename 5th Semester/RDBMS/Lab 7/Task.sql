-- Task A1
CREATE OR REPLACE PROCEDURE PROC1(STR IN VARCHAR2) AS
len number := 0;
begin
  len := length(STR);

    for i in 1 .. len loop
      dbms_output.put_line(substr(STR, i, 1));
    end loop;
end;
/

SET SERVEROUTPUT ON;
DECLARE 
STR VARCHAR2(100);
begin
  STR := 'ABC';
  PROC1(STR);
end;
/

-- Task A2
CREATE OR REPLACE PROCEDURE PROC2(STR IN VARCHAR2) AS
len number := 0;
pal boolean := true;
begin
  len := length(STR);

    for i in 1 .. len loop
      if substr(STR, i, 1) != substr(STR, len-i+1, 1) then
        pal := false;
      end if;
    end loop;

    if pal = true then
      dbms_output.put_line('Yes');
    else
      dbms_output.put_line('No');
    end if;
end;
/

SET SERVEROUTPUT ON;
DECLARE 
STR VARCHAR2(100);
begin
  STR := 'ABCBC';
  PROC2(STR);
end;
/

-- Task B
CREATE OR REPLACE PROCEDURE PROC3 AS
year number := 0;
begin
  SELECT extract(year from SysDate) INTO year FROM DUAL;

  if MOD(year, 10) = 0 then
    dbms_output.put_line('Yes');
  else
    dbms_output.put_line('No');
  end if;

  dbms_output.put_line(year - MOD(year, 10));
end;
/

SET SERVEROUTPUT ON;
DECLARE 
begin
  PROC3();
end;
/

-- Task C
CREATE OR REPLACE PROCEDURE PROC4(n IN number, itr IN NUMBER) AS
begin
    for num in 1 .. n loop
    dbms_output.put_line(num || ' Table');
      for num2 in 1 .. itr loop
        dbms_output.put_line(num || '*' || num2 || '=' || num*num2);
      end loop;
    end loop;
end;
/

SET SERVEROUTPUT ON;
DECLARE 
begin
  PROC4(2, 3);
end;
/