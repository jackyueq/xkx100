// Room: /d/nanyang/dajie2.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�������Թű��ǹء���ͨ������ıؾ�֮·�����䲻��ȴ������
�࣬����紾�ӡ�������һ��СС�ĵ��̣���Щ��ˮ����ʳ����������
�ˡ���������һ������
LONG);
	set("exits",([
		"north"     : __DIR__"beimen",
		"south"     : __DIR__"nanyang",
//		"west"      : __DIR__"xiaodian",
		"northeast" : __DIR__"wuhouci",
	]));
	set("objects",([
		__DIR__"npc/man":1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 510);
	set("coor/z", 0);
	setup();
	set("no_clean_up", 0);
}
