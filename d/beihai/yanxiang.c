// /d/beihai/yanxiang.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ų�Ϊһ��̨��Բ�Σ�̨�����壬�ܳ���ʮ���ɡ���֮��Ҵ���ţ�
��Ի�Ѿ�����Ի���飬�����еŵ�����������ųǵ������š��ſ��м�
������ɨ�ء�
LONG
	);
	set("exits", ([
		"west" : __DIR__"ximen",
		"east" : __DIR__"chengguang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
