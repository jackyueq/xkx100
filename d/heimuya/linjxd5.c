// Room: /d/heimuya/linjxd5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ּ�С��");
	set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵
�����ң�����ɳɳ�����������㲻����������Ȼ�㷢����������������
â��һ����û����
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"southup" : __DIR__"dating1",
		"north" : __DIR__"linjxd4",     
		"east"  : __DIR__"linjxd3",
		"west"  : __DIR__"linjxd5",
	]));
	set("objects",([
		__DIR__"npc/wolf" : 4 ,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}