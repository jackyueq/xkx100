// Room: /d/wuyi/pinziyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "Ʒ����");
	set("long", @LONG
Ʒ�����ڰ���֮�����Թ�����ɽ��������ͬɽ�ĵ䷶���塢�͡���
�����ų⣬���ݲ���������٣������漣����ˣ��˷�Ҳ�����̷塣
���ڽǶȲ�ͬ���˷����������˱ʼܣ��������ʼܷ塣
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1320);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

