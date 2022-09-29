-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT id, description FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;
-- Finding the IDs and descriptions of crimes committed at this time/ place
-- CS50 duck theft crime ID is 295
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three
-- witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
-- Interviews 161, 162 and 163 are useful
-- 161: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--      If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot
--      in that time frame.
-- 162: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--      I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard
--      the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the
--      person on the other end of the phone to purchase the flight ticket.

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
-- IDs 260-267 are suspects
-- License plates of suspects: 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55

SELECT * FROM people WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');
-- People IDs: 221103, 243696, 396669, 398010, 467400, 514354, 560886,  686048
-- Phone no.s: (725) 555-4692, (301) 555-4174, (829) 555-5269, (130) 555-0289, (389) 555-5198, (770) 555-1861, (499) 555-9472, (367) 555-5533
-- Passport no.s: 2963008352, 7526138472, 7049073643, 1695452385, 8496433585, 3592750733, 8294398571, 5773159633

SELECT * FROM atm_transactions
JOIN bank_accounts
ON atm_transactions.account_number = bank_accounts.account_number
WHERE person_id IN (221103, 243696, 396669, 398010, 467400, 514354, 560886,  686048) AND year = 2021 AND month = 7 AND day = 28;
-- Suspects: 467400, 686048, 396669, 514354
-- Phone no.s: (389) 555-5198, (367) 555-5533, (829) 555-5269, (770) 555-1861
-- Passports: 8496433585, 5773159633, 7049073643, 3592750733

SELECT * FROM phone_calls WHERE caller IN ('(389) 555-5198', '(367) 555-5533', '(829) 555-5269', '(770) 555-1861') AND year = 2021 AND month = 7 AND day = 28;
-- Assuming the witness was accurate about call duration
-- Suspects: (367) 555-5533, (770) 555-1861
-- Accomplice suspects: (375) 555-8161, (725) 555-3243

SELECT * FROM passengers
JOIN flights
ON passengers.flight_id = flights.id
WHERE passport_number IN (5773159633, 3592750733) AND year = 2021 AND month = 7 AND day = 29;
-- Suspect's passport no.: 5773159633
-- Suspect: Bruce

SELECT * FROM people WHERE phone_number = '(375) 555-8161';
-- Accomplice: Robin

SELECT * FROM airports WHERE id = 4;
-- Suspect's destination: New York City

The THIEF is: Bruce
The city the thief ESCAPED TO: New York City
The ACCOMPLICE is: Robin