// cundaota2.c ���������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
�����Ǵ�����Ķ��㣬���������������������졣����տ���
Ҳ������Ҳ��ȫ��ȫ������ǽ�ȥ�Ķ��ˡ�
LONG
        );
        set("exits", ([
                "eastup" : __DIR__"cundaota3",
                "eastdown" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}