```sql
--2
DECLARE
  v_birthdate   DATE := TO_DATE('1990-01-01', 'YYYY-MM-DD');  -- Przykładowa data urodzin
  v_current_date DATE := SYSDATE;
  v_days        NUMBER;
  v_weeks       NUMBER;
  v_months      NUMBER;
BEGIN
  -- Obliczanie liczby dni, tygodni i miesięcy, które minęły od daty urodzin
  v_days := ROUND(v_current_date - v_birthdate);
  v_weeks := ROUND((v_current_date - v_birthdate) / 7);
  v_months := ROUND(MONTHS_BETWEEN(v_current_date, v_birthdate));
  
  -- Wyświetlanie wyników
  DBMS_OUTPUT.PUT_LINE('Data urodzin: ' || TO_CHAR(v_birthdate, 'DD-MON-YYYY'));
  DBMS_OUTPUT.PUT_LINE('Bieżąca data: ' || TO_CHAR(v_current_date, 'DD-MON-YYYY'));
  DBMS_OUTPUT.PUT_LINE('Minęło dni: ' || v_days);
  DBMS_OUTPUT.PUT_LINE('Minęło tygodni: ' || v_weeks);
  DBMS_OUTPUT.PUT_LINE('Minęło miesięcy: ' || v_months);
END;
/
```


--3
DECLARE
  CURSOR c_min_sal IS
    SELECT empno, ename, sal
    FROM emp
    WHERE sal = (SELECT MIN(sal) FROM emp);

  CURSOR c_max_sal IS
    SELECT empno, ename, sal
    FROM emp
    WHERE sal = (SELECT MAX(sal) FROM emp);
BEGIN
  -- Wyświetlanie pracowników zarabiających najmniej
  DBMS_OUTPUT.PUT_LINE('Pracownicy zarabiający najmniej:');
  FOR r_min IN c_min_sal LOOP
    DBMS_OUTPUT.PUT_LINE('Empno: ' || r_min.empno || ', Ename: ' || r_min.ename || ', Salary: ' || r_min.sal);
  END LOOP;

  -- Wyświetlanie pracowników zarabiających najwięcej
  DBMS_OUTPUT.PUT_LINE('Pracownicy zarabiający najwięcej:');
  FOR r_max IN c_max_sal LOOP
    DBMS_OUTPUT.PUT_LINE('Empno: ' || r_max.empno || ', Ename: ' || r_max.ename || ', Salary: ' || r_max.sal);
  END LOOP;
END;
/
```

```sql
--4a
DECLARE
  CURSOR emp_cursor IS
    SELECT empno, ename, job, sal
    FROM emp;
  emp_record emp%ROWTYPE;
BEGIN
  OPEN emp_cursor;
  LOOP
    FETCH emp_cursor INTO emp_record;
    EXIT WHEN emp_cursor%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('Empno: ' || emp_record.empno || ', Ename: ' || emp_record.ename || ', Job: ' || emp_record.job || ', Salary: ' || emp_record.sal);
  END LOOP;
  CLOSE emp_cursor;
END;
/

--4b
BEGIN
  FOR emp_record IN (SELECT empno, ename, job, sal FROM emp) LOOP
    DBMS_OUTPUT.PUT_LINE('Empno: ' || emp_record.empno || ', Ename: ' || emp_record.ename || ', Job: ' || emp_record.job || ', Salary: ' || emp_record.sal);
  END LOOP;
END;
/
```