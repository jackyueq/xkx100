// Room: /d/yueyang/xiaolu9.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����ͨ������ɽ�Ͼ���ͤ�Ļ���С����С�����߲������࣬������
�ˣ����Ǹ��������ڡ���ɽ�£���ͥ��ˮ��ӵ��ɽ�����һƬ����ɫ��
�����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"yangeng1",
		"eastup"   : __DIR__"jiuxiangting",
	]));
	set("coor/x", -1790);
	set("coor/y", 2280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
