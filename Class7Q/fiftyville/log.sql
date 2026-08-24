-- Keep a log of any SQL queries you execute as you solve the mystery.

select * from crime_scene_reports;

select * from crime_scene_reports
where year = 2021
and month = 7
and day = 28
and street like "%Humphrey%";
-- 295: CS50 鸭子失窃案发生在上午 10:15，地点是汉弗莱街的一家面包店。当天对案发时在场的 3 名目击者进行了采访——这三人的采访记录中都提到了这家面包店。



select * from interviews
where year = 2021
and month = 7
and day = 28;
-- 161 Ruth: 在盗窃发生后的十分钟内，我看到小偷坐进面包店停车场的一辆汽车并开车离开了。如果你们有面包店停车场的监控录像，或许可以查看一下在那段时间内驶离停车场的车辆。
-- 162 Eugene: 我不知道小偷的名字，但那个人是我认识的人。今天早些时候，在我到 Emma 的面包店之前，我经过 Leggett Street 的 ATM 时，看见小偷正在那里取钱。
-- 163 Raymond: 当小偷离开面包店时，TA 给某个人打了电话，两人的通话时间不到一分钟。在通话中，我听到小偷说，TA 计划明天乘坐最早的一班航班离开 Fiftyville。随后，小偷让电话另一端的人帮忙购买机票。

-- 161: 面包店停车场监控
select * from bakery_security_logs
where year = 2021
and month = 7
and day = 28
and (hour * 60 + minute) < (10 * 60 + 15);
-- 一张大表

-- 162: 0728早上取钱zaigett Street
select * from atm_transactions
where year = 2021
and month = 7
and day = 28
and atm_location like "%Humphrey%"
and transaction_type = "deposit";
-- id: 248-335

select b.person_id from bank_accounts b
join atm_transactions a on a.account_number = b.account_number
where a.id >= 248 and a.id <= 335
and b.creation_year <= 2021;

-- 163: 0728 10:15- 一分钟电话 0729最早的机票
select * from airports;
select * from airports
where city = "Fiftyville";
-- +----+--------------+-----------------------------+------------+
-- | id | abbreviation |          full_name          |    city    |
-- +----+--------------+-----------------------------+------------+
-- | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
-- +----+--------------+-----------------------------+------------+
select * from flights
where origin_airport_id = 8
and year = 2021
and month = 7
and day = 29;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
select * from passengers
where flight_id = 36;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+
select * from phone_calls
where year = 2021
and month = 7
and day = 28
and duration < 60;
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+

-- 通过上面某一堆表查人
select p.id, p.name, p.license_plate, p.phone_number from people p
join phone_calls pc on pc.caller = p.phone_number
join passengers ps on ps.passport_number = p.passport_number
join bakery_security_logs bsl on bsl.license_plate = p.license_plate
join bank_accounts b on b.person_id = p.id
join atm_transactions a on a.account_number = b.account_number
where ps.flight_id = 36
and pc.year = 2021
and pc.month = 7
and pc.day = 28
and pc.duration < 60
and bsl.activity = "entrance"
and bsl.year = 2021
and bsl.month = 7
and bsl.day = 28
and (bsl.hour * 60 + bsl.minute) < (10 * 60 + 15)
and a.id >= 248 and a.id <= 335
and b.creation_year <= 2021;
-- +--------+--------+---------------+----------------+
-- |   id   |  name  | license_plate |  phone_number  |
-- +--------+--------+---------------+----------------+
-- | 449774 | Taylor | 1106N58       | (286) 555-6063 |
-- | 686048 | Bruce  | 94KL13X       | (367) 555-5533 |
-- +--------+--------+---------------+----------------+

-- 检查两个人分别啥时候离开的面包店，在10:25之前离开的是小偷
select * from bakery_security_logs
where license_plate = "1106N58" or license_plate = "94KL13X";
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 232 | 2021 | 7     | 28  | 8    | 23     | entrance | 94KL13X       |
-- | 237 | 2021 | 7     | 28  | 8    | 34     | entrance | 1106N58       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- -- 94KL13X是小偷，凶手是Bruce，id是686048

select * from airports
where id = 4;
-- +----+--------------+-------------------+---------------+
-- | id | abbreviation |     full_name     |     city      |
-- +----+--------------+-------------------+---------------+
-- | 4  | LGA          | LaGuardia Airport | New York City |
-- +----+--------------+-------------------+---------------+
-- 逃到了New York City

-- 给谁打的电话
select receiver from phone_calls
where year = 2021
and month = 7
and day = 28
and duration < 60
and caller = "(367) 555-5533";
-- (375) 555-8161

select name from people
where phone_number = "(375) 555-8161";
-- Robin
