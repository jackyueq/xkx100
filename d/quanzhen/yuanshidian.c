// yuanshidian.c Ԫʼ��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ԫʼ��");
        set("long", @LONG
�����ǹ���Ԫʼ����Ĵ������������ƣ�����������Ԫʼ��
��Ľ����Ա߻����ż�λ������̫�ҡ�����������ӡ�����ӵ�
�ȵ���������һ�����ɻ����������衣
LONG
        );
        set("exits", ([
                "south" : __DIR__"laojundian",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/qi" : 1,
        ] ));

	set("coor/x", -2770);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}