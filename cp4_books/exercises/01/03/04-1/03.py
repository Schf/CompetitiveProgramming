from datetime import datetime

d = datetime.strptime(input(), "%d %B %Y")
print(d.strftime("%A"), (datetime.today() - d).days)
