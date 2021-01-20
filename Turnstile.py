def getTimes(numCustomers: int, arrTime: List[int], direction: List[int]) -> List[int]:
    enter_queue = deque()
    exit_queue = deque()
    curTime = -1;
    last_pass = 'exit'
    
    for i in range(numCustomers):
        if direction[i] == 0:
            enter_queue.append((arrTime[i], i))
        else:
            exit_queue.append((arrTime[i], i))

    ans = [-1] * numCustomers
    while enter_queue and exit_queue:
        if enter_queue[0][0] <= curTime and exit_queue[0][0] <= curTime: #both customers are at door
            if curTime < 0 or last_pass == 'exit':
                cur_queue = exit_queue
            else:
                cur_queue = enter_queue
        elif enter_queue[0][0] < exit_queue[0][0]:
            cur_queue = enter_queue
        else:
            cur_queue = exit_queue
        
        time, i = cur_queue.popleft()
        curTime = max(curTime, time)
        ans[i] = curTime
        curTime += 1
        if cur_queue == exit_queue:
            last_pass = 'exit'
        else:
            last_pass = 'enter'
    
    remaining_queue = enter_queue if enter_queue else exit_queue
    while remaining_queue:
        time,  i = remaining_queue.popleft()
        curTime = max(time, curTime)
        ans[i] = curTime
        curTime += 1
    return ans

if __name__ == "__main__":
    numCustomers  = int(input())
    arrTime = [int(y) for y in input().split()]
    direction = [int(z) for z in input().split()]
    res = getTimes(numCustomers, arrTime, direction)
    print(' '.join(str(e) for e in res))

#Input

#5
#0 1 1 3 3
#0 1 0 0 1

#Expected

#0 2 1 4 3
