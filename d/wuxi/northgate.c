// Room: /d/wuxi/northgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "������");
	set("long", @LONG
�����Ž������ţ��Ӵ���ȥ�Ǿͽ����ĳ���Ҫ�����ٸ�Ϊ�˽���
��һֱ�޵��˽��ߡ���Ϊ��Ҫ�����Ľ����Ͻ�ֹͨ�������Դ��������
����ͨ�����٣����ϱ��������ֵľ�����������Եķ����ǽ����һ
�Ű�ֽ���ֵĹٸ���ʾ(gaoshi)��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south"  : __DIR__"northroad2",
		"north"  : __DIR__"lianrongqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -760);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}