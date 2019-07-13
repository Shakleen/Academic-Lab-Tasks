-- Products Table
create table Products (
    ProductID varchar2(10) NOT NULL,
    Seller varchar2(50) NOT NULL,
    Name varchar2(50) NOT NULL,
    Description varchar2(100),
    Type varchar2(50) NOT NULL,
    Brand varchar2(50) NOT NULL,
    Rating number,
    Price number NOT NULL,
    StockUnits integer NOT NULL,
    WarrantyPeriod varchar2(50) NOT NULL,
    ReleaseDate Date,
    CONSTRAINT pk_products_pid Primary Key (ProductID),
    CONSTRAINT check_products_rating check (Rating >= 0 AND Rating <= 5),
    CONSTRAINT check_products_stock check (StockUnits >= 0),
    CONSTRAINT check_products_price check (Price >= 0)
);

-- Sequence For product ID
create Sequence ProductNo minvalue 1 maxvalue 1000 start with 1 increment by 1 cache 10;

-- Function to generate unique product ID
CREATE OR REPLACE function GenerateProductID(name in varchar2, brand in varchar2, type in varchar2, seller in varchar2) return varchar2 is
    productID varchar2(10);
begin  
    productID := SUBSTR(seller, 1, 1) || SUBSTR(name, 1, 1) || SUBSTR(brand, 1, 1) || 
                 SUBSTR(type, 1, 1) || LPAD(TO_CHAR(ProductNo.NEXTVAL), 4, '0');
    return productID;
end;
/

-- Function to calculate discount
CREATE OR REPLACE function CutPrice(percentage in number, price in number) return number is
    newPrice number := 0;
begin  
    newPrice := price - price * (percentage / 100);
    return newPrice;
end;
/

-- Function to calculate rating
CREATE OR REPLACE Procedure RateProduct(prodID in VARCHAR2, newRating in number) is
    r number := 0;
    finalRating number := 0;
begin  
    SELECT Rating INTO r FROM Products WHERE ProductID = prodID;

    if r = 0 then
        update Products set Rating = newRating where productID = prodID;
        dbms_output.put_line('Rating set to ' || newRating);
    else
        finalRating := (r + newRating) / 2;
        update Products set Rating = finalRating where productID = prodID;
        dbms_output.put_line('Rating set to ' || finalRating);
    end if;
end;
/

-- Function for product purchase
CREATE OR REPLACE Procedure PurchaseProduct(prodID in VARCHAR2) is
    stock number := 0;
begin
    SELECT StockUnits INTO stock FROM Products WHERE productID = prodID;
    
    if stock > 0 then
      update Products set StockUnits = stock-1 where productID = prodID;
    end if;
end;
/

-- Trigger for product insertion
CREATE OR REPLACE TRIGGER Product_Add_Trigger
BEFORE insert ON Products
FOR EACH ROW
DECLARE
    s varchar2(50);
    n varchar2(50);
    t varchar2(50);
    b varchar2(50);
    d varchar2(100);
    release date;
BEGIN
    s := :NEW.Seller;
    n := :NEW.Name;
    t := :NEW.Type;
    b := :NEW.Brand;
    d := :NEW.Description;
    SELECT Systimestamp INTO release FROM dual;

    :NEW.ProductID := GenerateProductID(n, b, t, s);
    :NEW.rating := 0;
    :NEW.ReleaseDate := release;

    if Length(d) <= 0 then
      :NEW.Description := 'Not Available';
    end if;
END;
/

-- Adding a new product minimum
insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('StarTech', 'Hammer Head', 'Electronic', 'Razer', 5500, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('StarTech', 'Hammer Head USB', 'Electronic', 'Razer', 5800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('StarTech', 'Kraken V2', 'Electronic', 'Razer', 7800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('StarTech', 'Huntsman', 'Electronic', 'Razer', 12500, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('StarTech', 'Mamba Elite', 'Electronic', 'Razer', 7800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('Amazon', 'Raptor', 'Electronic', 'Razer', 45800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('Amazon', 'Blade 15', 'Electronic', 'Razer', 245800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('Amazon', 'Blade 17 Pro', 'Electronic', 'Razer', 275800, 10, '2 Years');

insert into Products (Seller, Name, Type, Brand, Price, StockUnits, WarrantyPeriod)
values ('Amazon', 'Blade 13 Stealth', 'Electronic', 'Razer', 175800, 10, '2 Years');


-- Delete product
delete from Products where ProductID = 'SHRH0001'


-- Edit product
update Products set field=value where ProductID = 'SHRH0001'


-- Tests

-- Test Generate Product ID
-- SET SERVEROUTPUT ON;
-- Declare
--     productID varchar2(10);
-- BEGIN
--     productID := GenerateProductID('Hammer Head', 'Razer', 'HeadPhone', 'Start Tech');
--     dbms_output.put_line(productID);
-- END;
-- /

-- Test Price Cut method
-- SET SERVEROUTPUT ON;
-- Declare
--     newPrice number := 0;
-- BEGIN
--     newPrice := CutPrice(33, 90);
--     dbms_output.put_line(newPrice);
-- END;
-- /

-- Test avergae rating
-- SET SERVEROUTPUT ON;
-- Declare
--     avgRating number := 0;
-- BEGIN
--     RateProduct('SHRH0001', 5);
-- END;
-- /


-- conn sys as sysdba
-- dragonsword05
-- drop user ishrak cascade;
-- create user ishrak identified by dragonsword05;
-- grant all privileges to ishrak;
-- disc;
-- conn ishrak/dragonsword05;