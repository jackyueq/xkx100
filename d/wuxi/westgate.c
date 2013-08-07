// Room: /d/wuxi/westgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
���ŵ������Ǻ��������Ϫ���йأ������ϪҲ������Ϊ�����ı�
�ƣ����ϰ��ջ���ϰ�߽������š���ǽ�����ż���ͨ����ʾ(gaoshi)��
����������ͨ�򱱷��ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס����
���ʡ������ǿ�Խ��Ϫ�ӿ�Ϫ�ţ�����ġ����εġ���·�ģ���ɫ�Ҵҡ�
�������������ֵĳ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"kuaxiqiao",
		"east"  : __DIR__"westroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 340);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}