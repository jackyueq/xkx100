// Room: zhengtang.c
#include <ansi.h>
inherit ROOM;
void bt_same(object who,object me);

void create()
{
	set("short", "ǩѺ��");
	set("long", @LONG
���������ݸ���ǩѺ����ƽ����ͷ�����Ƕ�������Ⱥ�̴��˵Ĵ�
�С����ŵı�����Ǵ����ˣ�����˴��������ǰ���������������ϳ�
�������������ʰ���
LONG
	);
	set("exits", ([
		"west" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"task3/shiye": 1,
	]));
	set("coor/x", -19);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
