# coding:utf-8
import psutil
import time

def getNet():
    sent_before = psutil.net_io_counters().bytes_sent  # 已发送的流量
    recv_before = psutil.net_io_counters().bytes_recv  # 已接收的流量
    time.sleep(1)
    sent_now = psutil.net_io_counters().bytes_sent
    recv_now = psutil.net_io_counters().bytes_recv
    sent = (sent_now - sent_before)/1024  # 算出1秒后的差值
    recv = (recv_now - recv_before)/1024
    if sent/1024 >= 1:
        sent = f'{sent/1024:.2f}MB/s'
    else:
        sent = f'{sent:.2f}KB/s'
    if recv/1024 >= 1:
        recv = f'{recv/1024:.2f}MB/s'
    else:
        recv = f'{recv:.2f}KB/s'
    # print(time.strftime(" [%Y-%m-%d %H:%M:%S] ", time.localtime()))
    print(u"\uf063"f" {recv} "u"\uf062"f" {sent}")
    # print("下载：{0}KB/s".format("%.2f"%recv))
    # print('-'*32)

if __name__ == "__main__":
    # print('-'*32)
    #while 1:
    getNet()
