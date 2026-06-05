```c
// Determine padding for scanlines
// BMP 格式规定：每一行像素数据（Scanline）占用的字节数必须是4的倍数
// 每行像素末尾字节填充
// 最后的 % 4 是为了处理刚好整除的情况，即如果本来就是4的倍数，计算结果是4，模4后变回0，表示不需要填充
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
```

```c
// sizeof单位字节
// 这行代码假设：文件的大小 = 图片数据的严格结尾。
// 也就是说，它假设文件在最后一个字节之后，没有任何多余的东西。
// 但实际上，很多 BMP 图片（特别是网络下载或经过去除元数据不干净的图片）在文件末尾可能会有：
// 1. 几个多余的 0x00 字节。
// 2. 换行符（如果某个步骤被当成文本文件处理过）。
// 3. 元数据（Metadata）。
// 如果文件末尾多出了哪怕 1 个字节，fseek 就会跳错位置
// fseek(inptr, - (bi.biWidth * sizeof(RGBTRIPLE) + padding) , SEEK_END);
// 从起点算起
long row_size = bi.biwidth * sizeof(RGBTRIPLE) + padding;
fseek(inotr, bf.bfOffBits + ((long)abs(bi.biHeight)) - 1) * row_size, SEEK_SET);
```

biHeight
位图的高度，以像素为单位。如果 biHeight 为正，表示位图是自下而上的 DIB，其原点在左下角。如果 biHeight 为负，表示位图是自上而下的 DIB，其原点在左上角。

BMP 文件格式中，BITMAPINFOHEADER 里的 biHeight 成员决定了图像的扫描行读取顺序：

- biHeight 为正数（+）：
  - 这是标准 BMP 格式。
  - 表示 Bottom-Up（自底向上）。

  即：文件里的第一行像素数据，实际上是图片的最下面一行。

- biHeight 为负数（-）：

  - 表示 Top-Down（自顶向下）。

  即：文件里的第一行像素数据，实际上是图片的最上面一行。
