// Room: /d/wuyi/path10.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
�������η��ɽ��һ��С·��·���ǵ���ʯ���̾͵ģ����߶�����
�ܲ����ɰء����Ͼ������η��ˣ�����ֱָ��Դ����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"  : __DIR__"tianyoufeng",
		"westdown" : __DIR__"taoyuandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -4970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

