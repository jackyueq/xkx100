// Room: /d/yueyang/shijie3.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����ͨ������ɽ�Ͼ���ͤ����ʯС����С�����߲������࣬������
�ˣ����Ǹ��������ڡ���ɽ�£���ͥ��ˮ��ӵ��ɽ�����һƬ����ɫ��
�����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shejiaotai",
		"westup"   : __DIR__"shijie4",
	]));
	set("coor/x", -1750);
	set("coor/y", 2280);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
