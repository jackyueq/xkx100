// /d/beihai/haopu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�姼�");
	set("long", @LONG
����֮�姽���Ϊ����ˮ鿡����ڻ���ի�������е��������ɽʯ
���ơ������ɽʯ����һ����ˮ�������г��������š������仯�����
֮�ڣ��ľ���Ȼ֮Ȥ��
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
