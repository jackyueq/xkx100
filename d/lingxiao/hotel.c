// Room: /d/lingxiao/hotel.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ѩ��");
	set("long", @LONG
�����������������ľ�¥��ѩ����ͬʱҲ�������ǵ�����֮һ��
�󷲹����ÿͣ������Ƿ������䣬��������ī�ͣ�Ǩ��ɧ�ˣ���Ҫ����
һ������л�̿Ͷ��������ǣ��ڴ˿���ʮ��̳�Ҿ�֮��ɱ��������
�ǡ��Ӵˣ������Ǳ�ѩ���Ĵ��������������ĺ���
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31010);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

