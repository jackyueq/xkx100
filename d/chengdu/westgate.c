// Room: westgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "������");
	set("long", @LONG
���������������⣬ֻ���ߴ�ĳ�ǽ��ʵ���أ�������ϸ���̲���
�������ˣ�һ�ж��Եþ�����������ǽ�����ż��Ÿ�ʾ(gaoshi)������
ԶԶ���Կ����������Ϫ��ˮ�������ǳ��
LONG );
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"nanheqiaow",
		"east"  : __DIR__"xijie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8090);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}
