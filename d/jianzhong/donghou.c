#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
��������з羰�������ţ���ľ�Դ䣬ɽ����ѣ����Ų���
ȥ���;�ɫ����֪�������߽����������
LONG
	);
	set("exits",([
		"north":__DIR__"donghou1",
		"south":__DIR__"dongkou",
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -430);
	set("coor/z", 0);
	setup();
}