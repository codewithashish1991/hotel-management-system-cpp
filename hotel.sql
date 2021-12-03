-- phpMyAdmin SQL Dump
-- version 4.6.6deb5ubuntu0.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Dec 03, 2021 at 07:06 PM
-- Server version: 5.7.36-0ubuntu0.18.04.1
-- PHP Version: 7.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `hotel`
--

-- --------------------------------------------------------

--
-- Table structure for table `checkin`
--

CREATE TABLE `checkin` (
  `sid` int(11) NOT NULL,
  `cnumber` varchar(100) NOT NULL,
  `rid` varchar(11) NOT NULL,
  `opendate` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `engagedate` varchar(50) NOT NULL,
  `engagecash` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `checkin`
--

INSERT INTO `checkin` (`sid`, `cnumber`, `rid`, `opendate`, `engagedate`, `engagecash`) VALUES
(2, '2121', '25', '2021-11-30 16:29:46', '12', '23,232.00');

-- --------------------------------------------------------

--
-- Table structure for table `checkout`
--

CREATE TABLE `checkout` (
  `sid` int(11) NOT NULL,
  `cnumber` varchar(255) NOT NULL,
  `rid` int(11) NOT NULL,
  `opendate` datetime NOT NULL,
  `closedate` datetime NOT NULL,
  `cash` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `checkout`
--

INSERT INTO `checkout` (`sid`, `cnumber`, `rid`, `opendate`, `closedate`, `cash`) VALUES
(1, '23', 13, '2021-11-26 18:54:50', '2021-11-26 18:55:14', '0'),
(2, '2154', 25, '2021-11-30 16:28:51', '2021-11-30 16:29:25', '0');

-- --------------------------------------------------------

--
-- Table structure for table `client`
--

CREATE TABLE `client` (
  `cnumber` varchar(100) NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `client`
--

INSERT INTO `client` (`cnumber`, `name`) VALUES
('123', 'Ashish'),
('23', 'Ashish'),
('2154', 'Ashish'),
('2121', 'Ashish');

-- --------------------------------------------------------

--
-- Table structure for table `room`
--

CREATE TABLE `room` (
  `rid` int(11) NOT NULL,
  `tid` int(11) NOT NULL COMMENT 'room type id',
  `state` varchar(10) NOT NULL COMMENT 'Occupy/idle',
  `foregift` varchar(255) NOT NULL COMMENT 'advance fee'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `room`
--

INSERT INTO `room` (`rid`, `tid`, `state`, `foregift`) VALUES
(1, 1, 'idle', '23,232.00'),
(2, 1, 'Occupy', '10,232.00'),
(3, 1, 'idle', '13,232.00'),
(4, 1, 'Occupy', '10,232.00'),
(5, 2, 'idle', '23,232.00'),
(6, 2, 'Occupy', '10,232.00'),
(7, 2, 'idle', '13,232.00'),
(8, 2, 'Occupy', '10,232.00'),
(9, 3, 'idle', '23,232.00'),
(10, 3, 'Occupy', '10,232.00'),
(11, 4, 'idle', '13,232.00'),
(12, 4, 'Occupy', '10,232.00'),
(13, 5, 'idle', '23,232.00'),
(14, 5, 'Occupy', '10,232.00'),
(15, 6, 'idle', '13,232.00'),
(16, 6, 'Occupy', '10,232.00'),
(17, 1, 'idle', '23,232.00'),
(18, 1, 'Occupy', '10,232.00'),
(19, 1, 'idle', '13,232.00'),
(20, 1, 'Occupy', '10,232.00'),
(21, 2, 'idle', '23,232.00'),
(22, 2, 'Occupy', '10,232.00'),
(23, 2, 'idle', '13,232.00'),
(24, 2, 'Occupy', '10,232.00'),
(25, 3, 'idle', '23,232.00'),
(26, 3, 'Occupy', '10,232.00'),
(27, 4, 'idle', '13,232.00'),
(28, 4, 'Occupy', '10,232.00'),
(29, 5, 'idle', '23,232.00'),
(30, 5, 'Occupy', '10,232.00'),
(31, 6, 'idle', '13,232.00'),
(32, 6, 'Occupy', '10,232.00');

-- --------------------------------------------------------

--
-- Table structure for table `roomtype`
--

CREATE TABLE `roomtype` (
  `tid` int(11) NOT NULL,
  `roomtype` varchar(150) NOT NULL,
  `amount` varchar(150) NOT NULL,
  `price` varchar(150) NOT NULL,
  `deposit` varchar(150) NOT NULL,
  `describe` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `roomtype`
--

INSERT INTO `roomtype` (`tid`, `roomtype`, `amount`, `price`, `deposit`, `describe`) VALUES
(1, 'Presidential suite', '23000.00', '25000.00', '12000.00', 'Presidential suite and Royal suite are common names for the most expensive suite in a luxury hotel.'),
(2, 'Business suite', '33000.00', '35000.00', '22000.00', 'Business suite and Royal suite are common names for the most expensive suite in a luxury hotel.'),
(3, 'Deluxe single room', '13000.00', '15000.00', '8000.00', 'Deluxe Single Rooms are single occupancy rooms that offer the best value for money. These no-frills rooms are equipped with all modern hotel amenities, top end toiletries and comfortable beds.'),
(4, 'Deluxe double room', '23000.00', '48000.00', '20000.00', 'Deluxe Double Rooms are double occupancy rooms that offer the best value for money. These no-frills rooms are equipped with all modern hotel amenities, top end toiletries and comfortable beds.'),
(5, 'Standard single room', '113000.00', '115000.00', '80000.00', 'Standard Single Rooms provide a twin bed, a private half bathroom (including a sink and toilet), a writing desk, an in-room safe, television, complimentary wifi internet access, daily housekeeping and air conditioning. '),
(6, 'Standard double room', '123000.00', '148000.00', '120000.00', 'Standard Double Rooms provide a twin bed, a private half bathroom (including a sink and toilet), a writing desk, an in-room safe, television, complimentary wifi internet access, daily housekeeping and air conditioning. ');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `id` int(11) NOT NULL,
  `sid` varchar(80) NOT NULL,
  `name` varchar(100) NOT NULL,
  `email` varchar(255) NOT NULL,
  `designation` varchar(150) NOT NULL,
  `pwd` varchar(50) NOT NULL,
  `date_of_joining` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`id`, `sid`, `name`, `email`, `designation`, `pwd`, `date_of_joining`) VALUES
(1, 'ashish', 'Ashish', 'ashish@gmail.com', 'Manager', '123456', '2021-11-25');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `checkin`
--
ALTER TABLE `checkin`
  ADD PRIMARY KEY (`sid`);

--
-- Indexes for table `checkout`
--
ALTER TABLE `checkout`
  ADD PRIMARY KEY (`sid`);

--
-- Indexes for table `room`
--
ALTER TABLE `room`
  ADD PRIMARY KEY (`rid`);

--
-- Indexes for table `roomtype`
--
ALTER TABLE `roomtype`
  ADD PRIMARY KEY (`tid`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `sid` (`sid`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `checkin`
--
ALTER TABLE `checkin`
  MODIFY `sid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `checkout`
--
ALTER TABLE `checkout`
  MODIFY `sid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `room`
--
ALTER TABLE `room`
  MODIFY `rid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=33;
--
-- AUTO_INCREMENT for table `roomtype`
--
ALTER TABLE `roomtype`
  MODIFY `tid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
