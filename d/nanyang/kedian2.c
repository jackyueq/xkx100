// Room: /d/nanyang/kedian2.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ������
�ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���
������ŵ����˹�ȥ��
LONG );
	set("sleep_room",1);
	set("exits", ([
		"down" : __DIR__"kedian1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 500);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{

	if (dir == "down" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
