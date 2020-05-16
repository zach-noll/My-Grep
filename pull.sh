#! /usr/bin/env bash

mv ~zacharynoll/c_lab/ex2/*.c ~zacharynoll/c_lab/ex2/backups/
mv ~zacharynoll/c_lab/ex2/*.h ~zacharynoll/c_lab/ex2/backups/

cp ~shohami/c_lab/ex2/*.c ~zacharynoll/c_lab/ex2/
cp ~shohami/c_lab/ex2/*.h ~zacharynoll/c_lab/ex2/

make clean
make all
