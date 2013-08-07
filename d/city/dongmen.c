// Room: /d/city/dongmen.c
// Last Modified by winder on July. 20 2000

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "�㴢��");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š��㴢�š�����������֣���ǽ����
�ż��Źٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��
Ϊ�һ����ֱ����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�
һƬһ���޼ʵ����֣�����Ī�⡣������һƬïʢ�������֡�������һ
��Ƭ�Ĳݵأ������ǳ��
LONG );
	set("outdoors", "yangzhoue");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : "/d/taishan/yidao",
		"west"  : __DIR__"dashidongjie",
		"north" : __DIR__"ml1",
		"south" : __DIR__"jiaowai1",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	set("coor/x", 70);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}