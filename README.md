Pixel
=====
###This repository is our Compiling Practice course project.

* backend: contains lexer and parser, and a server
* www: contains the frontend website

You can use our Pixel language interpreter by running the server and open the website at the same time.

Good luck!

### TODO List:
* 添加源代码说明文档readme.txt
* 写示例程序->做demo...?
* 写Pixel语言使用手册

* 后端要做的事：
  * 完善循环、分支、函数实现
  * 后端进行错误检查，输出错误提示信息
  * 完善细节部分语法设计
  * 二叉树输出微调，添加节点文字，调整树的位置
  * 支持画布上输出文字（待定）


* 前端要做的事：
  * 画布大小可拖动改变
  * 传入画布长宽
  * 错误信息文字提示框，输出错误信息用
  * 支持语法高亮，关键字参考下文...
  * 其它界面美化

* 服务器端要做的事：
  * 支持多用户同时访问（待定）
  * 前后端交互微调，解析输入的画布长宽，输出区分报错与svg代码（和前端商量）

#### 语法参考
##### 关键字：
* 常量：
  TRUE, FALSE, 数字
* 类型名：
  point, line, circle, rect, color, tree
* 类型内部变量名：
  x, y, x1, y1, r
* 其它：
  draw, while, if, else, break, continue, func
