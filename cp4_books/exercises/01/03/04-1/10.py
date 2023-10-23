import re

print(re.sub(r"\b[a-z]{1}\d{2}\b", "***", input()))
