# 員工與薪資管理系統 Employee-and-Salary-Management-System
## A simple OOP in C++ system that can recording and calculation employees' salaries.
### 中國文化大學 資訊工程系1A 第16組
### 組員 & 分工：
> [👩🏻‍💻康芷瑄] 主要程式碼撰寫、PPT

> [👩🏻‍💻邱詩云] 部分程式碼撰寫、測試、Debug、README、PPT

> [👩🏻‍💻高語涵] 部分程式碼撰寫、UML、PPT  

### 程式介紹：
這是一個能方便管理大量員工資訊及薪資情況的系統，支持：
> 管理不同職位類別員⼯的薪水

> 紀錄員⼯出缺勤狀況，包含缺勤扣薪等

> 紀錄⼯作績效，並依照業績自動核發獎⾦

> 支持人事異動，如升職、離職或增加新員工

#
> [!TIP]
> ### 系統安裝 & 執行：
> 下載本專案資料夾 [Employee-and-Salary-Management-System](<https://github.com/sweet20potato/Employee-and-Salary-Management-System/tree/7d517fa240225ec85bb5db82eca42fe38283de06/Employee-and-Salary-Management-System>) 中的所有檔案，放到同一資料夾，並於任一可執行C++語言之編譯器編譯並執行。
> 
> 或者，直接下載 [Employee-and-Salary-Management-System.zip](<https://github.com/sweet20potato/Employee-and-Salary-Management-System/blob/18af7c16e4c477c7b1b08df503ff98f393b6da1c/Employee-and-Salary-Management-System.zip>)，解壓縮後，於任一可執行C++語言之編譯器編譯並執行即可。
#
### 系統運行：
1. 系統顯示當前員工資訊及財務報表，並詢問要執行什麼功能
2. 輸入想要執行功能後，依照提示，搜尋要的更動的員工及員工資訊
   
   ![運行畫面1](<photo/015233.png>)

> [!NOTE]
> #### 請依照括弧內的提示輸入要執行的功能，如：
> 
> 想要查找員工，並對其資料進行更動，請輸入"find"。
> 
> 在搜尋員工時，可依照括弧內提示，直接輸入該員工的ID、姓名或職位類別。
#
### 各項操作說明：
#### 查找員工或修改員工資訊：
1. 輸入"find"
2. 輸入目標員工ID、姓名、或職位別(則一即可)
3. 確認該員工資訊，是否要查找的為目標員工
4. 輸入想要執行的更動
5. 如要繼續修改，則重複"第4項"操作
6. 如修改完成，輸入"done"結束更動
   
   ![運行畫面2](<photo/210624.png>)

> [!CAUTION]
> 請確認輸入的關鍵字符合括弧內的提示詞，注意大小寫、ID、姓名等正確性，否則可能無法執行想要的應用。

#### 新增員工
1. 輸入"add"
2. 輸入新員工姓名
3. 輸入新員工職位類別
4. 輸入新員工底薪
5. 系統自動生成ID
   ![運行畫面3](<>)

#### 開除員工
1. 輸入"del"
2. 輸入要開除的員工姓名或ID
   ![運行畫面4](<>)
   
#### 查看員工薪資報表
1. 輸入"show"
   ![運行畫面5](<>)

#### 無須再更動任何資訊 或 存檔
1. 輸入"end"
   ![運行畫面6](<>)
   

> [!IMPORTANT]
> 結束應用前請務必輸入"end"結束程式，否則將會無法儲存更變至csv。
