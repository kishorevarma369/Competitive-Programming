n=int(input())
diameter_of_holes=[int(i) for i in input().split(' ')]
m=int(input())
diameter_of_balls=[int(i) for i in input().split(' ')]

used=[0]*n

for ball in diameter_of_balls:
  flag=True
  for i,hole in enumerate(reversed(diameter_of_holes)):
    if used[n-i-1]<=n-i-1 and ball<=hole:
      used[n-i-1]+=1
      print(n-i,end=' ')
      flag=False
      break
  if flag :
    print(0,end=' ')
