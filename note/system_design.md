## Note: 系統設計我幾乎零認識，只是先搜集感覺重要的資料
面試 — System Design

1. Grokking the System Design Interview
這個是一個付費的資源。沒有很貴我也覺得很值得。主要就是把幾個比較經典的題目拿出
來討論，但是千萬不要只讀這個，因為他探討的非常表面，你需要更深入去研究每個一個
系統，不然面試時很容易被看破。

2. https://github.com/donnemartin/system-design-primer
這個也是一個很棒的資源，也是把一些經典的題目拿出來討論，比上面更深入，所以會建
議搭配上面一起用效果會很好。

3. Conference Talks
這些演講我真的受益良多，都是各大公司經驗談。看這些演講時，細節就不用真的去專研
，主要是了解他背後的架構和哲學。我挑的這些都是這些公司早期如何應付大流量的
Refactor 經驗談。這些都是面試很愛討論的

Instagram: https://youtu.be/hnpzNAPiC0E

Slack: https://youtu.be/WE9c9AZe-DY

Reddit: https://youtu.be/nUcO7n4hek4

Twitter: https://youtu.be/WEgCjwyXvwc

Dropbox: https://youtu.be/PE4gwstWhmc

Zuck 的 Memcache 演講: https://youtu.be/UH7wkvcf0ys


4. Classic Papers 有空的時候可以加減讀一下
The Google File System
Dynamo: Amazon’s Highly Available Key-value Store
Bigtable: A Distributed Storage System for Structured Data
The Chubby lock service for loosely-coupled distributed systems
Scaling Distributed machine Learning with the Parameter Server
Spanner: Google’s Globally-Distributed Database

5. DDIA 聖經 (Designing Data-Intensive Application)
不要直接拿來啃，會非常崩潰。請把他當工具書，遇到比較不了解的系統再去翻這本。


我本身就是有 SRE 的經驗，所以公司內部的系統大約有個概念，所以準備起來也比較上
手。L4 (有經驗但還未到資深工程師) 的System Design的大架構其實就是 Front End->
Load Balancer -> Internal Proxy -> Middleware -> Cache -> Storage/Database/CDN
等等。中間變化很多，細節也很多，所以就看個人想要專研到什麼程度，但大架構一定要
理解，這樣才比較好討論。

個人建議是一定要找一個比較了解系統的人幫你 mock interview 和實際把圖畫出來，不
然真的面試時會非常卡。