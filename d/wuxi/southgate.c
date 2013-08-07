// Room: /d/wuxi/southgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "������");
	set("long", @LONG
�����ϳ��ţ����ŵ������Ǵӹź�֮ʱ�ʹ������ˡ���ǽ�������
���ţ�����ס�˲���С��С������Χ�����˻������̸��и�ҵ�Ĺ�棬
�ٸ��ĸ�ʾ(gaoshi)�����м䵹Ҳ��̫��Ŀ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north"  : __DIR__"southroad2",
		"south"  : __DIR__"qingmingqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -840);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}