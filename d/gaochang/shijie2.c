// Room: /d/gaochang/shijie2.c
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
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}