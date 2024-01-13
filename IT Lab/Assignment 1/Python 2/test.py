import threading
import time
db=dict()
db["tonmoy"]="biswas"
db["tonmoy1"]="biswas"
db["dict"]=dict()
db["dict"]["bal"]="chal"

# print(db)
# print(str(db))
# print("tonmoy" not in db)

for it in db:
    print(it)

# arr=list()

# sem=threading.Semaphore(1)

# def addEle(start,end,arr,sem):
#     sem.acquire()
#     for i in range(start,end):
#         arr.append(i)
#         time.sleep(1)
#     sem.release()

# thread1=threading.Thread(target=addEle,args=(1,10,arr,sem))
# thread2=threading.Thread(target=addEle,args=(1,10,arr,sem))

# start=time.time()

# thread1.start()
# thread2.start()
# thread1.join()
# thread2.join()

# end=time.time()

# print(f"time {end-start} s")

# # print(len(arr))
# print(arr)