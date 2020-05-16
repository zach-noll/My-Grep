#! /usr/bin/env bash


~nimrodav/grep_tests/beta1.sh
~nimrodav/grep_tests/beta2.sh
~nimrodav/grep_tests/run11.sh
~nimrodav/grep_tests/run12.sh
~nimrodav/grep_tests/run13.sh
~nimrodav/grep_tests/run14.sh
~nimrodav/grep_tests/run15.sh
~nimrodav/grep_tests/run16.sh
~nimrodav/grep_tests/run17.sh

grep -c an ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputc
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -c an | diff ~zacharynoll/c_lab/ex2/my_tests/outputc -


grep -v ucket ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputv
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -v  ucket | diff ~zacharynoll/c_lab/ex2/my_tests/outputv -


grep -i nan ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputi
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -i nan | diff ~zacharynoll/c_lab/ex2/my_tests/outputi -


grep -i -v Nan ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputiv
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -i -v Nan | diff ~zacharynoll/c_lab/ex2/my_tests/outputiv -


grep -b an ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputb
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -b an | diff ~zacharynoll/c_lab/ex2/my_tests/outputb - 

grep -n na ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputn
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -n na | diff ~zacharynoll/c_lab/ex2/my_tests/outputn - 


grep -n -i -b -v  nAn ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputnibv
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -n -i -b -v nAn | diff ~zacharynoll/c_lab/ex2/my_tests/outputnibv - 

grep -n -i -b An ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputfilenib
~zacharynoll/c_lab/ex2/my_grep -n -i -b An ~zacharynoll/c_lab/ex2/my_tests/input | diff ~zacharynoll/c_lab/ex2/my_tests/outputfilenib -


grep -x  zach ~zacharynoll/c_lab/ex2/my_tests/inputx > ~zacharynoll/c_lab/ex2/my_tests/outputx
cat ~zacharynoll/c_lab/ex2/my_tests/inputx | ~zacharynoll/c_lab/ex2/my_grep -x zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputx - 

grep -x -i  zach ~zacharynoll/c_lab/ex2/my_tests/inputx > ~zacharynoll/c_lab/ex2/my_tests/outputx
cat ~zacharynoll/c_lab/ex2/my_tests/inputx | ~zacharynoll/c_lab/ex2/my_grep -x -i zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputx - 

grep -x -v  zach ~zacharynoll/c_lab/ex2/my_tests/inputx > ~zacharynoll/c_lab/ex2/my_tests/outputx
cat ~zacharynoll/c_lab/ex2/my_tests/inputx | ~zacharynoll/c_lab/ex2/my_grep -x -v zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputx - 

grep -x -b -n  zach ~zacharynoll/c_lab/ex2/my_tests/inputx > ~zacharynoll/c_lab/ex2/my_tests/outputx
cat ~zacharynoll/c_lab/ex2/my_tests/inputx | ~zacharynoll/c_lab/ex2/my_grep -x -b -n zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputx - 

grep -x -b -i -n zach ~zacharynoll/c_lab/ex2/my_tests/inputx > ~zacharynoll/c_lab/ex2/my_tests/outputx
cat ~zacharynoll/c_lab/ex2/my_tests/inputx | ~zacharynoll/c_lab/ex2/my_grep -x -b -i -n zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputx - 


grep zach ~zacharynoll/c_lab/ex2/my_tests/inputempty > ~zacharynoll/c_lab/ex2/my_tests/outputempty
cat ~zacharynoll/c_lab/ex2/my_tests/inputempty | ~zacharynoll/c_lab/ex2/my_grep zach | diff ~zacharynoll/c_lab/ex2/my_tests/outputempty - 

grep "a.a" ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputdot
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -E "a.a" | diff ~zacharynoll/c_lab/ex2/my_tests/outputdot - 

grep "[m-n]an" ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputsqr
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -E "[m-n]an" | diff ~zacharynoll/c_lab/ex2/my_tests/outputsqr - 


grep "[a-z]ucket" ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputsqr2
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -E "[a-z]ucket" | diff ~zacharynoll/c_lab/ex2/my_tests/outputsqr2 - 


grep "[a-z].cke[a-z]" ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputsqr3
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -E "[a-z].cke[a-z]" | diff ~zacharynoll/c_lab/ex2/my_tests/outputsqr3 - 

grep -i -n -A 2 "[a-z].CkE[a-z]" ~zacharynoll/c_lab/ex2/my_tests/input > ~zacharynoll/c_lab/ex2/my_tests/outputsqr4
cat ~zacharynoll/c_lab/ex2/my_tests/input | ~zacharynoll/c_lab/ex2/my_grep -i -n -A 2 -E "[a-z].CkE[a-z]" | diff ~zacharynoll/c_lab/ex2/my_tests/outputsqr4 - 

grep -i -n -b -E "[a-z]/.." ~zacharynoll/c_lab/ex2/my_tests/2013.html > ~zacharynoll/c_lab/ex2/my_tests/outputsqr5
cat ~zacharynoll/c_lab/ex2/my_tests/2013.html | ~zacharynoll/c_lab/ex2/my_grep -i -n -b -E "[a-z]/.." | diff ~zacharynoll/c_lab/ex2/my_tests/outputsqr5 -

grep -i -n -b -E "(<li>|<hi>)" ~zacharynoll/c_lab/ex2/my_tests/2013.html > ~zacharynoll/c_lab/ex2/my_tests/outputpar1
cat ~zacharynoll/c_lab/ex2/my_tests/2013.html | ~zacharynoll/c_lab/ex2/my_grep -i -n -b -E "(<li>|<hi>)" | diff ~zacharynoll/c_lab/ex2/my_tests/outputpar1 -

grep -E -n -b -x "\[1[0-9]\]" ~nimrodav/grep_tests/in16 > ~zacharynoll/c_lab/ex2/my_tests/output16
cat ~nimrodav/grep_tests/in16 | ~zacharynoll/c_lab/ex2/my_grep  -E -n -b -x "\[1[0-9]\]" | diff ~zacharynoll/c_lab/ex2/my_tests/output16 -

grep -i -n -b -E "(\(Sockets\)|<hr>)" ~zacharynoll/c_lab/ex2/my_tests/2013.html > ~zacharynoll/c_lab/ex2/my_tests/output17
cat ~zacharynoll/c_lab/ex2/my_tests/2013.html | ~zacharynoll/c_lab/ex2/my_grep -i -n -b -E "(\(Sockets\)|<hr>)" | diff ~zacharynoll/c_lab/ex2/my_tests/output17 -



chmod 755 *



 
