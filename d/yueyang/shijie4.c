// Room: /d/yueyang/shijie4.c
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
		"eastdown" : __DIR__"shijie3",
		"westup"   : __DIR__"shijie5",
	]));
	set("coor/x", -1760);
	set("coor/y", 2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
