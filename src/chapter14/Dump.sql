CREATE DATABASE  IF NOT EXISTS `exercise` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `exercise`;
-- MySQL dump 10.13  Distrib 5.7.9, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: exercise
-- ------------------------------------------------------
-- Server version	5.7.13

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `appartment`
--

DROP TABLE IF EXISTS `appartment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `appartment` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `buildingID` bigint(20) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `BuildingID_Building` (`buildingID`),
  CONSTRAINT `appartment_ibfk_1` FOREIGN KEY (`buildingID`) REFERENCES `building` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `appartment`
--

LOCK TABLES `appartment` WRITE;
/*!40000 ALTER TABLE `appartment` DISABLE KEYS */;
INSERT INTO `appartment` VALUES (1,1,'Casa Duranta'),(2,3,'Casello di LG'),(3,4,'Casa Capozza');
/*!40000 ALTER TABLE `appartment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `appartment_tenant`
--

DROP TABLE IF EXISTS `appartment_tenant`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `appartment_tenant` (
  `TenantID` bigint(20) NOT NULL,
  `AppartmentID` bigint(20) NOT NULL,
  PRIMARY KEY (`TenantID`,`AppartmentID`),
  KEY `AppartmentID_Appartment` (`AppartmentID`),
  CONSTRAINT `appartment_tenant_ibfk_1` FOREIGN KEY (`TenantID`) REFERENCES `tenant` (`ID`),
  CONSTRAINT `appartment_tenant_ibfk_2` FOREIGN KEY (`AppartmentID`) REFERENCES `appartment` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `appartment_tenant`
--

LOCK TABLES `appartment_tenant` WRITE;
/*!40000 ALTER TABLE `appartment_tenant` DISABLE KEYS */;
INSERT INTO `appartment_tenant` VALUES (1,1),(4,1),(2,2),(4,2),(3,3);
/*!40000 ALTER TABLE `appartment_tenant` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `building`
--

DROP TABLE IF EXISTS `building`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `building` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  `ComplexID` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ComplexID_Complex` (`ComplexID`),
  CONSTRAINT `building_ibfk_1` FOREIGN KEY (`ComplexID`) REFERENCES `complex` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `building`
--

LOCK TABLES `building` WRITE;
/*!40000 ALTER TABLE `building` DISABLE KEYS */;
INSERT INTO `building` VALUES (1,'Durante 24','Durante Milano',1),(2,'Hotel Durante','Durante 26',1),(3,'Casello','Melegnano 77',2),(4,'Capozzia','SanZeno',3);
/*!40000 ALTER TABLE `building` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `complex`
--

DROP TABLE IF EXISTS `complex`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `complex` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `complex`
--

LOCK TABLES `complex` WRITE;
/*!40000 ALTER TABLE `complex` DISABLE KEYS */;
INSERT INTO `complex` VALUES (1,'Durante 24'),(2,'Casello'),(3,'Capozzia');
/*!40000 ALTER TABLE `complex` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `request`
--

DROP TABLE IF EXISTS `request`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `request` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `AppartmentID` bigint(20) DEFAULT NULL,
  `status` varchar(100) DEFAULT NULL,
  `description` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ApparmentID_Appartment` (`AppartmentID`),
  CONSTRAINT `request_ibfk_1` FOREIGN KEY (`AppartmentID`) REFERENCES `appartment` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `request`
--

LOCK TABLES `request` WRITE;
/*!40000 ALTER TABLE `request` DISABLE KEYS */;
/*!40000 ALTER TABLE `request` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tenant`
--

DROP TABLE IF EXISTS `tenant`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tenant` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tenant`
--

LOCK TABLES `tenant` WRITE;
/*!40000 ALTER TABLE `tenant` DISABLE KEYS */;
INSERT INTO `tenant` VALUES (1,'Vika','Durante 24'),(2,'Grazia','Casello 77'),(3,'Capozzi','SanZeno 666'),(4,'MicioMao','Durante24'),(5,'Cika',''),(6,'PIDI',NULL);
/*!40000 ALTER TABLE `tenant` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-06-12 18:57:22
