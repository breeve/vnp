# 配置关系
A -> B : A依赖B
A ∈  B : A属于B
A != B : A无关B

# 支持字段

| 关键字     | 类型   | 说明                                                         |
| ---------- | ------ | ------------------------------------------------------------ |
| package    | string | 声明schema文件所属模块                                       |
| author     | string | 声明schema作者                                               |
| includes   | array  | 声明schema所引用的外部文件                                   |
| propreties | object | 声明schema的字段                                             |
| type       | string | 声明schema字段或者配置的类型<br />取值: object, string, array, enum |
| class      | string | 声明schema类型<br />取值:config, api, service                |
| items      | object | 辅助字段，当type为array的时候，items字段，声明其类型。<br />可以是内置类型，可以是自定义类型，也可以通过花括号，来声明直接定义。 |
| brief      | string | 声明schema字段的描述                                         |
| enum_value | array  | 声明枚举类型字段的取值                                       |
|            |        |                                                              |





# 例子

``` json

{
    "package"  : "vrouter",
    "author"   : "breeve",
    "includes" : [
        "../common/basic.json"
    ],
    "class" : "config",
    "type" : "object",
    "propreties" : {
        "name" : {
            "type"   : "string",
            "length" : 64,
            "format" : ""
        },
        "description" : {
            "type"   : "string",
            "length" : 64
        },
        "port" : {
            "type" : "array",
            "items" : "virtual_port"
        },
        "ipv4_group" : {
            "type" : "array",
            "items" : {
                "type" : "array",
                "items" : "ipv4_addr"
            }
        },
        "ipv6_group" : {
            "type" : "array",
            "items" : {
                "type" : "object",
                "propreties" : {
                    
                }
            }
        },
        "forward_mode" : {
            "type" : "enum",
            "enum_value" : [
                {
                    "value" : "custom",
                    "brief" : ""
                },
                {
                    "value" : "fast",
                    "brief" : ""
                }
            ]
        }
    }
}

```
