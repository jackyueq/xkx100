// Room: /d/wuxi/eastgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "������");
	set("long", @LONG
���������Ķ����ţ��������Ϸ����š������š�����������֣���
ǽ�����ż��Źٸ���ʾ(gaoshi)�����Ǻ�ˮһ�̲�ͣ�����ţ����˵���
����һ����ֱ�Ĵ���򶫷����죬����ȥ���ݵ������������ʹ�Ŀ���
���۶����������ǳ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : __DIR__"xinlin1",
		"east"  : __DIR__"road1",
		"west"  : __DIR__"eastroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 400);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}