// Room: /yangzhou/rongxiyuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "��ϥ԰");
	set("long", @LONG
��԰֮�����磬��ɽʯһ�飬ֲ��ľ������԰֮���࣬��ǽ����
�ȣ����ͤ��������԰֮���ϣ����԰�֣����իһ�䡣ի֮�ϣ�����
϶�أ���ҲС����ء�����԰�أ�����Լ��ʮ�������ʮ��������
�ƣ�ȫ԰�������ȫ���۵ס�����������һ�䡣
LONG );

	set("outdoors", "yangzhouw");
	set("exits", ([
		"south" : __DIR__"hejiajie",
		"north" : __DIR__"tangwu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}