// Room: /d/huijiang/xiaoxi1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "СϪ��");
	set("long", @LONG
�ڲ�̽������ʯ֮�����ʵ�һ��СϪ�����峺�ĺӵ��ǹ⻬�Ķ�
��ʯ��Ϫ�����ߵ���ľ��ʼ����������Ϫˮת���ƹ�һ��ߵأ���Ȼ��
ǰһƬ���٣�ˮ����䲻����ƥ������������������齦�񣬶ٳ���ۡ�
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"xiaoxi",
		"westup"    : __DIR__"xiaoxi2",
	]));
	set("objects", ([ /* sizeof() == 1 */
	]));
	set("coor/x", -50020);
	set("coor/y", 9010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
