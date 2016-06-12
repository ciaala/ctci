DROP SCHEMA IF EXISTS exercise;
CREATE  SCHEMA exercise;
USE exercise;

CREATE TABLE Complex (
	ID BIGINT AUTO_INCREMENT PRIMARY KEY,
	`name` varchar(255)
    
);

CREATE TABLE Building (
    ID BIGINT AUTO_INCREMENT PRIMARY KEY,
    `ComplexID` BIGINT,
    `name` VARCHAR(255),
    `address` VARCHAR(255),
    FOREIGN KEY `ComplexID_Complex` (`ComplexID`) REFERENCES Complex (`ID`)
);

CREATE TABLE Tenant (
    ID BIGINT AUTO_INCREMENT,
    `name` VARCHAR(255),
    address VARCHAR(255),
    PRIMARY KEY (`ID`)
);

CREATE TABLE Appartment (
    ID BIGINT AUTO_INCREMENT,
    buildingID BIGINT,
    address VARCHAR(255),
    PRIMARY KEY (`ID`),
	FOREIGN KEY `BuildingID_Building` (`BuildingID`) REFERENCES Building (`ID`)
);


CREATE TABLE Appartment_Tenant 
(
	TenantID bigint,
    AppartmentID bigint,
    PRIMARY KEY (`TenantID`, `AppartmentID`),
    FOREIGN KEY `TenantID_Tenant` (`TenantID`) REFERENCES Tenant (`ID`),
    FOREIGN KEY `AppartmentID_Appartment` (`AppartmentID`) REFERENCES Appartment (`ID`)
);


CREATE TABLE Request
(

	ID bigint AUTO_INCREMENT PRIMARY KEY,
    AppartmentID bigint,
	`status` varchar(100),
	description varchar(500),
	
	FOREIGN KEY `ApparmentID_Appartment` (`AppartmentID`) REFERENCES Appartment (`ID`)
	
);


