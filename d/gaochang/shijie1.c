// Room: /d/gaochang/shijie1.c
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
		"west" : __DIR__"kongdi",
		"northup" : __DIR__"shijie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}