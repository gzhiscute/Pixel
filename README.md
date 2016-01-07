Pixel
=====
###This repository is our Compiling Practice course project.

* backend: contains lexer and parser, and a server
* www: contains the frontend website

You can use our Pixel language interpreter by running the server and open the website at the same time.

Good luck!


### 使用方法
* 下载backend中的server_static.exe 和整个前端www文件夹
* 点击运行server_static.exe
* 打开www文件夹中的index.html
* 示例代码在example.pixel文件中
* 下面也列举了一些示例代码，粘贴到网页编辑器中就能画图了~



### Pixel示例代码

##### call function - 函数调用
```c
c = circle(100, 100, 40, red)
red = color(255, 0, 0)

haha = func(int xx, int yy, int rr) {
    blue = color(0, 0, 255)
    c.x = xx
    c.y = yy
    c.r = rr
    
    if (xx == 200){
        c.color = red
    }
    else{
        c.color = blue
    }
    draw c
    
    foo = func(int aa, int bb) {
        cir = rect(300,100,50, 50, blue)
        cir.x = aa
        cir.y = bb
        draw cir
    }
    foo(150, 200)
}
haha(200, 100, 50)
e = 20
haha(70, 100, e)
```
==============
##### a beautiful curve - 好看的曲线
```c
blue = color(200,200,200)
while (b.x < 400) {
   blue.R = b.y
   blue.G = b.x
   b.x = b.x + 3
   b.y = b.x * b.x / 100
   draw b
}
```

================
##### rect and circle matrix - 展示多重循环
```c
a = rect(50, 50, 20, 20, red)
red = color(255, 0, 0)

dd = 30
while (a.x < 400) {
   a.y = 50
   red.R = a.x
   red.G = a.x / 255
   while (a.y < 300) {
       draw a
       a.y = a.y + dd
   }
   a.x = a.x + dd
}

b = circle(65, 75, 4, blue)
blue = color(200,200,200)
b.r = 5
while (b.x < 395) {
   b.y = 66
   blue.B = b.x / 255
   blue.G = b.x
   while (b.y < 295) {
       draw b
       b.y = b.y + dd
       b.color = blue
   }
   b.x = b.x + dd
}
```

====================
##### a large binary tree - 大型二叉树
```c
c = tree(0,(0,1,2)(1,3,4)(3,5,6)(6,7,8)(8,9,10)
    (4,11,12)(11,13,14)(2,15,16)(15,17,18)
    (18,19,20))
draw c
```

==========================
##### so many stars~ －画复杂的多边形
```c
star = func (int xx, int yy) {
    hehe = polygon(100,100,color(240, 0,0),(100,10)(10,78)(40,198)(160,198)(190,78))
    hehe.x = xx
    hehe.y = yy
    draw hehe   
    haha = polygon(100,100,color(122,233,233),(100,10)(40,198)(190,78)(10,78)(160,198))
    haha.x = xx
    haha.y = yy
    draw haha
    cyc = circle(200,210,40, color(230,255,0))
    cyc.x = xx + 100
    cyc.y = yy + 110
    draw cyc
}

star(120,10)
star(300,10)
star(120,200)
star(300,200)
```

====================
#### cute baymax!! our logo － 可以直接画出我们组的图标
```c
a = circle(0, 0, 20, red)
red = color(255, 0, 100)

x = 150
y = 150
r = 100

while (a.x < 400) {
    
    a.y = 0
    while (a.y < 400) {
        if ((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y) == r*r) {
            draw a
        }
        else {}
        a.y = a.y + 1
    }
    a.x = a.x + 1
}

b = circle(100, 150, 20, color(0,0,0))
draw b

b.x = 200
draw b

draw line(100,150,200,150,color(0,0,0))
```

