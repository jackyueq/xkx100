// Room: /d/heimuya/linjxd1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ּ�С��");
	set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵
�����ң�����ɳɳ�����������㲻���������������ߺ�����һ��ɽ�ȡ� 
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"south" : __DIR__"linjxd2",
		"north" : __DIR__"linjxd5",     
		"east"  : __DIR__"road1",
		"west"  : __DIR__"guang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}