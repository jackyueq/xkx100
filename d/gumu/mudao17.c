// mudao17.c Ĺ��
// Java Oct.10 1998

#include <ansi.h>;
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
		"north" : __DIR__"liangong2",
		"south" : __DIR__"zhongting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 20);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
