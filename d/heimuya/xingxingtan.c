// Room: /d/heimuya/xingxingtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "����̲");
	set("long", @LONG
ֻ��һƬ��̲��ɽʯ�����Ѫ��ˮ���ļ������������������̲��
һҶС��������«έ�У�Ҫ�������Ҫ���⼸��С���ˡ�
LONG );
	set("outdoors", "heimuya");
	set("objects", ([
//		CLASS_D("heimuya")+"/first" : 1,
	]));
	set("exits", ([
		"eastup" : __DIR__"shidao2",
		"enter"  : __DIR__"duchuan1",
	]));
	set("coor/x", -3060);
	set("coor/y", 4040);
	set("coor/z", -10);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir != "enter" ) me->set_temp("hmy_ship/xxt", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}
