// tongtiandian.c ͨ���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ͨ���");
        set("long", @LONG
�����ǹ�������֮ĩ--ͨ������Ĵ����ڵ����̲�����ʢ��
��ͨ������Ľ����Աߣ����ż�λ�ؽ̵����󳤶��ɡ������ɡ���
����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"laojundian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2770);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}