// Room: /d/huijiang/zhangpeng3.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ⶥ��ţƤ�������ܾ�û��ɨ�ˣ��ڿ�������Ĳ��֣��кü���
������ҧ����С����һ������Ƥƴ������̺�Ӱ�����������ģ���ڹ�
�ŵĹ����Կ��Űѳ���������˷�����ɫ�����⡣
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huoayi" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"buluo2",
	]));
	set("coor/x", -50060);
	set("coor/y", 9060);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
