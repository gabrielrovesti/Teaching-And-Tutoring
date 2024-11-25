-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Nov 18, 2024 alle 13:35
-- Versione del server: 10.4.27-MariaDB
-- Versione PHP: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `scuola`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `materia`
--

CREATE TABLE `materia` (
  `Codmat` int(11) NOT NULL,
  `Nome` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `materia`
--

INSERT INTO `materia` (`Codmat`, `Nome`) VALUES
(1, 'Italiano'),
(2, 'Inglese'),
(3, 'Storia'),
(4, 'Matematica'),
(5, 'Informatica'),
(6, 'Sistemi e reti'),
(7, 'GPOI'),
(8, 'TPSIT'),
(9, 'Scienze motorie e sportive');

-- --------------------------------------------------------

--
-- Struttura della tabella `studente`
--

CREATE TABLE `studente` (
  `Matricola` int(11) NOT NULL,
  `Nome` varchar(50) NOT NULL,
  `Cognome` varchar(50) NOT NULL,
  `Classe` int(11) NOT NULL,
  `Genere` varchar(20) NOT NULL,
  `DataN` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `studente`
--

INSERT INTO `studente` (`Matricola`, `Nome`, `Cognome`, `Classe`, `Genere`, `DataN`) VALUES
(1, 'Riccardo', 'Longo', 1, 'Maschio', '1999-09-09'),
(2, 'Riccardo', 'Benato', 1, 'Maschio', '2002-02-02'),
(3, 'Topo', 'Giggio', 3, 'Femmina', '1995-11-02');

-- --------------------------------------------------------

--
-- Struttura della tabella `voto`
--

CREATE TABLE `voto` (
  `Voto` int(11) DEFAULT NULL,
  `Tipo` varchar(30) DEFAULT NULL,
  `DataV` date DEFAULT NULL,
  `Materiaid` int(11) DEFAULT NULL,
  `Studenteid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `voto`
--

INSERT INTO `voto` (`Voto`, `Tipo`, `DataV`, `Materiaid`, `Studenteid`) VALUES
(4, 'Orale', '2024-10-06', 7, 3),
(8, 'orale', '2024-09-19', 5, 1),
(4, 'pratico', '2024-10-15', 6, 1);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `materia`
--
ALTER TABLE `materia`
  ADD PRIMARY KEY (`Codmat`);

--
-- Indici per le tabelle `studente`
--
ALTER TABLE `studente`
  ADD PRIMARY KEY (`Matricola`);

--
-- Indici per le tabelle `voto`
--
ALTER TABLE `voto`
  ADD KEY `Materiaid` (`Materiaid`),
  ADD KEY `Studenteid` (`Studenteid`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `materia`
--
ALTER TABLE `materia`
  MODIFY `Codmat` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT per la tabella `studente`
--
ALTER TABLE `studente`
  MODIFY `Matricola` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `voto`
--
ALTER TABLE `voto`
  ADD CONSTRAINT `voto_ibfk_1` FOREIGN KEY (`Materiaid`) REFERENCES `materia` (`Codmat`),
  ADD CONSTRAINT `voto_ibfk_2` FOREIGN KEY (`Studenteid`) REFERENCES `studente` (`Matricola`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
