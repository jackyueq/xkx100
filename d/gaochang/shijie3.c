// Room: /d/gaochang/shijie3.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ǰ��Ȼ����һ��Ƭ���֡����ֳ��ü��ܣ�ʯ���������˺�����
�Ƶ����롣���ڽ��£���������������һֻС����֨������ǰ������
��ʧ���ֺ��
LONG
	);

	set("outdoors", "gaochang");
	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"northup" : __DIR__"entrance",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}