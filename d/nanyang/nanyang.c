// Room: /d/nanyang/nanyang.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǵ�����������Ĺʾӡ��������䲻����Ϊ�س�Ҫ�壬��
�������Ŀ����ر�࣬����Ҳ�����ȫ����¥����ջ����꣬�����Ӷ�
�ǡ������˿����٣�����������ɫ�ҴҵĽ������ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"dajie1",
		"north" : __DIR__"dajie2",
		"east"  : __DIR__"kedian1",
		"west"  : __DIR__"jiulou1",
	]));
	set("objects",([
		"/d/shaolin/npc/xiao-fan" : 1,
	]));
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
