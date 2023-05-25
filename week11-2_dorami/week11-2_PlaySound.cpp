#include <windows.h>
#include <stdio.h>
int main()
{
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav",NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav",NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav",NULL, SND_SYNC);

    ///目錄的斜線可以用 兩個反斜線
    PlaySound("do-re-mi/do.wav", NULL, SND_SYNC);
    ///相對路徑
    printf("Hello World\n");
}
