@echo off
lcc %1.c -o %1.gb
d:\downloads\bgb\bgb.exe %1.gb