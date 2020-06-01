# 转发规则
在转发行为中，描述某一类报文的出接口等信息的规则，称为转发规则。一般的组成:
``` c
< match, instruction >
```
# 二层转发
二层转发，即根据报文目的mac进行转发。转发规则所组成的表项称为fdb(forward database)表项。fdb的组成
```c
< [mac, vlan], [outif]>
```

# 三层转发
三层转发，即根据报文目的ip进行转发。转发规则所组成的表项称为fib(forward information base)表项。fib的组成
```c
< [ip], [[type, gateway, outif], [gateway, outif]]>
```
fib里的每一条称为一条路由。路由的 instruction 则称为下一跳。下一跳，包含的信息


# flow

# slow path

# fast path