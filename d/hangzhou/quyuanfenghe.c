// quyuanfenghe.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
�߽�ͤԺ��ֻ���ٺ�һ��С鿡�������һ����(duilian)�� ���
�ۺ���ֻ���ɻ����������������Զ���塣������������ӽ���Ͼ�
���������У���ⲻ����ʱͬ��������Ҷ����̣�ӳ�պɻ������족��
LONG);
        set("exits", ([
            "out"    : __DIR__"quyuanbei",
        ]));
        set("item_desc", ([
            "duilian" :
"\n
        ��              ��
        ��              ��
        ��              С
        ��              ��
        ˮ              ��
        Ӱ              ��
        ��              ��\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4060);
	set("coor/y", -1460);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
