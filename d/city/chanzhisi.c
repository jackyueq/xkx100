// Room: /city/chanzhisi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������������һ�������������ʢ���ֵõ��عٸ�Ȩ����
�ͣ������޵����Ʋ������ſڵ���¥�Ե�ʮ�ֵظߴ�������̽�����
һ����ϴ�����߻�ǽ��Φ��Ҳ���ó����������ɡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"chanzhidadian",
		"south"  : __DIR__"chanzhimenqian",
	]));
	set("objects", ([
		__DIR__"npc/kanmenseng": 1,
	]));
	set("coor/x", -20);
	set("coor/y", -9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}