// Room: /d/huangshan/banshan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
��ɽ�վ�����ȥ�������̣����������߶�Ϊ���ҿ��޵�ɮ�ˣ�����
��ɽ֮���������ࡣ��ɽ�¾���Ϊ����һλ�ó�ɽˮ�Ĵ󻭼ҡ�ѩׯ��
�С�������������֮�ס����������������漣�������ɰ�ɽ��������ɽ
������ʯ������������ȥ�춼�塣
LONG
	);
	set("exits", ([ 
		"northup"   : __DIR__"guanyin",
		"westdown"  : __DIR__"zuishi",
		"southdown" : __DIR__"qingluan",
	]));
	set("outdoors", "huangshan");
	replace_program(ROOM);
	setup();
	replace_program(ROOM);
}
