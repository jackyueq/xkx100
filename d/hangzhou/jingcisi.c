// jingcisi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£�ԭ����������Ժ���ֽ��˽��¡�������������������ӵ
��Ȼͦ�������ɽ�������ͻص�����ϡ�
LONG);
        set("exits", ([
            "north"   : __DIR__"road16",
            "enter"   : __DIR__"jingci",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 4120);
	set("coor/y", -1510);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}