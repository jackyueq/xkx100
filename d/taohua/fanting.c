// Room: /d/taohua/fanting.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǻ�ҩʦһ���˳Է��ĵط�������������Ŵ�Բ������Χ�����
�������Ρ����ڻ����ż���ˮ�ɻ���������һ�±��ӣ������������㣡
Ҳ��֪�����ǻ��㻹�Ƿ��㡣
LONG
	);
	set("exits", ([
		"east"  : __DIR__"neishi1",
		"north" : __DIR__"chufang",
	]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
	]));

	set("coor/x", 8990);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}