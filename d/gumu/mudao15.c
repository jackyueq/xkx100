// mudao15.c Ĺ��
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"Ĺ��"NOR);
	set("long", @LONG
�����ǹ�Ĺ�е�Ĺ���������ܲ�͸�磬����ǽ�ϻ谵�ĵƹ⣬����
��ǿ�ֱ������ǽ�����������ʯ���������ģ��Ӻϵ�������������
�Դ����ҳ�һ˿��϶���ƹ�������ʯ���ϣ���˸�ű����ĵĹ�㡣
LONG	);
	set("exits", ([
		"east" : __DIR__"zhengting",
		"west" : __DIR__"woshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
