-- A
CREATE TABLE Occupation (
    ID NUMBER,
    General VARCHAR2(20),
    Specific VARCHAR2(20),
    Salary NUMBER,
    CONSTRAINT PK_OCP_ID PRIMARY KEY(ID),
    CONSTRAINT CHK_OCP_General CHECK (General IN ('Teacher', 'Student', 'Engineer')),
    CONSTRAINT CHK_OCP_Specific CHECK (Specific IN ('School', 'University', 'CSE', 'Mechanical'))
);

INSERT INTO Occupation VALUES (1, 'Teacher', 'School', 20000);
INSERT INTO Occupation VALUES (1, 'Teacher', 'University', 50000);
INSERT INTO Occupation VALUES (1, 'Teacher', 'School', 25000);
INSERT INTO Occupation VALUES (1, 'Teacher', 'University', 70000);
INSERT INTO Occupation VALUES (1, 'Student', 'School', 9000);
INSERT INTO Occupation VALUES (1, 'Student', 'University', 2000);
INSERT INTO Occupation VALUES (1, 'Student', 'School', 3000);
INSERT INTO Occupation VALUES (1, 'Student', 'University', 10000);
INSERT INTO Occupation VALUES (1, 'Student', 'University', 20000);
INSERT INTO Occupation VALUES (1, 'Engineer', 'CSE', 200000);
INSERT INTO Occupation VALUES (1, 'Engineer', 'Mechanical', 120000);
INSERT INTO Occupation VALUES (1, 'Engineer', 'Mechanical', 320000);
INSERT INTO Occupation VALUES (1, 'Engineer', 'CSE', 220000);


-- A 1
