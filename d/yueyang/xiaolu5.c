// Room: /d/yueyang/xiaolu5.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
�����ھ�ɽ��ɽ��С·�ϡ���ɽ������Բ�Σ��Ը��еͣ�����ʮ��
����ɣ��������㣬���������ġ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"xiaolu4",
		"southwest" : __DIR__"liuyijing",
	]));
	set("coor/x", -1680);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
