// guangning.c ������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ������֮���´�ͨ�����ң����Һ�С������һ��С����
һ��С�輸����û��ʲô��İ��衣�輸��Ө͸������ϸһ����ԭ��
�����������������ĥ�ɵġ��輸�ϰڷ��ż�������������飬����
һЩ�����õĽ�Ǯ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"piandian",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/hao" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}