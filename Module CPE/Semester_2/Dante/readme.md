# Dante
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#Overview)
### General Info
***
The objective of the project is to create 2 binary files, the first generates a maze and the second resolves it.
## Technologies
***
A list of technologies used within the project:
* [Lib C functions]
* [systems functions]
## Installation
***
A little intro about the installation.
```
$ git clone git@github.com:EpitechPromo2027/B-CPE-200-BDX-2-1-dante-marc.mendia.git
$ cd B-CPE-200-BDX-2-1-dante-marc.mendia
$ make
$ ./solver maze.txt or ./generator x y [perfect]
```
## Overview
***
***
```
$> ./generator 10 10 perfect > file
$> cat file

   *********X
   *X*X*X*X*X
   *X*X*X*X*X
   *X*X*X*X*X
   *X*X*X*X*X
   *XXX*X***X
   ***X*X*X*X
   *XXX*X*X*X
   ***X*X*X*X
   XXXXXXXX**
```
***
```
$> ./solver file > solve_file
$> cat solve_file

   ooooooo**X
   *X*X*XoX*X
   *X*X*XoX*X
   *X*X*XoX*X
   *X*X*XoX*X
   *XXX*XoooX
   ***X*X*XoX
   *XXX*X*XoX
   ***X*X*XoX
   XXXXXXXXoo
```
