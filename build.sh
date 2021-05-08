#!/bin/bash

gcc -Wall -D_TEST_ ping.c -o ping -lws2_32
