// xiuxishi.c ��Ϣ��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�����ֻ��
�м�һ��С������ǽ����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ��
����������ģ����ž�������˯����
LONG	);
	set("exits", ([
		"east" : __DIR__"mudao02",
	]));
	set("sleep_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
