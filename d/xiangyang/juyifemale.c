// Room: /d/xiangyang/juyifemale.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "Ů�ͷ�");
	set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵�������
�����ֻ�����߷��ż�����ʰ����������Ĵ󴲣����ž���
����˯����
LONG );
	set("sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"juyihuayuan",
	]));
	set("coor/x", -529);
	set("coor/y", -503);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}