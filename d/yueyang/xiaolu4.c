// Room: /d/yueyang/xiaolu4.c
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
		"southup" : __DIR__"shanliang",
		"west"    : __DIR__"xiaolu5",
	]));
	set("coor/x", -1670);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
