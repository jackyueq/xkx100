// Room: /d/nanyang/dajie1.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������Թű��ǹء���ͨ������ıؾ�֮·�����䲻��ȴ������
�࣬����紾�ӡ�������˺���˻�������������������̡���������һ
���̺š�
LONG);
	set("exits",([
		"north" : __DIR__"nanyang",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"shop",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 490);
	set("coor/z", 0);
	set("outdoors","nanyang");
	setup();
	replace_program(ROOM);
}
