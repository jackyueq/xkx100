// /d/beihai/jingji.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳй��ľ����ã���ʮ��䣬Ե��ǽ�ɻ���֮�ơ��ٴ���
��������һ����������ķ�⡣��������ķ��ż���̴ľ���ӡ��м���
һ�Ű���������Ȼ����������������ȴ��Ȼ����ɨ��һ����Ⱦ��
LONG
	);
	set("exits", ([
		"south" : __DIR__"chengguang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

