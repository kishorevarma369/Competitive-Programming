number_of_players=int(input())
race_time=int(input())-1

players=[]
player_step=[]
for i in range(number_of_players):
    player=[int(x) for x in input().split(' ')]
    players.append(player[:-1])
    player_step.append(player[-1])

winners = [0]*number_of_players
runs = [0]*number_of_players

for i in range(1,race_time,2):
    mymax=0
    l=[]
    for j in range(number_of_players):
        runs[j]+=(players[j][i]+players[j][i-1])*player_step[j]
        if runs[j] > mymax :
            l=[j]
            mymax=runs[j]
        elif runs[j] == mymax :
            l.append(j)
    for winner in l:
        winners[winner]+=1

# print(winners)
# print(runs)
maxval=winners[0]
ans=0
for i in range(len(winners)):
    if maxval<winners[i]:
        maxval=winners[i]
        ans=i
print(ans+1)