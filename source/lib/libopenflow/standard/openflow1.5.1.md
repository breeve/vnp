# Introduction
本文档描述了OpenFlow逻辑交换机的一些要求。关于OpenFlow和SDN的更多信息描述可以在 https://www.opennetworking.org 上找到。本规范涵盖交换机基础功能，以及远程OpenFlow控制器用来管理OpenFlow交换机的OpenFlow交互协议。


```
    +------------+  +------------+
    | Controller |  | Controller |
    +------------+  +------------+
            ^              ^
            |              |
          {penFLow   Protocol}
            |              |             OpenFLow Switch
    +------ | ------------ | --------------------------------+
    |       V              V        *       Datapath         |
    | ......+......  ......+......  *  .........  .........  |
    | . OpenFlow  .  . OpenFlow  .  *  . Group .  . Group .  |
    | . Channel   .  . Channel   .  *  . Table .  . Table .  |
    | .............  .............  *  .........  .........  |
    |********************************                        |
  ......                                                   ......
  .Port.  .........     .........             .........    .Port.
  ......  . Flow  .     . Flow  .             . Flow  .    ......
    |     . Table . --> . Table . --> ... --> . Table .      |
  ......  .........     .........             .........    ......
  .Port.                  Pipeline                         .Port.
  ......                                                   ......
    |                                                        |
    +--------------------------------------------------------+
        Figure 1 : Main components of an OpenFlow switch
```
# Switch Components
一个OpenFlow逻辑交换机包含一个或者多个【流表，flow tables】和一个【组表，group table】，用来处理报文转发，有一个或者多个【Openflow通道，Openflow channels】用来和外部【控制器，controller】交互。交换机和控制器通过【Openflow交换机协议，Openflow switch protocol】来交互。

在主动或者被动模式下，控制器可以使用Openflow交换机协议来增加更新删除流表里面的【流条目，flow entry】。每个流表都包含一组流条目；每一个流条目都包含一组 【匹配字段，match fields】，【计数，counters】，和一组【指令，instructions】，以用来匹配报文。

匹配从一个pipeline第一个流表开始，顺次匹配递增的流表。流条目匹配报文按照优先级，使用第一条被匹配到的流条目。如果有一个条目被匹配到，他的指令就会被执行。如果没有匹配到任何的流表，则执行行为依赖【table-miss flow entry】。比如，可以通过OpenFlow通道送到控制器，或者丢弃，或者继续匹配下一个流表。

流表中的指令会包含【动作，action】，或者修改【流水线处理，pipeline processing】。instruction 里面的action包含【报文转发，packet forwarding】，【报文修改，packet modification】和【组表处理，group table processing】。流水线处理指令允许将数据包发送到后续表进行进一步处理，并允许以元数据的形式在表之间通信信息。当与匹配的流条目关联的指令集未指定下一个表时，表管道处理将停止；此时通常会修改和转发数据包。

流条目通常转发到一个【端口，port】。通常是一个物理口，也可能是一个switch定义的或者本规范保留的逻辑端口。保留端口通常实现一些特定的动作，送到到控制，广播，或者使用 non-OpenFlow 方法 来转发，比如"normal"处理行为。交换机定义的逻辑端口，比如聚合口，隧道口或者环回口。

与流条目相关联的操作也可以将数据包定向到指定附加处理的组。组表示用于泛洪的操作集，以及更复杂的转发语义（例如多路径、快速重路由和链路聚合）。作为间接寻址的一般层，组还允许多个流条目转发到单个标识符（例如，IP转发到公共下一跳）。此抽象允许有效地更改跨流条目的公共输出操作。

组表包含组条目；每个组条目包含一个动作bucket列表，其特定语义取决于组类型。一个或多个操作桶中的操作将应用于发送到组的数据包。只要保持正确的匹配和指令语义，Switch设计器可以以任何方便的方式自由实现内部结构。例如，流条目可以使用全组转发到多个端口，交换机设计器可以选择将其作为硬件转发表中的位掩码来实现。另一个例子是匹配；OpenFlow交换机的pipeline可以用不同数量的硬件表来实现。

# Glossary
下面是一些关键字段
Action:
一个应用在报文上的操作。。一个action可能转发报文到一个端口，修改报文(例如ttl减一)或者改变报文的状态(关联到一个队列)。大多数操作包括参数，例如设置 set-filed 包括字段类型和字段值。操作可以指定为与流条目关联的指令集的一部分，也可以指定在与组条目关联的操作桶中。操作可能累积在数据包的操作集中，或立即应用于数据包。

