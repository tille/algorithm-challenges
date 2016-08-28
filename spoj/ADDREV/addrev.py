k = input()
for i in range(0, k):
  a,b = raw_input().split()
  rev = int(a[::-1]) + int(b[::-1])
  print int(str(rev)[::-1])
