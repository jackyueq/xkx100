// Room: /yangzhou/tianningxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
������һ��Ƨ����С����������޼����Ӵ������ǲ��½ֿڣ���
���������£�С������߹���һ����ľ�ң����顰������֡��ĸ����֣�
���������ڵط�����ƫƧ�������������������顣
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"northwest"  : __DIR__"tianningshuju",
		"northeast"  : __DIR__"yuelaoci",
		"south"      : __DIR__"caiyijiekou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}