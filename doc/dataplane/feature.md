# 简介

实现通用转发平台，主要功能：

1.  host设备管理，包含网卡，内存，CPU等管理
2.  虚设备管理，包含虚拟路由器(vrouter)，虚拟交换机(vswitch)，分布式虚拟路由器(dvrouter)，分布式虚拟交换机(dvswith)
3.  高级网络功能，包含dhcp，portchain
4.  高级路由，包含 rip，ospf，bgp
5.  bgp-evpn
6.  隧道功能，vxlan隧道
7.  服务链
8.  openflow
9.  调试，包含 抓包，报文注入



# 转发模型

vector转发

快慢路转发



# 进程模型

单进程多线程模型，即 单配置线程 + 多转发线程



# 转发分析

![流量分析](https://github.com/breeve/sdn/blob/master/doc/resource/%E6%B5%81%E9%87%8F%E5%88%86%E6%9E%90.jpg)



流量类型

1.  物理口<->物理口
2.  物理口<->虚设备
3.  物理口<->内核
4.  物理口<->vm/docker
5.  物理口<->控制面
6.  虚设备<->虚设备
7.  虚设备<->控制面



# 接口联动

``` c
int linkage_add(ifp_member_list, linkage)
{
  
}
```



















