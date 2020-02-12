# 安装
```
https://computingforgeeks.com/how-to-install-and-configure-gitlab-on-centos-rhel/

1.
sudo yum -y update
sudo yum -y install curl vim policycoreutils python3-policycoreutils

2.
sudo vi /etc/yum.repos.d/gitlab-ce.repo

[gitlab-ce]
name=gitlab-ce
baseurl=https://packages.gitlab.com/gitlab/gitlab-ce/el/7/$basearch
repo_gpgcheck=1
gpgcheck=1
enabled=1
gpgkey=https://packages.gitlab.com/gitlab/gitlab-ce/gpgkey
       https://packages.gitlab.com/gitlab/gitlab-ce/gpgkey/gitlab-gitlab-ce-3D645A26AB9FBD22.pub.gpg
metadata_expire=300

3.
sudo yum makecache
sudo yum install -y gitlab-ce --nobest

4.
sudo vi /etc/gitlab/gitlab.rb
external_url 'http://gitlab.example.com'
sudo gitlab-ctl reconfigure

sudo firewall-cmd --permanent --add-service={ssh,http,https} --permanent
sudo firewall-cmd --reload

5.
http://gitlab.example.com
```