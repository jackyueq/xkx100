// Room: /d/heimuya/changtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "��̲");
	set("long", @LONG
����һƬ��̲����ʱ�����½̽��ڳ˴�������̲ͷ����һ�����½�
�����ģ�����������������̵ĵ��̣����ܽ����������Ĵ�ֻ�ܶ࣬��
�ǲ�û�д���������ͣ����������ͣ����һβ���½̵�С����
LONG );
	set("exits", ([
		"westup" : __DIR__"shandao1",
		"enter"  : __DIR__"duchuan1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/huang" : 1,
		__DIR__"npc/heiyiren" : 2,
	]));
	set("outdoors", "heimuya");
	set("coor/x", -3200);
	set("coor/y", 4200);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" ) me->set_temp("hmy_ship/ct", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}

