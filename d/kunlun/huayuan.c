// Room: /d/kunlun/huayuan.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����������ɵĺ�԰��԰���з��أ�Ե��������ɽ���ȱ߻�ľ��
�裬��Ӱ�βɽȪ���ģ���Ȼ���н���԰�ֵ���Ȥ�������������ɵ�
���š�
LONG );
	set("exits", ([
		"west"      :__DIR__"cemen",
		"east"      : __DIR__"huapu",
		"south"     : __DIR__"houting",
		"north"     : __DIR__"shanlin1",
		"southeast" : __DIR__"jiashan",
		"southwest" : __DIR__"liangting",
	]));

	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119990);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}