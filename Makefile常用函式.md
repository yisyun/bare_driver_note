##patsubst (模式替換函式)
查找符合模式的字串並進行替換
$(patsubst <模式>, <替換>, <字串>)

##foreach (迴圈函式)
遍歷一組變數，並對每個元素執行 <運算>
$(foreach <變數>, <列表>, <運算>)

##wildcard (檔案匹配函式)
$(wildcard <模式>)

##notdir (去除路徑函式)
移除字串中的目錄部分，只保留檔名

##$(SFILENDIR:.S=.o)
字串替換語法
$(變數:舊字串=新字串)

##VPATH
VPATH 變數用來指定 make 在哪些目錄中查找原始碼 