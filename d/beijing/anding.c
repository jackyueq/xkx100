// /d/beijing/andingmen.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ţ��������Ϸ����š������š��������֣���ǽ������
���Źٸ���ʾ (gaoshi)�������ٱ��������ԡ�
LONG );
        set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : "/d/changcheng/nroad1",
		"south" : __DIR__"di_anmen",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}
