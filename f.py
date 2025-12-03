#   [ binary search tree ]
# bst=[3,41,5,6,4,7,8,9,10,2,45,20,78,60]
# bst=sorted(bst)
# start=bst.index(bst[0])
# end =len(bst)-1
# val = int(input("inter the value you search it for"))
# def binary_search_tree(start,end,bst,val):
#     if start > end:
#         print("value not found")
#         return -1
   
#     l=start+end
#     mid=l//2
#     if val==bst[mid]: print("val is found")
#     if val >bst[mid]:
#         binary_search_tree(mid+1,end,bst,val)
#     elif val < bst[mid]:
#         binary_search_tree(start,mid-1,bst,val)
# binary_search_tree(start,end,bst,val)    
#   [ fibonacci sequence ]
# import time
# a=0
# b=1
# i=0
# start=time.perf_counter()
# print(start)
# while i<100:
#     temp= a+b
#     a=b
#     b=temp
#     print(f"{temp}\n")
#     i+=1
# end=time.perf_counter()
# dif=end-start
# print(dif) 
# print(end)   
                    #        A     B     C     A     B     B     A

                    #     o-----o-----o-----o-----o-----o-----o-----o   0
                    #     |     |     | \   |     |     |     |     |
                    # C   |     |     |  \  |     |     |     |     |
                    #     |     |     |   \ |     |     |     |     |
                    #     o-----o-----o-----o-----o-----o-----o-----o   1
                    #     |     | \   |     |     | \   | \   |     |
                    # B   |     |  \  |     |     |  \  |  \  |     |
                    #     |     |   \ |     |     |   \ |   \ |     |
                    #     o-----o-----o-----o-----o-----o-----o-----o   2
                    #     | \   |     |     | \   |     |     | \   |
                    # A   |  \  |     |     |  \  |     |     |  \  |
                    #     |   \ |     |     |   \ |     |     |   \ |
                    #     o-----o-----o-----o-----o-----o-----o-----o   3
                    #     |     | \   |     |     | \   | \   |     |
                    # B   |     |  \  |     |     |  \  |  \  |     |
                    #     |     |   \ |     |     |   \ |   \ |     |
                    #     o-----o-----o-----o-----o-----o-----o-----o   4
                    #     | \   |     |     | \   |     |     | \   |
                    # A   |  \  |     |     |  \  |     |     |  \  |
                    #     |   \ |     |     |   \ |     |     |   \ |
                    #     o-----o-----o-----o-----o-----o-----o-----o   5
                    #     |     |     | \   |     |     |     |     |
                    # C   |     |     |  \  |     |     |     |     |
                    #     |     |     |   \ |     |     |     |     |
                    #     o-----o-----o-----o-----o-----o-----o-----o   6

                    #     0     1     2     3     4     5     6     7git 