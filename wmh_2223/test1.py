def replace(oldString, newString, filePath):
    with open(filePath, 'r') as file:
        # 讀取檔案內容
        content = file.read()

    # 將 oldString 替換成 newString
    content = content.replace(oldString, newString)

    with open(filePath, 'w') as file:
        # 寫回檔案
        file.write(content)

# 執行 replace 函式
replace('l', '#', 'd:\\sample.txt')
