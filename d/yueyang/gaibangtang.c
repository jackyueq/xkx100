// Room: /d/yueyang/gaibangtang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ؤ����ھۻ᳡�������Ϻ����������Ų��ٲ����š���Ȼ��
�����ƺ������ң���ʵȴ���ǺϺ���棺��������ְ˾��ǰ��˳��һ
Ŀ��Ȼ��
LONG );
	set("exits", ([
		"south" : __DIR__"gaibangyuan",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/qiao-feng" : 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", -1420);
	set("coor/y", -2240);
	set("coor/z", 0);
	setup();
	"/clone/board/gaibang_b"->foo();
	replace_program(ROOM);
}
