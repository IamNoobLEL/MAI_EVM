def reverser(a):
  r = ''
  i = 0
  while(i < len(a)):
    if ('0' <= a[i] <= '9'):
      num =''
      while('0' <= a[i] <= '9'):
        num += a[i]
        i+=1
        if (i >= len(a)):
          break
      r += num[::-1]
      i-=1
    else :
      r+=a[i]
    i+=1
  return r[::-1]
  
a = input().replace(' ', '')
print("Input =  ", a)
a = reverser(a)
a = a.replace(')', '#').replace('(', ')').replace('#', '(') # перевернули
q = [] # used as queue
s = [] # used as stack
def preor(i):
  if (i in "+-"): return 1
  if (i in "*/"): return 2
  if (i in "()"): return 10
  return 100
i = 0
while (i < len(a)):
  if ('0' <= a[i] <= '9'):
    num =''
    while('0' <= a[i] <= '9'):
      num += a[i]
      i+=1
      if (i >= len(a)):
        break
    i-=1
    q += [int(num)]
  if not (a[i] in "0123456789+-/*()") :
    q += [a[i]]
  if (a[i] in '+-*/'):
    if (len(s) == 0 or s[-1] == '(') : s+= [a[i]]
    elif (preor(a[i]) > preor(s[-1])): s+= [a[i]]
    elif (preor(a[i]) <= preor(s[-1])):
      while((len(s)) and (preor(s[-1]) > preor(a[i])) and (s[-1]!="(")) :
        q+=[s[-1]]
        s=s[:-1]
      s += [a[i]]
  if (a[i] == "("):
    s+=[a[i]]
  if (a[i] == ")"):
    while(s[-1] != '(') :
      q += [s[-1]]
      s = s[:-1]
    if (s[-1] == "("): s = s[:-1]
  i+=1
while(len(s) > 0):
  q+=[s[-1]]
  s=s[:-1]
print("Output = ",*q[::-1])