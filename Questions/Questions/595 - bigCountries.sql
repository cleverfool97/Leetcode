#Difficulty: Easy
#Please refer to "595. Big Countries" for the problem statement.
#https://leetcode.com/problems/big-countries/description/
#Use SELECT to obtain the terms desired, FROM to specify the table, and WHERE to specify the conditional
#This is a good warmup in case you are rusty with SQL queries.
SELECT name, population, area FROM World WHERE area > 3000000 OR population > 25000000