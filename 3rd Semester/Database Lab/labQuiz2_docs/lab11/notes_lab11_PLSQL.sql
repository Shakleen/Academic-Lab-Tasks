-- this block of code adds two variables and show the result. 

DECLARE 
	N1 NUMBER;
	N2 NUMBER;
	RESULT NUMBER;

BEGIN
	N1:=4;
	N2:=5;
	RESULT := N1+N2;
	DBMS_OUTPUT.PUT_LINE(RESULT);
END;
/

-- if we execute this in the SQL CMD, no output will be shoun. To see the output we have to write
SET SERVEROUT ON
/

-- show the salary of the citizen who have ID=5;

DECLARE
VAR_SALARY NUMBER;

BEGIN
	SELECT SALARY INTO VAR_SALARY
	FROM CITIZEN
	WHERE c_ID=5;

	DBMS_OUTPUT.PUT_LINE('The salary is '|| VAR_SALARY);
END;
/

-- the next program is the modified version of it!
DECLARE
VAR_SALARY NUMBER;
name varchar2(30);
BEGIN
SELECT SALARY,C_NAME INTO VAR_SALARY,name
FROM CITIZEN
WHERE c_ID=5;

DBMS_OUTPUT.PUT_LINE('The salary of '||name||' is '|| VAR_SALARY);
END;
/

-- How to write function in PL/SQL

-- the following function will take two numbers and return the addition of them.

CREATE OR REPLACE PROCEDURE ggADDITION(NUM1 IN NUMBER, NUM2 IN NUMBER, x OUT NUMBER) AS 
BEGIN
	x:= NUM1+NUM2;
END;
/

--NOW LET'S CALL THIS FUNCTION

DECLARE
NUM1 NUMBER;
NUM2 NUMBER;
x NUMBER;

BEGIN
	NUM1:=5;
	NUM2:=100;
	ggADDITION(NUM1,NUM2,x);
	DBMS_OUTPUT.PUT_LINE('The addition is '|| x);
END;
/

-- var name SUM is a keyword. So can't use that.

-- Now Let's write a PL/SQL function which will comment on the age of the citizen. Let's set the rule as, if age<18 then TEEN AGE, if age>18 && <30 then Middle aged. Other wise he is Old.

--works

CREATE OR REPLACE PROCEDURE GGAGE(ID IN NUMBER) AS

TEMP NUMBER;

BEGIN 
	SELECT AGE INTO TEMP
	FROM CITIZEN
	WHERE C_ID=ID;


	IF (TEMP<18)	THEN DBMS_OUTPUT.PUT_LINE('TEEN');
	ELSIF (TEMP BETWEEN 18 AND 30) THEN DBMS_OUTPUT.PUT_LINE('Middle');
	ELSE DBMS_OUTPUT.PUT_LINE('OLD');
	END IF;

END GGAGE;
/

DECLARE 
	ID NUMBER;

BEGIN
	ID:=5;
	ggAGE(ID);
--DBMS_OUTPUT.PUT_LINE(COMMENT);
END;
/






CREATE OR REPLACE PROCEDURE ggage(ID IN NUMBER,COMMENT OUT varchar2 ) AS
TEMP NUMBER;
BEGIN 
SELECT AGE INTO TEMP
FROM CITIZEN
WHERE C_ID=ID;
IF (TEMP<18)	THEN COMMENT:='TEEN AGER';
ELSIF (TEMP BETWEEN 18 AND 30) THEN COMMENT:='Middle aged';
ELSE COMMENT:= 'OLD';
END IF;
END ggage;
/

DECLARE 
ID NUMBER;
COMMENT varchar2(20);
BEGIN
ID:=5;
ggage(5,COMMENT);
DBMS_OUTPUT.PUT_LINE(COMMENT);
END;
/



--TRIGGER--


  CREATE OR REPLACE TRIGGER T_DEMO 
  AFTER UPDATE ON CITIZEN 
  BEGIN

  DBMS_OUTPUT.PUT_LINE('HELLO WORLD');

  END;
