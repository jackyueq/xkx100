// Room: /d/heimuya/linjxd3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ּ�С��");
	set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵
�����ң�����ɳɳ�����������㲻��������
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"south" : __DIR__"linjxd4",
		"north" : __DIR__"linjxd2",     
		"east"  : __DIR__"linjxd5",
		"west"  : __DIR__"linjxd5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}