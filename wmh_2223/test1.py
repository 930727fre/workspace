import re

def checkEmail(email):
  pattern = r'^[a-zA-Z0-9]{5}@[A-Z]{3}\.com$'
  if re.match(pattern, email):
    return email.split('@')[0]
  else:
    return None

# 測試範例
print(checkEmail('abcde@HAS.com')) # abcde
print(checkEmail('abc55@HAS.com')) # abc55
print(checkEmail('abc55@HaS.com')) # None
print(checkEmail('abcde@HASA.com')) # None
print(checkEmail('abcd@HAS.com')) # None
print(checkEmail('abcde@HAS.comm')) # None
print(checkEmail('abcde@HAS.com.com')) # None
