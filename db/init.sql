-- Create the database
CREATE DATABASE bm_db;

-- Use the database
USE bm_db;

-- Create the patients table
CREATE TABLE patients (
    ssn CHAR(10) NOT NULL,
    mail VARCHAR(128) NOT NULL,
    name VARCHAR(50) NOT NULL,
    PRIMARY KEY (ssn)
);

-- Create the measurements table
CREATE TABLE measurements (
    id INT UNSIGNED AUTO_INCREMENT,
    ssn CHAR(10) NOT NULL,
    date CHAR(19) NOT NULL,
    systolic INT UNSIGNED NOT NULL,
    diastolic INT UNSIGNED NOT NULL,
    seen TINYINT UNSIGNED NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (ssn) REFERENCES patients(ssn) ON DELETE CASCADE
);

-- Optional: Add indexes to improve performance on frequently queried columns
CREATE INDEX idx_measurement_date ON measurements(date);
CREATE INDEX idx_measurement_ssn ON measurements(ssn);

-- Optional: Add some sample data to test the schema
INSERT INTO patients (ssn, mail, name) VALUES 
(   '1234567590', 
    'Mette@outlook.com', 
    'Mette Lykke Slot'
);

INSERT INTO patients (ssn, mail, name) VALUES 
(   '1234567891', 
    'Benny@gmail.com', 
    'Benny Hansen'
);

INSERT INTO patients (ssn, mail, name) VALUES 
(   '1234567893', 
    'Jens@hotmail.com', 
    'Jens løg Hansen'
);

INSERT INTO measurements (ssn, date, systolic, diastolic, seen) 
VALUES 
('1234567891', '2023-11-07 12:30:00', 120, 80, 1),
('1234567893', '2023-11-08 14:15:00', 130, 85, 0);