List of Actions:
可包括在流条目动作的有序列表，适用于Apply-Actions指令或发包消息，并按列表顺序立即执行。列表中的动作可以重复，其作用是累加的。

Set of Actions:
一组可以包含在Write-Actions指令的操作，可以添加在操作集中，或者添加在一组顺序执行的操作桶中。一组动作，只能执行一次

Action Bucket:
group中的一组动作。group会执行其中的一个或者多个bucket来处理报文。

Action Set:
与数据包关联的一组动作，这些动作在每个表处理数据包时累积，并在指令集终止管道处理时按指定顺序执行

Byte:
8bit位

Connection:
一个使用网络传输协议实现的网络连接，用以在交换机和控制器之间传递OpenFLow消息。一个OpenFlow管道有一个主链接，和可选的一些辅助连接

Control Channel:
管理与控制器通信的OpenFlow逻辑交换机的组件的集合。 每个OpenFlow控制器的控制通道包括一个OpenFlow通道。

Controller:
参见OpenFlow控制器

Counter:
计数器是OpenFlow统计信息的主要元素，并且在管道的各个特定点（例如在端口或流条目上）进行累加。计数器通常对通过OpenFlow元素的数据包和字节数进行计数，但是还定义了其他计数器类型。

Datapath:
直接涉及流量处理和转发的OpenFlow逻辑交换机组件的聚合。 datapath包括流表，组表和端口的管道。

Flow Entry:
流表中用于匹配和处理数据包的元素。 它包含一组用于匹配数据包的匹配字段，一个用于匹配优先级的优先级，一组用于跟踪数据包的计数器以及一组适用的指令

Flow Table:
pipeline处理过程中的一个阶段，包含了 flow entry

Forwarding:
决定报文的一个或多个出接口，并且传输到这些口

Group:
action bucket 列表，且从每个数据包中选择一个或多个桶进行应用的方法，称为一个Group

Header:
交换机内嵌的数据包中的控制信息，用于标识该数据包并通知交换机如何处理和转发该数据包。 标头通常包括各种标头字段，以标识数据包的源和目的地，以及如何解释其他标头和有效负载。

Header Field:
数据包标头中的值。 解析包头以提取其头字段，该头字段与对应的匹配字段进行匹配。

Hybrid:
集成了OpenFlow操作和常规以太网交换操作

Instruction:
指令附在流条目上，描述了数据包与流条目匹配时发生的OpenFlow处理。一条指令要么修改流水线处理，例如将数据包定向到另一个流表，要么包含一组要添加到操作集中的动作，或者包含要立即应用于数据包的一系列动作

Instruction Set:
附于流表中流条目的一组指令

Match Field:
数据包与之匹配的流条目的一部分。匹配字段可以匹配各种数据包头字段，数据包入口端口，元数据值和其他管道字段。匹配字段可以是通配符（匹配任何值），在某些情况下可以是掩码的（匹配位的子集）。

Matching:
将数据包的标头字段和管道字段的集合与流条目的匹配字段进行比较

Metadata:
掩码寄存器(就是一个掩码..)，用于将信息从一个表传送到下一个表。

Message:
通过OpenFlow连接发送的OpenFlow协议单元。 可能是一个请求，一个回复，控制消息或状态事件。

Meter(限速器):
可以测量和控制数据包速率的交换元件。 如果通过meter的数据包速率或字节速率超过预定义的阈值，meter将触发限速。 如果meter丢弃数据包，则称为速率限制器(Rate Limiter)。

OpenFlow Channel:
控制器和交换机之间的接口，用于传递消息

OpenFlow Controller
一个实体，使用Openflow交换机协议控制OpenFlow交换机。大多情况下，一个控制器可以控制多个交换机

OpenFlow Logical Switch:
交换机

OpenFlow Protocol:
协议

OpenFlow Switch:
交换机

Packet:
报文

Pipeline:
流水线

Pipeline fields:
在流水线处理期间附加到数据包的一组值，区别于报文本身的字段。 包括入口，元数据值，Tunnel-ID值和其他

Port:
端口，物理口，逻辑口或者保留口

Queue:
根据输出端口上的优先级调度数据包，以提供服务质量（QoS）。

Switch:
交换机

Tag:
可以通过push和pop操作插入或从数据包中删除的标签

Outermost Tag:
最外层标签


# OpenFlow Ports
本节描述了OpenFlow端口抽象以及OpenFlow支持的各种类型的OpenFlow端口。
## Openflow Ports


# OpenFlow Tables

# OpenFlow Channel and Control Channel

# The OpenFlow Switch Protocol

# Header file openflow.h

# Release Notes
