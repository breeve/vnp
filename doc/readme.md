“愿中国青年都摆脱冷气，只是向上走， 不必听自暴自弃者流的话。 能做事的做事，能发声的发声。 有一分热，发一分光。 就令萤火一般，也可以在黑暗里发一点光， 不必等候炬火。 以后如竟没有炬火， 你便是唯一的光。”

# 目录结构

```shell
├── doc
│   └── readme.md
├── resource
│   ├── dpdk
│   └── readme.md
├── src
│   ├── Makefile
│   ├── device
│   ├── forward
│   ├── init
│   ├── session
│   ├── vrouter
│   └── vswitch
└── test
    └── readme.md

----------------------------------------------------------------

doc: 文档

resource: 外部资源

src: 功能代码

test: 测试用例

```

# 项目组成

```shell
整体设计
manager，controller，dataplane，schema。

.1 manager: 管理面，业务对接，提供北向api

.2 controller: 控制面，配置存储，提供南向api

.3 dataplane: 转发面，转发

.4 schema: 提供统一数据格式描述
```
