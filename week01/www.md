# 环境配置总结

Copyright (C) 2022, HITCRT_VISION, all rights reserved.  
Author:pwm(2021112834.stu.hit.edu.cn)  
Time:2022-07-16

## 配置过程及问题解决办法

1. Ubuntu 20.04 双系统全程按照教程里的操作，非常顺利。

2. 安装git、build-essential\eigen、pcl库也按照教程来的，没什么问题。

3. cmake安装  

   + 安装依赖  sudo apt-get install openssl libssl-dev
   + 点击cmake安装包将其打开，并进行解压  
   + 进入解压后的文件，在文件夹中打开终端，输入 sudo ./bootstrap && sudo make -j16 && sudo make install  
   + 安装成功后在终端输入 cmake --version 检查版本
  
4. opencv安装  

我先是按照教程的来进行安装，但在安装依赖时就报错了。虽然学长们说了教程在这里有问题，但有学长指出我加错源了。  

### 换源

  打开 /etc/apt/sources.list/ 在 other software 中把打勾的那一条去掉。
  
  同时把镜像源换成了hit哈工大源，这样下载速度会快很多。  

### 按官网安装

  我按照速通教程进入了 opencv 官网，然后按照官网给的安装过程一步一步地进行安装，但所有都安装完之后，我在终端输入pkg-config --modversion opencv进行验证时，显示找不到opencv安装包。然后尝试了csdn上的方法进行配置环境，但依然无用。后来我试着运行了opencv的例程，依然显示没成功。

  于是，我就只好将其卸载。

### 卸载opencv  

在终端输入

```bash
sudo make uninstall
cd build            #或直接在opencv的build文件夹右键打开终端
sudo rm -r build
sudo rm -r /usr/local/include/opencv2 /usr/local/include/opencv /usr/include/opencv /usr/include/opencv2 /usr/local/share/opencv /usr/local/share/OpenCV /usr/share/opencv /usr/share/OpenCV /usr/local/bin/opencv* /usr/local/lib/libopencv
```

如果这样还没有卸载干净，就可以在终端输入  sudo apt purge libopencv-dev ,然后仔细检查有没有把系统内核也带上了，如果没有就点击yes。卸载干净后我就用了apt来安装，在终端输入  

```bash
sudo apt install libopencv-dev 
```

安装完成后，试运行opencv例程来检验。
