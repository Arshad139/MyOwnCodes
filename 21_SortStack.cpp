void sortedInsert(stack<int> &stack,int val)
{
    //Base Case
    if(stack.empty()||stack.top()<val)
    {
      stack.push(val);
        return;  
    }
    int num=stack.top();
    stack.pop();
    sortedInsert(stack,val);
    stack.push(num);
    return;
    
}
void sortStack(stack<int> &stack)
{
	//Base Case
    if(stack.empty())
    {
      return;  
    }
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack,num);
    return;
    
}
