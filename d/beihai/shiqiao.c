// /d/beihai/shiqiao.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ֻ��һ��Сʯ�ţ������������ú���������Ȼ����ȴ�ǳ���
���������ϵ������໨�ݶ������������
LONG
	);
	set("exits", ([
		"southup"   : __DIR__"zhizhu",
		"northwest" : __DIR__"yilan",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
