// /d/yixing/clhuayuan.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����԰�ǵ��͵Ľ��Ϸ�񣬾���ϸ�¡�԰�л�����û��ʲô����
Ʒ�֣�Ҳ�����涷��������һ��ʯ���̾͵�С·������鲼��̦������
ʪ��������һ������
LONG );

	set("exits", ([
		"west"  : __DIR__"clzoulang2",
		"east"  : __DIR__"clyongdao",
		"south" : __DIR__"clbajiaoting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();
	replace_program(ROOM);
}

