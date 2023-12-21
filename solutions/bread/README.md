| ID | Problem name | Link to solution |
|:---|:---|:---:|
| [bread](https://open.kattis.com/problems/bread   ) | Bread Sorting | [Solution](https://github.com/versenyi98/kattis-solutions/tree/main/solutions/bread)|
#### 1 to first index, 9 to last index -> swap(1, 9) swap(2, 3)
**9** 8 7 6 5 4 **3** **2** **1**   
**9** 8 7 6 5 4 **1** 3 2   
**9** 8 7 6 **1** 5 4 3 2   
**9** 8 **1** 7 6 5 4 3 2   
**1** **9** 8 7 6 5 4 3 2   
**1** 8 7 **9** 6 5 4 3 2   
**1** 8 7 6 5 **9** 4 3 2   
**1** 8 7 6 5 4 3 **9** 2   
**1** 8 7 6 5 4 **2** **3** **9**   

#### 1 to first index, 8 to last index -> swap(1, 8) swap(2, 3)
**8** 7 6 5 4 **3** **2** **1**   
**8** 7 6 5 4 **1** 3 2   
**8** 7 6 **1** 5 4 3 2   
**8** **1** 7 6 5 4 3 2   
**1** 7 **8** 6 5 4 3 2   
**1** 7 6 5 **8** 4 3 2   
**1** 7 6 5 4 3 **8** 2   
**1** 7 6 5 4 **2** **3** **8**   

[More info](http://techblogofmrd.blogspot.com/2014/01/linear-solution-to-bread-shuffling.html)