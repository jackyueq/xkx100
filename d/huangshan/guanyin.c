// Room: /d/huangshan/guanyin.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�ɰ�ɽ�������������ŵ��춼���£�����һ��ͤͤ������ʯ�ˣ���
��һ���װ��Ů���˳ƹ���ʯ������һ��Сʯ��ǡ����֮ͯ�ӣ��⡰
С��٪�����á���������ʯ�����ù��ɡ�ͯ�Ӱݹ�������������㿪
ʼ�ˡ��̿�ǧ���������ϵ��ݡ������춼��ؿ�����͡��ĵǶ���
�̡�
LONG
	);
	set("exits", ([ 
		"southdown"  : __DIR__"banshan",
		"northup"    : __DIR__"yingke",
		"east"       : __DIR__"jiyu",
	]));
	set("objects", ([
		__DIR__"obj/guanyin" : 1,
		__DIR__"obj/xiaotong" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
