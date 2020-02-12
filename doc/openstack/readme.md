# instrucation
```
version: Train

OpenStack是IaaS(Infrastructure-as-a-Service)。
主要组件
1. neutron-server
2. OpenStack Networking plug-ins and agents
3. Messaging queue

概念
VNI: virtual networking infrastructure
PNI: physical networking infrastructure
VPN: virtual private network
SDN: software define network
Security Group:
FWaaS: Firewall-as-a-Service
network:
subnet:
switch:
router:
ARP:
DHCP:
```

# basic networking
```
1. Ethernet
Ethernet: IEEE 802.3
MAC address: Media Access Control address
promiscuous mode:
FIB: forwarding information base

2. VLANs
range: 1-4095
trunk port:A switchport that is configured to pass frames from all VLANs and tag them with the VLAN IDs is called a trunk port.
access port:When a switchport is configured for a specific VLAN, it is called an access port

3. Subnets and ARP
IP address: IP addresses are broken up into two parts: a network number and a host identifier.

dotted quad: 点分十进制
classless inter-domain routing: CIDR, 无类地址划分

4. DHCP
Dynamic Host Configuration Protocol

dnsmasq

5. IP
Internet Protocol

6. TCP
Transmission Control Protocol
port range: 1-65535

7. UDP
User Datagram Protocol

8. ICMP
Intenet Control Protocol

9. DNS
Domain Name System

10. NTP
Network Time Protocol

11. VXLAN
Virtual extensible local area network

```

# Network Components
```
1. Switches
Switches are Multi-input Multi-out(MIMO) devices that enable packets to travel from one node to another.

2. Routers
Routers are special devices that enable packets to travel from one layer-3 network to another.

3. Firewalls
Firewalls are used to regulate traffic to and from a host or a network.

4. Load balancers
Load balancers can be software-based or hadrware-based devices that allow traffic to evently be distributed across servers.
```
# Overlay (tunnel) protocols
```
1. Generic routing encapsulation (GRE)

2. Virtual extensible local area network (VXLAN)

3. Generic Network Virtualization Encapsulation (GENEVE)

```
# Network namespaces
```
1. Linux network namespace

2. Virtual routing and forwarding (VRF)

```

# Network address translation
```
Network address translation is a process for modifying the source or destination address in the headers of an IP packet while the packet is in transit, the sender and receiver applications are aware that eht IP packets are being manipulated.

1. SNAT
Port Address Translation(PAT)

2. DNAT

3. One-to-one NAT
In One-to-one NAT, the NAT router maintains a ono-to-one mapping between private IP address and public IP addresses. OpenStack uses one-to-one NAT to implement floating IP addresses.

```

# OpenStack Networking
```
1. API server

2. OpenStack Networking plug-in and agents

3. Messaging queue

4. Provider networks
供应商网络，也即是管理网络

5. Routed provider networks

6. Self-service networks

7. overlay technology
. FLAT
平面网络，也即是没有隔离

. VLAN

. GRE and VXLAN

8. Subnets

9. Subnet pools
类似dhcp pool

10. Ports

11. Routers

12. Security groups

13. Extensions
. DHCP

. Metadata
The optional metadata service provides an API for instances to obtain metadata such as SSH keys.

```




















