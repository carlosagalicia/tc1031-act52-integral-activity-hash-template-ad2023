![Tec de Monterrey](images/logotecmty.png)
# Act 5.2 - Comprehensive Activity on the Use of Hash Codes (Competency Evidence)

## <span style="color: rgb(26, 99, 169);">What Do I Have to Do?</span>
In this repository, you will find the input files as well as the expected outputs you can use to test your implementation. You will also find a "main.cpp" file. You must implement your solution in this file. At the top of the file, include your personal information in comments. For example:

```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```
<span style="text-decoration: underline;">Individually</span>, develop the solution for the following problem:

A **competitive programming contest** is an algorithmic programming competition for university students. Teams of three work to solve the most real-world problems, promoting collaboration, creativity, innovation, and the ability to perform under pressure.

Competing teams are ranked first by the number of problems solved (the more, the better), then by decreasing penalty time. If two or more participants are tied in both problems solved and penalty time, they are ranked in ascending order of team number.

A problem is considered solved by a competing team if any of the submissions for that problem was deemed correct. Penalty time is calculated as the number of minutes it took for the first correct submission to be received for a problem plus 20 minutes for each incorrect submission received before the correct solution. Subsequent submissions for an already solved problem are ignored. Unsolved problems do not incur penalty time.

## <span style="color: rgb(26, 99, 169);">**Input**</span>
The input consists of a snapshot of the evaluation queue, which contains entries from some or all contestants from 1 to 100 solving problems 1 to 9. Each input line consists of three numbers and a letter:

```
#team #problem time result
```
Where *result* can be 'C', 'I', 'R', 'U', or 'E'. These represent Correct, Incorrect, Request, Unjudged, and Erroneous submissions respectively. The last three cases do not affect the score.

The input lines are in the order in which the submissions were received.

## <span style="color: rgb(26, 99, 169);">**Output**</span>
The output will consist of a scoreboard ordered as described above. Each output line will contain a contestant number, the number of problems solved by the contestant, and the accumulated penalty time for the contestant. Since not all contestants from 1 to 100 participate, show only those contestants who made a submission.

## <span style="color: rgb(26, 99, 169);">**Sample Input**</span>
```
1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
```

## <span style="color: rgb(26, 99, 169);">**Sample Output**</span>
```
1 2 66
3 1 11
```

To test your implementation, compile your program with the command:
```
g++ -std=c++11 main.cpp -o app
```
Then, test your solution with each of the input files provided in this repository (`input1.txt`, `input2.txt`, `input3.txt`, `input4.txt`). The expected results are in the files `output1.txt`, `output2.txt`, `output3.txt`, and `output4.txt`. To perform the tests, you can use the following commands. For example, to test with "input1.txt":
```
./app < input1.txt > mysolution1.txt
diff mysolution1.txt output1.txt
```
If the second command produces no output, you know your results are as expected.

Finally, conduct individual research and reflection on the importance and efficiency of different sorting and searching algorithms in a problem situation like this. Generate a document titled **"ReflexAct5.2.pdf"**.

## <span style="color: rgb(26, 99, 169);">**How Is My Evidence Evaluated?**</span>

- **80%** - For each functionality, the evaluation will be:
    - **Excellent (80%)** - correctly passes all test cases.
    - **Very Good (60%)** - correctly passes 75% of test cases.
    - **Good (40%)** - correctly passes 50% of test cases.
    - **Insufficient (20%)** - correctly passes less than 50% of test cases.

- **10%** - The code must follow the coding standards specified in the document: <span class="instructure_file_holder link_holder">[coding_standard_link](estandar.pdf)</span>.
- **10%** - The function names in the application must be respected.

## <span style="color: rgb(26, 99, 169);">**Where Do I Submit It?**</span>
This activity is part of your final course grade as well as the portfolio of evidence for the competencies to be developed in the course. Therefore, individually:
* Submit the corresponding files for the sorting and searching algorithms in the appropriate section of this platform, along with the individual reflection document (**ReflexAct5.2.pdf**).
* Create a personal folder named **TC1031(Final_Portfolio)** for the portfolio of competencies submission at the end of the course. This folder must contain 5 subfolders:
    * Act1.3
    * Act2.3
    * Act3.4
    * Act4.3
    * **Act5.2** - place your files that solved <span style="text-decoration: underline;">activity 1.3</span> along with the individual reflection document (**ReflexAct5.2.pdf**).
