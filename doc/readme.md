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
manager，controller，dataplane，mk，schema。

.1 manager: 管理面，业务对接，提供北向api

.2 controller : 控制面，配置存储，提供南向api

.3 dataplane : 转发面，转发

.4 mk : makefile 工具集

.5 schema : 提供统一数据格式描述
```
