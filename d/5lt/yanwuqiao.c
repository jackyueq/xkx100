// Room: /d/5lt/yanwuqiao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�����µ�С�ţ������ϵ������໨�ݶ��������������
����װ�˺ü�յ�۹�ƣ����ϵ���������ʱ�򣬼�ֱ����ˮ�������š�
LONG);
	set("exits", ([
		"south"   : __DIR__"sroad2",
		"north"   : __DIR__"sroad1",
	]));
	set("outdoors", "5lt");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
