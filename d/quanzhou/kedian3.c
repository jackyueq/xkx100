// Room: /d/quanzhou/kedian3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�͵�ͷ�");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ������
�ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���
������ŵ����˹�ȥ��
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	set("coor/x", 1860);
	set("coor/y", -6520);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
