
int time_taken_by_winner(int n, int weights[])
{
    // code goes here
	std::priority_queue<int, std::vector<int>, std::greater<int> > p;
	int ans = 0, a, b;
	for (int i = 0; i<n; i++)
	{
		p.push(weights[i]);
	}
	while (p.size()>1){
		a = p.top();
		p.pop();
		a += p.top();
		p.pop();
		p.push(a);
	}
	return p.top();
}
